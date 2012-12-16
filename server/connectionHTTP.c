/*
 *  $Id: connectionHTTP.c,v 1.21 2010/08/03 10:46:41 schmirl Exp $
 */

#include <ctype.h>
#include <time.h>
#include <stdarg.h>
#include <vdr/thread.h>
#include <vdr/recording.h>
 
#include "server/connectionHTTP.h"
#include "server/menuHTTP.h"
#include "server/server.h"
#include "server/setup.h"

cConnectionHTTP::cConnectionHTTP(void): 
		cServerConnection("HTTP"),
		m_Status(hsRequest),
		m_Streamer(NULL),
		m_StreamType((eStreamType)StreamdevServerSetup.HTTPStreamType),
		m_Channel(NULL),
		m_Recording(NULL),
		m_ChannelList(NULL)
{
	Dprintf("constructor hsRequest\n");
	m_Apid[0] = m_Apid[1] = 0;
	m_Dpid[0] = m_Dpid[1] = 0;
}

cConnectionHTTP::~cConnectionHTTP() 
{
	delete m_Streamer;
	delete m_Recording;
}

bool cConnectionHTTP::CanAuthenticate(void)
{
	return opt_auth != NULL;
}

bool cConnectionHTTP::Command(char *Cmd) 
{
	Dprintf("command %s\n", Cmd);
	switch (m_Status) {
	case hsRequest:
		// parse METHOD PATH[?QUERY] VERSION
		{
			char *p, *q, *v;
			p = strchr(Cmd, ' ');
			if (p) {
				*p = 0;
				v = strchr(++p, ' ');
				if (v) {
					*v = 0;
					SetHeader("REQUEST_METHOD", Cmd);
					q = strchr(p, '?');
					if (q) {
						*q = 0;
						SetHeader("QUERY_STRING", q + 1);
						while (q++) {
							char *n = strchr(q, '&');
							if (n)
								*n = 0;
							char *e = strchr(q, '=');
							if (e)
								*e++ = 0;
							else
								e = n ? n : v;
							m_Params.insert(tStrStr(q, e));
							q = n;
						}
					}
					else
						SetHeader("QUERY_STRING", "");
					SetHeader("PATH_INFO", p);
					m_Status = hsHeaders;
					return true;
				}
			}
		}
		return false;

	case hsHeaders:
		if (*Cmd == '\0') {
			m_Status = hsBody;
			return ProcessRequest();
		}
		else if (isspace(*Cmd)) {
			; //TODO: multi-line header
		}
		else {
			// convert header name to CGI conventions:
			// uppercase, '-' replaced with '_', prefix "HTTP_"
			char *p;
			for (p = Cmd; *p != 0 && *p != ':'; p++) {
				if (*p == '-')
					*p = '_';
				else
					*p = toupper(*p);
			}
			if (*p == ':') {
				*p = 0;
				p = skipspace(++p);
				// don't disclose Authorization header
				if (strcmp(Cmd, "AUTHORIZATION") == 0) {
					char *q;
					for (q = p; *q != 0 && *q != ' '; q++)
						*q = toupper(*q);
					if (p != q) {
						*q = 0;
						SetHeader("AUTH_TYPE", p);
						m_Authorization = (std::string) skipspace(++q);
					}
				}
				else
					SetHeader(Cmd, p, "HTTP_");
			}
		}
		return true;
	default:
		// skip additional blank lines
		if (*Cmd == '\0')
			return true;
		break;
	}
	return false; // ??? shouldn't happen
}

