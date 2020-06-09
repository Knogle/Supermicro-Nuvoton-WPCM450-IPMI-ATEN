
#ifndef SAMPLE_UTIL_H
#define SAMPLE_UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

#include <string.h>

#include "upnptools.h"
#include "ithread.h"
#include "ixml.h"

extern ithread_mutex_t display_mutex ;

typedef enum {
	STATE_UPDATE = 0,
	DEVICE_ADDED =1,
	DEVICE_REMOVED=2,
	GET_VAR_COMPLETE=3
} eventType;



char * SampleUtil_GetElementValue(IN IXML_Element *element);



IXML_NodeList *SampleUtil_GetFirstServiceList(IN IXML_Document * doc); 



char * SampleUtil_GetFirstDocumentItem(IN IXML_Document *doc, IN const char *item); 




char * SampleUtil_GetFirstElementItem(IN IXML_Element *element, IN const char *item); 


void SampleUtil_PrintEventType(IN Upnp_EventType S);


int SampleUtil_PrintEvent(IN Upnp_EventType EventType, 
			  IN void *Event);


int SampleUtil_FindAndParseService (IN IXML_Document *DescDoc, IN char* location, 
				    IN char *serviceType, OUT char **serviceId, 
				    OUT char **eventURL, OUT char **controlURL);



typedef void (*print_string)(const char *string);

extern print_string gPrintFun;


typedef void (*state_update)( const char *varName, const char *varValue, const char *UDN,
							 eventType type);

extern state_update gStateUpdateFun;


int SampleUtil_Initialize(print_string print_function);


int SampleUtil_Finish(void);


int SampleUtil_Print( char *fmt, ... );


int SampleUtil_RegisterUpdateFunction( state_update update_function );


void SampleUtil_StateUpdate( const char *varName, const char *varValue, const char *UDN,
							eventType type);

#ifdef __cplusplus
};
#endif

#endif 
