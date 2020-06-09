
#ifndef UPNP_H
#define UPNP_H



#include <stdio.h>
#include "ixml.h"
#include "upnpconfig.h"
#if UPNP_HAVE_DEBUG
#	include "upnpdebug.h"
#endif

#define UpnpCloseSocket         close
#define UPNP_SOCKETERROR        -1
#define UPNP_INVALID_SOCKET     -1
#define SOCKET                  int

#include <netinet/in.h>

#define LINE_SIZE  180
#define NAME_SIZE  256
#define MNFT_NAME_SIZE  64
#define MODL_NAME_SIZE  32
#define SERL_NUMR_SIZE  64
#define MODL_DESC_SIZE  64
#define UPNP_INFINITE -1

#define UPNP_USING_CHUNKED			-3
#define UPNP_UNTIL_CLOSE			-4





#define UPNP_E_SUCCESS          0


#define UPNP_E_INVALID_HANDLE   -100


#define UPNP_E_INVALID_PARAM    -101


#define UPNP_E_OUTOF_HANDLE     -102

#define UPNP_E_OUTOF_CONTEXT    -103


#define UPNP_E_OUTOF_MEMORY     -104


#define UPNP_E_INIT             -105

#define UPNP_E_BUFFER_TOO_SMALL -106


#define UPNP_E_INVALID_DESC     -107


#define UPNP_E_INVALID_URL      -108

#define UPNP_E_INVALID_SID      -109
#define UPNP_E_INVALID_DEVICE   -110


#define UPNP_E_INVALID_SERVICE  -111


#define UPNP_E_BAD_RESPONSE     -113

#define UPNP_E_BAD_REQUEST      -114


#define UPNP_E_INVALID_ACTION   -115


#define UPNP_E_FINISH           -116


#define UPNP_E_INIT_FAILED      -117


#define UPNP_E_URL_TOO_BIG      -118


#define UPNP_E_BAD_HTTPMSG      -119


#define UPNP_E_ALREADY_REGISTERED -120


#define UPNP_E_NETWORK_ERROR    -200


#define UPNP_E_SOCKET_WRITE     -201


#define UPNP_E_SOCKET_READ      -202


#define UPNP_E_SOCKET_BIND      -203


#define UPNP_E_SOCKET_CONNECT   -204


#define UPNP_E_OUTOF_SOCKET     -205


#define UPNP_E_LISTEN           -206


#define UPNP_E_TIMEDOUT         -207


#define UPNP_E_SOCKET_ERROR	    -208

#define UPNP_E_FILE_WRITE_ERROR       -209
#define UPNP_E_EVENT_PROTOCOL         -300


#define UPNP_E_SUBSCRIBE_UNACCEPTED   -301


#define UPNP_E_UNSUBSCRIBE_UNACCEPTED -302


#define UPNP_E_NOTIFY_UNACCEPTED      -303


#define UPNP_E_INVALID_ARGUMENT       -501


#define UPNP_E_FILE_NOT_FOUND         -502


#define UPNP_E_FILE_READ_ERROR        -503


#define UPNP_E_EXT_NOT_XML            -504

#define UPNP_E_NO_WEB_SERVER          -505
#define UPNP_E_OUTOF_BOUNDS	      -506


#define UPNP_E_NOT_FOUND	      -507


#define UPNP_E_INTERNAL_ERROR         -911

#define UPNP_SOAP_E_INVALID_ACTION    401
#define UPNP_SOAP_E_INVALID_ARGS      402
#define UPNP_SOAP_E_OUT_OF_SYNC       403
#define UPNP_SOAP_E_INVALID_VAR       404
#define UPNP_SOAP_E_ACTION_FAILED     501


#ifndef OUT
#define OUT
#endif

#ifndef IN
#define IN
#endif

#ifndef INOUT
#define INOUT
#endif

enum UpnpOpenFileMode{UPNP_READ, UPNP_WRITE};




typedef int  UpnpClient_Handle;



typedef int  UpnpDevice_Handle;



enum Upnp_EventType_e {




  UPNP_CONTROL_ACTION_REQUEST,



  UPNP_CONTROL_ACTION_COMPLETE,



  UPNP_CONTROL_GET_VAR_REQUEST,



  UPNP_CONTROL_GET_VAR_COMPLETE,




