/*
 *  $Id: i18n.c,v 1.8 2008/04/07 14:50:32 schmirl Exp $
 */
 
#include "i18n.h"

const char *i18n_name = NULL;

const tI18nPhrase Phrases[] = {
	{	"VDR Streaming Server",		// English
		"VDR Streaming Server",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"VDR-suoratoistopalvelin",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika / Greek
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"VTP Streaming Client",		// English
		"VTP Streaming Client",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"VTP-suoratoistoasiakas ",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika / Greek
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Start VDR-to-VDR Server",		// English
		"VDR-zu-VDR Server starten",		// Deutsch
		"",		// Slovenski
		"Avvia il Server VDR-toVDR",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"K�ynnist� VDR-palvelin",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika / Greek
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Start HTTP Server",		// English
		"HTTP Server starten",		// Deutsch
		"",		// Slovenski
		"Avvia il Server HTTP",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"K�ynnist� HTTP-palvelin",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"HTTP Streamtype",		// English
		"HTTP Streamtyp",		// Deutsch
		"",		// Slovenski
		"Tipo di Stream HTTP",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"HTTP-l�hetysmuoto",		// Suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Start Client",		// English
		"Client starten",		// Deutsch
		"",		// Slovenski
		"Avvia il Client",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"K�ynnist� VDR-asiakas",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"VDR-to-VDR Server Port",		// English
		"Port des VDR-zu-VDR Servers",		// Deutsch
		"",		// Slovenski
		"Porta del Server VDR-to-VDR",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"VDR-palvelimen portti",		// Suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"HTTP Server Port",		// English
		"Port des HTTP Servers",		// Deutsch
		"",		// Slovenski
		"Porta del Server HTTP",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"HTTP-palvelimen portti",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Maximum Number of Clients",		// English
		"Maximalanzahl an Clients",		// Deutsch
		"",		// Slovenski
		"Numero Massimo di Client",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Suurin sallittu asiakkaiden m��r�",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Remote IP",		// English
		"IP der Gegenseite",		// Deutsch
		"",		// Slovenski
		"Indirizzo IP del Server",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Et�koneen IP-osoite",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Remote Port",		// English
		"Port der Gegenseite",		// Deutsch
		"",		// Slovenski
		"Porta del Server Remoto",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Et�koneen portti",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Remote Streamtype",		// English
		"Streamtyp von Gegenseite",		// Deutsch
		"",		// Slovenski
		"Tipo di Stream",		// Italiano (oppure Flusso ?)
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Et�koneen l�hetysmuoto",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Common Settings",		// English
		"Allgemeines",		// Deutsch
		"",		// Slovenski
		"Settaggi Comuni",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Yleiset asetukset",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"VDR-to-VDR Server",		// English
		"VDR-zu-VDR Server",		// Deutsch
		"",		// Slovenski
		"Server VDR-to-VDR",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"VDR-palvelin",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"HTTP Server",		// English
		"HTTP Server",		// Deutsch
		"",		// Slovenski
		"Server HTTP",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"HTTP-palvelin",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"VDR-to-VDR Client",		// English
		"VDR-zu-VDR Client",		// Deutsch
		"",		// Slovenski
		"Client VDR-to-VDR",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"VDR-asiakas",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Please restart VDR to activate changes",		// English
		"Bitte starten Sie f�r die �nderungen VDR neu",		// Deutsch
		"",		// Slovenski
		"Riavviare VDR per attivare i cambiamenti",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Aktivoi muutokset k�ynnist�m�ll� VDR uudelleen",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Synchronize EPG",		// English
		"EPG synchronisieren",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"P�ivit� ohjelmaopas",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Suspend Live TV",		// English
		"Live-TV pausieren",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Pys�yt� suora TV-l�hetys",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Suspend behaviour",		// English
		"Pausierverhalten",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Pys�ytystoiminto",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Offer suspend mode",		// English
		"Pausieren anbieten",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"tyrkyt�",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Always suspended",		// English
		"Immer pausiert",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"aina",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Never suspended",		// English
		"Nie pausiert",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"ei koskaan",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Suspend Server",		// English
		"Server pausieren",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Pys�yt� palvelin",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Server is suspended",		// English
		"Server ist pausiert",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Palvelin on pys�ytetty",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Couldn't suspend Server!",		// English
		"Konnte Server nicht pausieren!",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Palvelinta ei onnistuttu pys�ytt�m��n!",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Client may suspend",		// English
		"Client darf pausieren",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Asiakas saa pys�ytt�� palvelimen",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{	"Bind to IP",		// English
		"",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Sido osoitteeseen",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
        },
	{	"Filter Streaming",		// English
		"",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Suodatetun tiedon suoratoisto",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
        },
	{	"Streaming active",		// English
		"Streamen im Gange",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Suoratoistopalvelin aktiivinen",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
        },
	{	"Hide Mainmenu Entry",		// English
		"Hauptmen�eintrag verstecken",		// Deutsch
		"",		// Slovenski
		"",		// Italiano
		"",		// Nederlands
		"",		// Portugu�s
		"",		// Fran�ais
		"",		// Norsk
		"Piilota valinta p��valikosta",		// suomi
		"",		// Polski
		"",		// Espa�ol
		"",		// Ellinika
		"",		// Svenska
		"",		// Romaneste
		"",		// Magyar
		"",		// Catala
		"",		// Russian
		"",		// Hrvatski
		"",		// Eesti
		"",		// Dansk
		"",		// Czech
#if VDRVERSNUM >= 10502
		"",		// T�rk�e
#endif
	},
	{ NULL }
};