bool cConnectionHTTP::ProcessRequest(void) 
{
	// keys for Headers() hash
	const static std::string AUTH_TYPE("AUTH_TYPE");
	const static std::string REQUEST_METHOD("REQUEST_METHOD");
	const static std::string PATH_INFO("PATH_INFO");

	Dprintf("process\n");
	if (!StreamdevHosts.Acceptable(RemoteIpAddr())) {
		bool authOk = opt_auth && !m_Authorization.empty();
		if (authOk) {
			tStrStrMap::const_iterator it = Headers().find(AUTH_TYPE);

			if (it == Headers().end()) {
				// no authorization header present
				authOk = false;
			}
			else if (it->second.compare("BASIC") == 0) {
				// basic auth
				authOk &= m_Authorization.compare(opt_auth) == 0;
			}
			else {
				// unsupported auth type
				authOk = false;
			}
		}
		if (!authOk) {
			isyslog("streamdev-server: HTTP authorization required");
			return HttpResponse(401, true, NULL, "WWW-authenticate: basic Realm=\"Streamdev-Server\"");
		}
	}

	tStrStrMap::const_iterator it_method = Headers().find(REQUEST_METHOD);
	tStrStrMap::const_iterator it_pathinfo = Headers().find(PATH_INFO);
	if (it_method == Headers().end() || it_pathinfo == Headers().end()) {
		// should never happen
		esyslog("streamdev-server connectionHTTP: Missing method or pathinfo");
	} else if (it_method->second.compare("GET") == 0 && ProcessURI(it_pathinfo->second)) {
		if (m_ChannelList)
			return Respond("%s", true, m_ChannelList->HttpHeader().c_str());
		else if (m_Channel != NULL) {
			cDevice *device = NULL;
			if (ProvidesChannel(m_Channel, StreamdevServerSetup.HTTPPriority))
				device = GetDevice(m_Channel, StreamdevServerSetup.HTTPPriority);
			if (device != NULL) {
				device->SwitchChannel(m_Channel, false);
				cStreamdevLiveStreamer* liveStreamer = new cStreamdevLiveStreamer(StreamdevServerSetup.HTTPPriority, this);
				m_Streamer = liveStreamer;
				if (liveStreamer->SetChannel(m_Channel, m_StreamType, m_Apid[0] ? m_Apid : NULL, m_Dpid[0] ? m_Dpid : NULL)) {
					liveStreamer->SetDevice(device);
					if (!SetDSCP())
						LOG_ERROR_STR("unable to set DSCP sockopt");
					if (m_StreamType == stEXT) {
						return Respond("HTTP/1.0 200 OK");
					} else if (m_StreamType == stES && (m_Apid[0] || m_Dpid[0] || ISRADIO(m_Channel))) {
						return HttpResponse(200, false, "audio/mpeg", "icy-name: %s", m_Channel->Name());
					} else if (ISRADIO(m_Channel)) {
						return HttpResponse(200, false, "audio/mpeg");
					} else {
						return HttpResponse(200, false, "video/mpeg");
					}
				}
				DELETENULL(m_Streamer);
			}
			return HttpResponse(503, true);
		}
		else if (m_Recording != NULL) {
			Dprintf("GET recording\n");
			cStreamdevRecStreamer* recStreamer = new cStreamdevRecStreamer(m_Recording, this);
			m_Streamer = recStreamer;
			int64_t from, to;
			uint64_t total = recStreamer->GetLength();
			if (ParseRange(from, to)) {
				int64_t length = recStreamer->SetRange(from, to);
				if (length < 0L)
					return HttpResponse(416, true, "video/mpeg", "Accept-Ranges: bytes\r\nContent-Range: bytes */%llu", (unsigned long long) total);
				else
					return HttpResponse(206, false, "video/mpeg", "Accept-Ranges: bytes\r\nContent-Range: bytes %lld-%lld/%llu\r\nContent-Length: %lld", (long long) from, (long long) to, (unsigned long long) total, (long long) length);
			}
			else
				return HttpResponse(200, false, "video/mpeg", "Accept-Ranges: bytes");
		}
		else {
			return HttpResponse(404, true);
		}
	} else if (it_method->second.compare("HEAD") == 0 && ProcessURI(it_pathinfo->second)) {
		if (m_ChannelList) {
			DeferClose();
			return Respond("%s", true, m_ChannelList->HttpHeader().c_str());
		}
		else if (m_Channel != NULL) {
			if (ProvidesChannel(m_Channel, StreamdevServerSetup.HTTPPriority)) {
				if (m_StreamType == stEXT) {
					cStreamdevLiveStreamer *liveStreamer = new cStreamdevLiveStreamer(StreamdevServerSetup.HTTPPriority, this);
					liveStreamer->SetChannel(m_Channel, m_StreamType, m_Apid[0] ? m_Apid : NULL, m_Dpid[0] ? m_Dpid : NULL);
					m_Streamer = liveStreamer;
					return Respond("HTTP/1.0 200 OK");
				} else if (m_StreamType == stES && (m_Apid[0] || m_Dpid[0] || ISRADIO(m_Channel))) {
					return HttpResponse(200, true, "audio/mpeg", "icy-name: %s", m_Channel->Name());
				} else if (ISRADIO(m_Channel)) {
					return HttpResponse(200, true, "audio/mpeg");
				} else {
					return HttpResponse(200, true, "video/mpeg");
				}
			}
			return HttpResponse(503, true);
		}
		else if (m_Recording != NULL) {
			Dprintf("HEAD recording\n");
			cStreamdevRecStreamer *recStreamer = new cStreamdevRecStreamer(m_Recording, this);
			m_Streamer = recStreamer;
			int64_t from, to;
			uint64_t total = recStreamer->GetLength();
			if (ParseRange(from, to)) {
				int64_t length = recStreamer->SetRange(from, to);
				if (length < 0L)
					return HttpResponse(416, true, "video/mpeg", "Accept-Ranges: bytes\r\nContent-Range: bytes */%llu", (unsigned long long) total);
				else
					return HttpResponse(206, true, "video/mpeg", "Accept-Ranges: bytes\r\nContent-Range: bytes %lld-%lld/%llu\r\nContent-Length: %lld", (long long) from, (long long) to, (unsigned long long) total, (long long) length);
			}
			else
				return HttpResponse(200, true, "video/mpeg", "Accept-Ranges: bytes");
		}
		else {
			return HttpResponse(404, true);
		}
	}

	return HttpResponse(400, true);
}

