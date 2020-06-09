



#ifndef UPNP_TOOLS_H
#define UPNP_TOOLS_H

#include "upnp.h"

#if UPNP_HAVE_TOOLS

#ifdef __cplusplus
extern "C" {
#endif



int UpnpResolveURL(
    IN const char * BaseURL,  
    IN const char * RelURL,   
    OUT char * AbsURL   
    );



IXML_Document* UpnpMakeAction(
    IN const char * ActionName, 
    IN const char * ServType,   
    IN int NumArg,              
    IN const char * Arg,        
    IN ...                   
    );



int UpnpAddToAction(
        IN OUT IXML_Document ** ActionDoc, 

        IN const char * ActionName,   
        IN const char * ServType,     
        IN const char * ArgName,      
        IN const char * ArgVal        
        );



IXML_Document* UpnpMakeActionResponse(
    IN const char * ActionName, 
    IN const char * ServType,   
    IN int NumArg,              
    IN const char * Arg,        
    IN ...                   
    );



int UpnpAddToActionResponse(
        IN OUT IXML_Document ** ActionResponse, 

        IN const char * ActionName,        
        IN const char * ServType,          
        IN const char * ArgName,           
        IN const char * ArgVal             
        );



int UpnpAddToPropertySet(
    IN OUT IXML_Document **PropSet,    

    IN const char * ArgName,      
    IN const char * ArgVal        
    );



IXML_Document* UpnpCreatePropertySet(
    IN int NumArg,        
    IN const char* Arg,   
    IN ...
    );



const char * UpnpGetErrorMessage(
        int errorcode  
        );


#ifdef __cplusplus
}
#endif

#endif 

#endif 


