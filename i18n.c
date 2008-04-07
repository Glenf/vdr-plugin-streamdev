/*
 *  $Id: i18n.c,v 1.7 2008/04/07 14:40:39 schmirl Exp $
 */
 
#include "i18n.h"

const char *i18n_name = NULL;

const tI18nPhrase Phrases[] = {
	{	"VDR Streaming Server",	// English
		"VDR Streaming Server",	// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"VDR-suoratoistopalvelin",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika / Greek
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"VTP Streaming Client",	// English
		"VTP Streaming Client",	// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"VTP-suoratoistoasiakas ",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika / Greek
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Start VDR-to-VDR Server",// English
		"VDR-zu-VDR Server starten",// Deutsch
		"",											// Slovenski
		"Avvia il Server VDR-toVDR",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"K�ynnist� VDR-palvelin",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika / Greek
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Start HTTP Server",		// English
		"HTTP Server starten",	// Deutsch
		"",											// Slovenski
		"Avvia il Server HTTP", // Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"K�ynnist� HTTP-palvelin",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"HTTP Streamtype",		  // English
		"HTTP Streamtyp",	      // Deutsch
		"",											// Slovenski
		"Tipo di Stream HTTP",  // Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"HTTP-l�hetysmuoto",									// Suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Start Client",					// English
		"Client starten",				// Deutsch
		"",											// Slovenski
		"Avvia il Client",			// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"K�ynnist� VDR-asiakas",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"VDR-to-VDR Server Port",// English
		"Port des VDR-zu-VDR Servers",// Deutsch
		"",											// Slovenski
		"Porta del Server VDR-to-VDR",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"VDR-palvelimen portti",								// Suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"HTTP Server Port",			// English
		"Port des HTTP Servers",// Deutsch
		"",											// Slovenski
		"Porta del Server HTTP",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"HTTP-palvelimen portti",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Maximum Number of Clients",// English
		"Maximalanzahl an Clients",// Deutsch
		"",											// Slovenski
		"Numero Massimo di Client",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Suurin sallittu asiakkaiden m��r�",							// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Remote IP",						// English
		"IP der Gegenseite",		// Deutsch
		"",											// Slovenski
		"Indirizzo IP del Server",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Et�koneen IP-osoite",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Remote Port",					// English
		"Port der Gegenseite",	// Deutsch
		"",											// Slovenski
		"Porta del Server Remoto",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Et�koneen portti",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Remote Streamtype",		// English
		"Streamtyp von Gegenseite",// Deutsch
		"",											// Slovenski
		"Tipo di Stream",       // Italiano (oppure Flusso ?)
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Et�koneen l�hetysmuoto",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Common Settings",		  // English
		"Allgemeines",          // Deutsch
		"",											// Slovenski
		"Settaggi Comuni",			// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Yleiset asetukset",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"VDR-to-VDR Server",		// English
		"VDR-zu-VDR Server",    // Deutsch
		"",											// Slovenski
		"Server VDR-to-VDR",		// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"VDR-palvelin",										// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"HTTP Server",		      // English
		"HTTP Server",          // Deutsch
		"",											// Slovenski
		"Server HTTP",					// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"HTTP-palvelin",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"VDR-to-VDR Client",		// English
		"VDR-zu-VDR Client",    // Deutsch
		"",											// Slovenski
		"Client VDR-to-VDR",		// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"VDR-asiakas",										// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Please restart VDR to activate changes",// English
		"Bitte starten Sie f�r die �nderungen VDR neu",// Deutsch
		"",											// Slovenski
		"Riavviare VDR per attivare i cambiamenti",// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Aktivoi muutokset k�ynnist�m�ll� VDR uudelleen",					// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Synchronize EPG",			// English
		"EPG synchronisieren",	// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"P�ivit� ohjelmaopas",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Suspend Live TV",			// English
		"Live-TV pausieren",		// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Pys�yt� suora TV-l�hetys",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Suspend behaviour",		// English
		"Pausierverhalten",			// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Pys�ytystoiminto",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Offer suspend mode",		// English
		"Pausieren anbieten",		// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"tyrkyt�",										// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Always suspended",			// English
		"Immer pausiert",				// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"aina",											// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Never suspended",			// English
		"Nie pausiert",					// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"ei koskaan",										// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Suspend Server",				// English
		"Server pausieren",			// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Pys�yt� palvelin",									// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Server is suspended",	// English
		"Server ist pausiert",	// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Palvelin on pys�ytetty",								// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Couldn't suspend Server!",// English
		"Konnte Server nicht pausieren!",// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Palvelinta ei onnistuttu pys�ytt�m��n!",						// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
	{	"Client may suspend",		// English
		"Client darf pausieren",// Deutsch
		"",											// Slovenski
		"",											// Italiano
		"",											// Nederlands
		"",											// Portugu�s
		"",											// Fran�ais
		"",											// Norsk
		"Asiakas saa pys�ytt�� palvelimen",							// suomi
		"",											// Polski
		"",											// Espa�ol
		"",											// Ellinika
		"",											// Svenska
		"",											// Romaneste
		"",											// Magyar
		"",											// Catala
		""                      // Russian
	},
        {       "Bind to IP",           // English
                "",// Deutsch
                "",                                                                                     // Slovenski
                "",                                                                                     // Italiano
                "",                                                                                     // Nederlands
                "",                                                                                     // Portugu�s
                "",                                                                                     // Fran�ais
                "",                                                                                     // Norsk
                "Sido osoitteeseen",                                                                    // suomi
                "",                                                                                     // Polski
                "",                                                                                     // Espa�ol
                "",                                                                                     // Ellinika
                "",                                                                                     // Svenska
                "",                                                                                     // Romaneste
                "",                                                                                     // Magyar
                "",                                                                                     // Catala
                ""                      // Russian
        },
        {       "Filter Streaming",     // English
                "",// Deutsch
                "",                                                                                     // Slovenski
                "",                                                                                     // Italiano
                "",                                                                                     // Nederlands
                "",                                                                                     // Portugu�s
                "",                                                                                     // Fran�ais
                "",                                                                                     // Norsk
                "Suodatetun tiedon suoratoisto",                                                        // suomi
                "",                                                                                     // Polski
                "",                                                                                     // Espa�ol
                "",                                                                                     // Ellinika
                "",                                                                                     // Svenska
                "",                                                                                     // Romaneste
                "",                                                                                     // Magyar
                "",                                                                                     // Catala
                ""                      // Russian
        },
        {       "Streaming active",     // English
                "Streamen im Gange",// Deutsch
                "",                                                                                     // Slovenski
                "",                                                                                     // Italiano
                "",                                                                                     // Nederlands
                "",                                                                                     // Portugu�s
                "",                                                                                     // Fran�ais
                "",                                                                                     // Norsk
                "Suoratoistopalvelin aktiivinen", // suomi
                "",                                                                                     // Polski
                "",                                                                                     // Espa�ol
                "",                                                                                     // Ellinika
                "",                                                                                     // Svenska
                "",                                                                                     // Romaneste
                "",                                                                                     // Magyar
                "",                                                                                     // Catala
                ""                      // Russian
        },
	{ NULL }
};