static const char *AAA[] = {
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};
static const char *MMM[] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

bool cConnectionHTTP::HttpResponse(int Code, bool Last, const char* ContentType, const char* Headers, ...)
{
        va_list ap;
        va_start(ap, Headers);
#if APIVERSNUM >= 10728
        cString headers = cString::vsprintf(Headers, ap);
#else
        cString headers = cString::sprintf(Headers, ap);
#endif
        va_end(ap);

	bool rc;
	if (Last)
		DeferClose();
	switch (Code)
	{
		case 200: rc = Respond("HTTP/1.1 200 OK"); break;
		case 206: rc = Respond("HTTP/1.1 206 Partial Content"); break;
		case 400: rc = Respond("HTTP/1.1 400 Bad Request"); break;
		case 401: rc = Respond("HTTP/1.1 401 Authorization Required"); break;
		case 404: rc = Respond("HTTP/1.1 404 Not Found"); break;
		case 416: rc = Respond("HTTP/1.1 416 Requested range not satisfiable"); break;
		case 503: rc = Respond("HTTP/1.1 503 Service Unavailable"); break;
		default:  rc = Respond("HTTP/1.1 500 Internal Server Error");
	}
	if (rc && ContentType)
		rc = Respond("Content-Type: %s", true, ContentType);
	
	if (rc)
		rc = Respond("Connection: close")
			&& Respond("Pragma: no-cache")
			&& Respond("Cache-Control: no-cache");

	time_t t = time(NULL);
	struct tm *gmt = gmtime(&t);
	if (rc && gmt) {
		char buf[] = "Date: AAA, DD MMM YYYY HH:MM:SS GMT";
		if (snprintf(buf, sizeof(buf), "Date: %s, %.2d %s %.4d %.2d:%.2d:%.2d GMT", AAA[gmt->tm_wday], gmt->tm_mday, MMM[gmt->tm_mon], gmt->tm_year + 1900, gmt->tm_hour, gmt->tm_min, gmt->tm_sec) == sizeof(buf) - 1)
			rc = Respond(buf);
	}

	if (rc && strlen(Headers) > 0)
		rc = Respond(headers);

	tStrStrMap::iterator it = m_Params.begin();
	while (rc && it != m_Params.end()) {
		static const char DLNA_POSTFIX[] = ".dlna.org";
		if (it->first.rfind(DLNA_POSTFIX) + sizeof(DLNA_POSTFIX) - 1 == it->first.length())
			rc = Respond("%s: %s", true, it->first.c_str(), it->second.c_str());
		++it;
	}
	return rc && Respond("");
}

bool cConnectionHTTP::ParseRange(int64_t &From, int64_t &To) const
{
	const static std::string RANGE("HTTP_RANGE");
	From = To = 0L;
	tStrStrMap::const_iterator it = Headers().find(RANGE);
	if (it != Headers().end()) {
		size_t b = it->second.find("bytes=");
		if (b != std::string::npos) {
			char* e = NULL;
			const char* r = it->second.c_str() + b + sizeof("bytes=") - 1;
			if (strchr(r, ',') != NULL)
				esyslog("streamdev-server cConnectionHTTP::GetRange: Multi-ranges not supported");
			From = strtol(r, &e, 10);
			if (r != e) {
				if (From < 0L) {
					To = -1L;
					return *e == 0 || *e == ',';
				}
				else if (*e == '-') {
					r = e + 1;
					if (*r == 0 || *e == ',') {
						To = -1L;
						return true;
					}
					To = strtol(r, &e, 10);
					return r != e && To >= From &&
							(*e == 0 || *e == ',');
				}
			}
		}
	}
	return false;
}

void cConnectionHTTP::Flushed(void) 
{
	if (m_Status != hsBody)
		return;

	if (m_ChannelList) {
		if (m_ChannelList->HasNext()) {
			if (!Respond("%s", true, m_ChannelList->Next().c_str()))
				DeferClose();
		}
		else {
			DELETENULL(m_ChannelList);
			m_Status = hsFinished;
			DeferClose();
		}
		return;
	}
	else if (m_Streamer != NULL) {
		Dprintf("streamer start\n");
		m_Streamer->Start(this);
		m_Status = hsFinished;
	}
	else {
		// should never be reached
		esyslog("streamdev-server cConnectionHTTP::Flushed(): no job to do");
		m_Status = hsFinished;
	}
}