  UPNP_DISCOVERY_ADVERTISEMENT_ALIVE,



  UPNP_DISCOVERY_ADVERTISEMENT_BYEBYE,



  UPNP_DISCOVERY_SEARCH_RESULT,



  UPNP_DISCOVERY_SEARCH_TIMEOUT,




  UPNP_EVENT_SUBSCRIPTION_REQUEST,



  UPNP_EVENT_RECEIVED,



  UPNP_EVENT_RENEWAL_COMPLETE,



  UPNP_EVENT_SUBSCRIBE_COMPLETE,



  UPNP_EVENT_UNSUBSCRIBE_COMPLETE,



  UPNP_EVENT_AUTORENEWAL_FAILED,


  
  UPNP_EVENT_SUBSCRIPTION_EXPIRED

};

typedef enum Upnp_EventType_e Upnp_EventType;


    
typedef char Upnp_SID[44];



enum Upnp_SType_e {

  UPNP_S_ALL,    

  UPNP_S_ROOT,   


  UPNP_S_DEVICE, 
                       

  UPNP_S_SERVICE 
                       
};

typedef enum Upnp_SType_e Upnp_SType;


enum Upnp_DescType_e { 

	UPNPREG_URL_DESC, 
	

	UPNPREG_FILENAME_DESC,
    

	UPNPREG_BUF_DESC 

};

typedef enum Upnp_DescType_e Upnp_DescType;


struct Upnp_Action_Request
{
  int ErrCode;

  int Socket;

  char ErrStr[LINE_SIZE];

  char ActionName[NAME_SIZE];

  char DevUDN[NAME_SIZE];

  char ServiceID[NAME_SIZE];

  IXML_Document *ActionRequest;

  IXML_Document *ActionResult;

  struct in_addr CtrlPtIPAddr;


  IXML_Document *SoapHeader;
};

struct Upnp_Action_Complete
{
  int ErrCode;

  char CtrlUrl[NAME_SIZE];

  IXML_Document *ActionRequest;

  IXML_Document *ActionResult;

};



struct Upnp_State_Var_Request
{
  int ErrCode;

  int Socket;

  char ErrStr[LINE_SIZE];

  char DevUDN[NAME_SIZE];

  char ServiceID[NAME_SIZE];

  char StateVarName[NAME_SIZE];

  struct in_addr CtrlPtIPAddr;


  DOMString CurrentVal;
};



struct Upnp_State_Var_Complete
{
  int ErrCode;

  char CtrlUrl[NAME_SIZE];

  char StateVarName[NAME_SIZE];

  DOMString CurrentVal;
};


struct Upnp_Event
{
  Upnp_SID Sid;

  int EventKey;

  IXML_Document *ChangedVariables;

};


typedef struct sockaddr_in SOCKADDRIN;


struct Upnp_Discovery
{

  int  ErrCode;                  
				     
  int  Expires;                  
                                     
  char DeviceId[LINE_SIZE];      

  char DeviceType[LINE_SIZE];    

  char ServiceType[LINE_SIZE];

  char ServiceVer[LINE_SIZE];    

  char Location[LINE_SIZE];      

  char Os[LINE_SIZE];            
				     
  char Date[LINE_SIZE];            
				     
  char Ext[LINE_SIZE];           
				     
  SOCKADDRIN * DestAddr; 

};



struct Upnp_Event_Subscribe {



  Upnp_SID Sid;            

  int ErrCode;              

  char PublisherUrl[NAME_SIZE]; 

  int TimeOut;              
                              
};
  


struct Upnp_Subscription_Request
{
  char *ServiceId; 

  char *UDN;       

  Upnp_SID Sid;

};


struct File_Info
{

  int file_length;


  time_t last_modified;


  int is_directory;


  int is_readable;


   
  DOMString content_type;

};


typedef void *UpnpWebFileHandle;


struct UpnpVirtualDirCallbacks
{

  int (*get_info) (
    IN  const char *filename,     
    OUT struct File_Info *info    
    );
                                  

  UpnpWebFileHandle (*open)(
    IN const char *filename,       
    IN enum UpnpOpenFileMode Mode  
    );


   int (*read) (
     IN UpnpWebFileHandle fileHnd,  
     OUT char *buf,                 
     IN size_t buflen               
     );


   int (*write) (
     IN UpnpWebFileHandle fileHnd, 
     IN char *buf,                 
     IN size_t buflen              
     );


