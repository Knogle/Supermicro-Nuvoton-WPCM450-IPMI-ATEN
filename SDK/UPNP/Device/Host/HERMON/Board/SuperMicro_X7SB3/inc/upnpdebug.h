
#ifndef UPNP_DEBUG_H
#define UPNP_DEBUG_H 

#include "upnpconfig.h"

#if UPNP_HAVE_DEBUG

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif







typedef enum Upnp_Module {SSDP,SOAP,GENA,TPOOL,MSERV,DOM,API, HTTP} Dbg_Module;
typedef enum Upnp_LogLevel_e {
	UPNP_CRITICAL,
	UPNP_PACKET,
	UPNP_INFO,
	UPNP_ALL
} Upnp_LogLevel;

#define Dbg_Level	Upnp_LogLevel



#define UPNP_DEFAULT_LOG_LEVEL	UPNP_ALL




int UpnpInitLog();

#define InitLog		UpnpInitLog



void UpnpSetLogLevel (Upnp_LogLevel);



void UpnpCloseLog();

#define CloseLog	UpnpCloseLog



void UpnpSetLogFileNames (const char* ErrFileName, const char* InfoFileName);

#define SetLogFileNames		UpnpSetLogFileNames



FILE* UpnpGetDebugFile (Upnp_LogLevel level, Dbg_Module module);

#define GetDebugFile	UpnpGetDebugFile



void UpnpPrintf (Upnp_LogLevel DLevel, Dbg_Module Module,
		 const char* DbgFileName, int DbgLineNo,
		 const char* FmtStr,
		 ...)
#if (__GNUC__ >= 3)
	__attribute__((format (__printf__, 5, 6)))
#endif
;



void UpnpDisplayBanner (FILE *fd,
			const char** lines, size_t size, int starlength);



void UpnpDisplayFileAndLine (FILE *fd, const char *DbgFileName, int DbgLineNo);




#ifdef __cplusplus
}
#endif

#endif 

#endif 