cChannelList* cConnectionHTTP::ChannelListFromString(const std::string& Path, const std::string& Filebase, const std::string& Fileext) const
{
	std::string groupTarget;
	cChannelIterator *iterator = NULL;

	const static std::string GROUP("group");
	if (Filebase.compare("tree") == 0) {
		const cChannel* c = NULL;
		tStrStrMap::const_iterator it = m_Params.find(GROUP);
		if (it != m_Params.end())
			c = cChannelList::GetGroup(atoi(it->second.c_str()));
		iterator = new cListTree(c);
		groupTarget = Filebase + Fileext;
	} else if (Filebase.compare("groups") == 0) {
		iterator = new cListGroups();
		groupTarget = (std::string) "group" + Fileext;
	} else if (Filebase.compare("group") == 0) {
		const cChannel* c = NULL;
		tStrStrMap::const_iterator it = m_Params.find(GROUP);
		if (it != m_Params.end())
			c = cChannelList::GetGroup(atoi(it->second.c_str()));
		iterator = new cListGroup(c);
	} else if (Filebase.compare("channels") == 0) {
		iterator = new cListChannels();
	} else if (Filebase.compare("all") == 0 ||
			(Filebase.empty() && Fileext.empty())) {
		iterator = new cListAll();
	}

	if (iterator) {
		if (Filebase.empty() || Fileext.compare(".htm") == 0 || Fileext.compare(".html") == 0) {
			std::string self = Filebase + Fileext;
			tStrStrMap::const_iterator it = Headers().find("QUERY_STRING");
			if (it != Headers().end() && !it->second.empty())
				self += '?' + it->second;
			return new cHtmlChannelList(iterator, m_StreamType, self.c_str(), groupTarget.c_str());
		} else if (Fileext.compare(".m3u") == 0) {
			std::string base;
			const static std::string HOST("HTTP_HOST");
			tStrStrMap::const_iterator it = Headers().find(HOST);
			if (it != Headers().end())
				base = "http://" + it->second + "/";
			else
				base = (std::string) "http://" + LocalIp() + ":" +
					(const char*) itoa(StreamdevServerSetup.HTTPServerPort) + "/";
			base += Path;
			return new cM3uChannelList(iterator, base.c_str());
		} else {
			delete iterator;
		}
	}
	return NULL;
}

bool cConnectionHTTP::ProcessURI(const std::string& PathInfo) 
{
	std::string filespec, fileext;
	size_t file_pos = PathInfo.rfind('/');

	if (file_pos != std::string::npos) {
		size_t ext_pos = PathInfo.rfind('.');
		// file basename with leading / stripped off
		filespec = PathInfo.substr(file_pos + 1, ext_pos - file_pos - 1);
		if (ext_pos != std::string::npos)
			// file extension including leading .
			fileext = PathInfo.substr(ext_pos);
	}
	if (fileext.length() > 5) {
		//probably not an extension
		filespec += fileext;
		fileext.clear();
	}

	// Streamtype with leading / stripped off
	std::string type = PathInfo.substr(1, PathInfo.find_first_of("/;", 1) - 1);
	const char* pType = type.c_str();
	if (strcasecmp(pType, "PS") == 0) {
		m_StreamType = stPS;
	} else if (strcasecmp(pType, "PES") == 0) {
		m_StreamType = stPES;
	} else if (strcasecmp(pType, "TS") == 0) {
		m_StreamType = stTS;
	} else if (strcasecmp(pType, "ES") == 0) {
		m_StreamType = stES;
	} else if (strcasecmp(pType, "EXT") == 0) {
		m_StreamType = stEXT;
	}

	Dprintf("before channelfromstring: type(%s) filespec(%s) fileext(%s)\n", type.c_str(), filespec.c_str(), fileext.c_str());

	if ((m_ChannelList = ChannelListFromString(PathInfo.substr(1, file_pos), filespec.c_str(), fileext.c_str())) != NULL) {
		Dprintf("Channel list requested\n");
		return true;
	} else if (strcmp(fileext.c_str(), ".rec") == 0) {
		cThreadLock RecordingsLock(&Recordings);
		cRecording* rec = Recordings.Get(atoi(filespec.c_str()) - 1);
		Dprintf("Recording %s%s found\n", rec ? rec->Name() : filespec.c_str(), rec ? "" : " not");
		if (rec)
			m_Recording = new cRecording(rec->FileName());
		return m_Recording != NULL;
	} else if ((m_Channel = ChannelFromString(filespec.c_str(), &m_Apid[0], &m_Dpid[0])) != NULL) {
		Dprintf("Channel found. Apid/Dpid is %d/%d\n", m_Apid[0], m_Dpid[0]);
		return true;
	} else
		return false;
}

cString cConnectionHTTP::ToText() const
{
	cString str = cServerConnection::ToText();
	return m_Streamer ? cString::sprintf("%s\t%s", *str, *m_Streamer->ToText()) : str;
}
