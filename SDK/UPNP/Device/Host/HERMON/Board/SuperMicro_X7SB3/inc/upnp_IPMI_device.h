
#ifndef UPNP_TV_DEVICE_H
#define UPNP_TV_DEVICE_H

#include <stdio.h>
#include <signal.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "ithread.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "upnp.h"
#include "sample_util.h"

#define MAX_COLOR 10
#define MIN_COLOR 1

#define MAX_BRIGHTNESS 10
#define MIN_BRIGHTNESS 1

#define POWER_ON 1
#define POWER_OFF 0

#define MAX_TINT 10
#define MIN_TINT 1

#define MAX_VOLUME 10
#define MIN_VOLUME 1

#define MAX_CONTRAST 10
#define MIN_CONTRAST 1

#define MAX_CHANNEL 100
#define MIN_CHANNEL 1

#define TV_SERVICE_SERVCOUNT  2

#define TV_SERVICE_CONTROL    0

#define TV_SERVICE_PICTURE    1

#define TV_CONTROL_VARCOUNT   3

#define TV_CONTROL_POWER      0

#define TV_CONTROL_CHANNEL    1

#define TV_CONTROL_VOLUME     2

#define TV_PICTURE_VARCOUNT   4

#define TV_PICTURE_COLOR      0

#define TV_PICTURE_TINT       1

#define TV_PICTURE_CONTRAST   2

#define TV_PICTURE_BRIGHTNESS 3

#define TV_MAX_VAL_LEN 5

#define TV_MAXACTIONS 12

#define TV_MAXVARS TV_PICTURE_VARCOUNT


extern char TvDeviceType[];

extern char *TvServiceType[];





typedef int (*upnp_action) (IXML_Document *request, IXML_Document **out, 
			    char **errorString);


struct TvService {
  
  char UDN[NAME_SIZE]; 
  char ServiceId[NAME_SIZE];
  char ServiceType[NAME_SIZE];
  char *VariableName[TV_MAXVARS]; 
  char *VariableStrVal[TV_MAXVARS];
  char *ActionNames[TV_MAXACTIONS];
  upnp_action actions[TV_MAXACTIONS];
  unsigned int  VariableCount;
};

extern struct TvService tv_service_table[];

extern UpnpDevice_Handle device_handle;



extern ithread_mutex_t TVDevMutex;




int SetActionTable(int serviceType, struct TvService * out);


int TvDeviceStateTableInit(char*);



int TvDeviceHandleSubscriptionRequest(struct Upnp_Subscription_Request *);


int TvDeviceHandleGetVarRequest(struct Upnp_State_Var_Request *);


int TvDeviceHandleActionRequest(struct Upnp_Action_Request *);


int TvDeviceCallbackEventHandler(Upnp_EventType, void*, void*);


int TvDeviceSetServiceTableVar(unsigned int, unsigned int, char*);



int TvDevicePowerOn(IN IXML_Document * in, OUT IXML_Document **out, 
		    OUT char **errorString);


int TvDevicePowerOff(IN IXML_Document *in, OUT IXML_Document **out, 
		     OUT char **errorString);


int TvDeviceSetChannel(IN IXML_Document *in, OUT IXML_Document **out, 
		       OUT char **errorString);


int TvDeviceIncreaseChannel(IN IXML_Document *in, OUT IXML_Document **out, 
			    OUT char **errorString);

int TvDeviceDecreaseChannel(IN IXML_Document *in, OUT IXML_Document **out, 
			    OUT char **errorString);

int TvDeviceSetVolume(IN IXML_Document *in, OUT IXML_Document **out, 
		      OUT char **errorString);


int TvDeviceIncreaseVolume(IN IXML_Document *in, OUT IXML_Document**out, 
			   OUT char **errorString);



int TvDeviceDecreaseVolume(IN IXML_Document *in, OUT IXML_Document**out, 
			   OUT char **errorString);




int TvDeviceSetColor(IN IXML_Document *in, OUT IXML_Document **out, 
		     OUT char **errorString);



int TvDeviceIncreaseColor(IN IXML_Document * in, OUT IXML_Document **out, 
			  OUT char **errorString);


int TvDeviceDecreaseColor(IN IXML_Document * in, OUT IXML_Document **out, 
			  OUT char **errorString);


int TvDeviceSetTint(IN IXML_Document *in, OUT IXML_Document **out, 
		    OUT char **errorString);


int TvDeviceIncreaseTint(IN IXML_Document *in, OUT IXML_Document **out, 
			 OUT char **errorString);


int TvDeviceDecreaseTint(IN IXML_Document *in, OUT IXML_Document **out, 
			 OUT char **errorString);


int TvDeviceSetContrast(IN IXML_Document *in, OUT IXML_Document **out, 
			OUT char **errorString);


int TvDeviceIncreaseContrast(IN IXML_Document *in, OUT IXML_Document **out, 
			     OUT char **errorString);

int TvDeviceDecreaseContrast(IN IXML_Document *in, OUT IXML_Document **out, 
			     OUT char **errorString);


int TvDeviceSetBrightness(IN IXML_Document *in, OUT IXML_Document **out, 
			  OUT char **errorString);


int TvDeviceIncreaseBrightness(IN IXML_Document *in, OUT IXML_Document **out, 
			       OUT char **errorString);


int TvDeviceDecreaseBrightness(IN IXML_Document *in, OUT IXML_Document **out, 
			       OUT char **errorString);

int TvDeviceStart(char * ip_address, unsigned short port,char * desc_doc_name,
				  char *web_dir_path, print_string pfun);
int TvDeviceStop();

#ifdef __cplusplus
}
#endif

#endif