   int (*seek) (
     IN UpnpWebFileHandle fileHnd,  
     IN long offset,                
     IN int origin                  
     );


   int (*close) (
     IN UpnpWebFileHandle fileHnd   
     );

};

typedef struct virtual_Dir_List
{
    struct virtual_Dir_List *next;
    char dirName[NAME_SIZE];
} virtualDirList;



typedef int  (*Upnp_FunPtr) (
    IN Upnp_EventType EventType, 
    IN void *Event, 
    IN void *Cookie
    );


#ifdef __cplusplus
extern "C" {
#endif 



int UpnpInit(
    IN const char *HostIP,      
    IN unsigned short DestPort  
    );



int UpnpFinish();


unsigned short UpnpGetServerPort(void);


char * UpnpGetServerIpAddress(void);



int UpnpRegisterClient(
    IN Upnp_FunPtr Callback,   
    IN const void *Cookie,     
    OUT UpnpClient_Handle *Hnd 
    );  



int UpnpRegisterRootDevice(
    IN const char *DescUrl,    
    IN Upnp_FunPtr Callback,   
    IN const void *Cookie,     
    OUT UpnpDevice_Handle *Hnd 
    );


 
int UpnpRegisterRootDevice2(
    IN Upnp_DescType descriptionType,
    IN const char* description,      
    IN size_t bufferLen,             
    IN int config_baseURL,           
    IN Upnp_FunPtr Fun,              
    IN const void* Cookie,           
    OUT UpnpDevice_Handle* Hnd       
    );



int UpnpUnRegisterClient(
    IN UpnpClient_Handle Hnd  
    );



int UpnpUnRegisterRootDevice(
   IN UpnpDevice_Handle 
   );



int UpnpSetContentLength(
    IN UpnpClient_Handle Hnd,  
    IN int contentLength       
    );



int UpnpSetMaxContentLength(
    IN size_t contentLength    
    );






int UpnpSearchAsync(
    IN UpnpClient_Handle Hnd, 
    IN int Mx,                
    IN const char *Target,    
    IN const void *Cookie     
    ); 


int UpnpSendAdvertisement(
    IN UpnpDevice_Handle Hnd, 
    IN int Exp                
    );






int UpnpGetServiceVarStatus(
    IN UpnpClient_Handle Hnd,     
    IN const char *ActionURL,     
    IN const char *VarName,       
    OUT DOMString *StVarVal       
    );



int UpnpGetServiceVarStatusAsync(
    IN UpnpClient_Handle Hnd, 
    IN const char *ActionURL, 
    IN const char *VarName,   
    IN Upnp_FunPtr Fun,       
    IN const void *Cookie     
    );



int UpnpSendAction(
    IN UpnpClient_Handle Hnd,     
    IN const char *ActionURL,     
    IN const char *ServiceType,   
    IN const char *DevUDN,        
    IN IXML_Document *Action,     
    OUT IXML_Document **RespNode  
   );



int UpnpSendActionEx(
    IN UpnpClient_Handle Hnd,    
    IN const char *ActionURL,    
    IN const char *ServiceType,  
    IN const char *DevUDN,       
    IN IXML_Document *Header,    
    IN IXML_Document *Action,    
    OUT IXML_Document **RespNode 
   );



int UpnpSendActionAsync(
    IN UpnpClient_Handle Hnd,   
    IN const char *ActionURL,   
    IN const char *ServiceType, 
    IN const char *DevUDN,      
    IN IXML_Document *Action,   
    IN Upnp_FunPtr Fun,         
    IN const void *Cookie       
    );



int UpnpSendActionExAsync(
    IN UpnpClient_Handle Hnd,   
    IN const char *ActionURL,   
    IN const char *ServiceType, 
    IN const char *DevUDN,      
    IN IXML_Document *Header,   
    IN IXML_Document *Action,   
    IN Upnp_FunPtr Fun,         
    IN const void *Cookie       
    );






int UpnpAcceptSubscription(
    IN UpnpDevice_Handle Hnd, 
    IN const char *DevID,     
    IN const char *ServID,    
    IN const char **VarName,  
    IN const char **NewVal,   
    IN int cVariables,        
    IN Upnp_SID SubsId        
    );



int UpnpAcceptSubscriptionExt(
    IN UpnpDevice_Handle Hnd,  
    IN const char *DevID,      
    IN const char *ServID,     
    IN IXML_Document *PropSet, 
    IN Upnp_SID SubsId         
    );



int UpnpNotify(
    IN UpnpDevice_Handle,   
    IN const char *DevID,   
    IN const char *ServID,  
    IN const char **VarName,
    IN const char **NewVal, 
    IN int cVariables       
    );



int UpnpNotifyExt(
    IN UpnpDevice_Handle,       
    IN const char *DevID,       
    IN const char *ServID,      
    IN IXML_Document *PropSet   
    );



int UpnpRenewSubscription(
    IN UpnpClient_Handle Hnd, 
    INOUT int *TimeOut,       
    IN Upnp_SID SubsId        
    );



int UpnpRenewSubscriptionAsync(
    IN UpnpClient_Handle Hnd, 
    IN int TimeOut,           
    IN Upnp_SID SubsId,       
    IN Upnp_FunPtr Fun,       
    IN const void *Cookie     
    );



int UpnpSetMaxSubscriptions(  
    IN UpnpDevice_Handle Hnd, 
    IN int MaxSubscriptions   
    );



int UpnpSetMaxSubscriptionTimeOut(  
    IN UpnpDevice_Handle Hnd,       
    IN int MaxSubscriptionTimeOut   
    );



int UpnpSubscribe(
    IN UpnpClient_Handle Hnd,    
    IN const char *PublisherUrl, 
    INOUT int *TimeOut,          
    OUT Upnp_SID SubsId          
    );



int UpnpSubscribeAsync(
    IN UpnpClient_Handle Hnd,      
    IN const char *PublisherUrl,   
    IN int TimeOut,                
    IN Upnp_FunPtr Fun,            
    IN const void *Cookie          
    );



int UpnpUnSubscribe(
    IN UpnpClient_Handle Hnd, 
    IN Upnp_SID SubsId        
    );



int UpnpUnSubscribeAsync(
    IN UpnpClient_Handle Hnd, 
    IN Upnp_SID SubsId,       
    IN Upnp_FunPtr Fun,       
    IN const void *Cookie     
    );







int UpnpDownloadUrlItem(
    IN const char *url,          
    OUT char **outBuf,           
    OUT char *contentType        
    );



int UpnpOpenHttpGet(
	IN const char *url,	    
	IN OUT void **handle,       
	IN OUT char **contentType,  
	IN OUT int *contentLength,  
	IN OUT int *httpStatus,	    
	IN int timeout		    
	  );



int UpnpOpenHttpGetEx(
	IN const char *url,         
	IN OUT void **handle,       
	IN OUT char **contentType,  
	IN OUT int *contentLength,  
	IN OUT int *httpStatus,	    
	IN int lowRange,            
	IN int highRange,           
	IN int timeout	            
	  );



int UpnpReadHttpGet(
	IN void *handle,           
	IN OUT char *buf,          
	IN OUT unsigned int *size, 
	IN int timeout             
	);



int UpnpCloseHttpGet(IN void *handle);




int UpnpOpenHttpPost(
	IN const char *url,         
	IN OUT void **handle,	    
	IN const char *contentType, 
	IN int contentLength,       
	IN int timeout              
	);




int UpnpWriteHttpPost(
	IN void *handle,          
	IN char *buf,             
	IN unsigned int *size,    
	IN int timeout            
	);


  
int UpnpCloseHttpPost(
	IN void *handle,          
	IN OUT int *httpStatus,   
	IN int timeout            
	);
  



int UpnpDownloadXmlDoc(
    IN const char *url,          
    OUT IXML_Document **xmlDoc   
    );





 
int UpnpSetWebServerRootDir( 
    IN const char* rootDir  
    );



int UpnpSetVirtualDirCallbacks(
    IN struct UpnpVirtualDirCallbacks *callbacks 
    );



int UpnpEnableWebserver(
    IN int enable 
    );



int UpnpIsWebserverEnabled();



int UpnpAddVirtualDir(
    IN const char *dirName 
    );



int UpnpRemoveVirtualDir(
    IN const char *dirName 
    );



void UpnpRemoveAllVirtualDirs( );

void UpnpFree(
    IN void *item 
    );


#ifdef __cplusplus
}
#endif 


#endif

