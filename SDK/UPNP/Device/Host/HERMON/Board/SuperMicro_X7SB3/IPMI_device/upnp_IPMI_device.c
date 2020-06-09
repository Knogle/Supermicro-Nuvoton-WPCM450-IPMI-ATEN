
#include "../inc/upnp_IPMI_device.h"
#include <stdio.h>

#define DEFAULT_WEB_DIR "/nv"

#define DESC_URL_SIZE 200


char TvDeviceType[] = "urn:schemas-upnp-org:device:management:1";


char *TvServiceType[] = { "urn:schemas-upnp-org:service:IPMImanagement:1",
    "urn:schemas-upnp-org:service:IPMIpicture:1"
};

#define	DEFAULT_DESC_SAMPLE_FILE		"IPMIdevicedesc_sample.xml"
#define FNAME_SIZE	64
char *friendlyName = "friendlyName";


char *tvc_varname[] = { "Power", "Channel", "Volume" };
char tvc_varval[TV_CONTROL_VARCOUNT][TV_MAX_VAL_LEN];
char *tvc_varval_def[] = { "1", "1", "5" };


char *tvp_varname[] = { "Color", "Tint", "Contrast", "Brightness" };
char tvp_varval[TV_PICTURE_VARCOUNT][TV_MAX_VAL_LEN];
char *tvp_varval_def[] = { "5", "5", "5", "5" };


int default_advr_expire = 100;


struct TvService tv_service_table[2];


UpnpDevice_Handle device_handle = -1;


ithread_mutex_t TVDevMutex;

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


int
SetServiceTable( IN int serviceType,
                 IN const char *UDN,
                 IN const char *serviceId,
                 IN const char *serviceTypeS,
                 INOUT struct TvService *out )
{
    unsigned int i = 0;

    strcpy( out->UDN, UDN );
    strcpy( out->ServiceId, serviceId );
    strcpy( out->ServiceType, serviceTypeS );

    switch ( serviceType ) {
        case TV_SERVICE_CONTROL:
            out->VariableCount = TV_CONTROL_VARCOUNT;
            for( i = 0;
                 i < tv_service_table[TV_SERVICE_CONTROL].VariableCount;
                 i++ ) {
                tv_service_table[TV_SERVICE_CONTROL].VariableName[i]
                    = tvc_varname[i];
                tv_service_table[TV_SERVICE_CONTROL].VariableStrVal[i]
                    = tvc_varval[i];
                strcpy( tv_service_table[TV_SERVICE_CONTROL].
                        VariableStrVal[i], tvc_varval_def[i] );
            }

            break;
        case TV_SERVICE_PICTURE:
            out->VariableCount = TV_PICTURE_VARCOUNT;

            for( i = 0;
                 i < tv_service_table[TV_SERVICE_PICTURE].VariableCount;
                 i++ ) {
                tv_service_table[TV_SERVICE_PICTURE].VariableName[i] =
                    tvp_varname[i];
                tv_service_table[TV_SERVICE_PICTURE].VariableStrVal[i] =
                    tvp_varval[i];
                strcpy( tv_service_table[TV_SERVICE_PICTURE].
                        VariableStrVal[i], tvp_varval_def[i] );
            }

            break;
        default:
            assert( 0 );
    }

    return SetActionTable( serviceType, out );

}


int
SetActionTable( IN int serviceType,
                INOUT struct TvService *out )
{
    if( serviceType == TV_SERVICE_CONTROL ) {
        out->ActionNames[0] = "PowerOn";
        out->actions[0] = TvDevicePowerOn;
        out->ActionNames[1] = "PowerOff";
        out->actions[1] = TvDevicePowerOff;
        out->ActionNames[2] = "SetChannel";
        out->actions[2] = TvDeviceSetChannel;
        out->ActionNames[3] = "IncreaseChannel";
        out->actions[3] = TvDeviceIncreaseChannel;
        out->ActionNames[4] = "DecreaseChannel";
        out->actions[4] = TvDeviceDecreaseChannel;
        out->ActionNames[5] = "SetVolume";
        out->actions[5] = TvDeviceSetVolume;
        out->ActionNames[6] = "IncreaseVolume";
        out->actions[6] = TvDeviceIncreaseVolume;
        out->ActionNames[7] = "DecreaseVolume";
        out->actions[7] = TvDeviceDecreaseVolume;
        out->ActionNames[8] = NULL;
        return 1;
    } else if( serviceType == TV_SERVICE_PICTURE ) {
        out->ActionNames[0] = "SetColor";
        out->ActionNames[1] = "IncreaseColor";
        out->ActionNames[2] = "DecreaseColor";
        out->actions[0] = TvDeviceSetColor;
        out->actions[1] = TvDeviceIncreaseColor;
        out->actions[2] = TvDeviceDecreaseColor;
        out->ActionNames[3] = "SetTint";
        out->ActionNames[4] = "IncreaseTint";
        out->ActionNames[5] = "DecreaseTint";
        out->actions[3] = TvDeviceSetTint;
        out->actions[4] = TvDeviceIncreaseTint;
        out->actions[5] = TvDeviceDecreaseTint;

        out->ActionNames[6] = "SetBrightness";
        out->ActionNames[7] = "IncreaseBrightness";
        out->ActionNames[8] = "DecreaseBrightness";
        out->actions[6] = TvDeviceSetBrightness;
        out->actions[7] = TvDeviceIncreaseBrightness;
        out->actions[8] = TvDeviceDecreaseBrightness;

        out->ActionNames[9] = "SetContrast";
        out->ActionNames[10] = "IncreaseContrast";
        out->ActionNames[11] = "DecreaseContrast";

        out->actions[9] = TvDeviceSetContrast;
        out->actions[10] = TvDeviceIncreaseContrast;
        out->actions[11] = TvDeviceDecreaseContrast;
        return 1;
    }

    return 0;

}


int
TvDeviceStateTableInit( IN char *DescDocURL )
{
    IXML_Document *DescDoc = NULL;
    int ret = UPNP_E_SUCCESS;
    char *servid_ctrl = NULL,
     *evnturl_ctrl = NULL,
     *ctrlurl_ctrl = NULL;
    char *servid_pict = NULL,
     *evnturl_pict = NULL,
     *ctrlurl_pict = NULL;
    char *udn = NULL;

    if( UpnpDownloadXmlDoc( DescDocURL, &DescDoc ) != UPNP_E_SUCCESS ) {
        SampleUtil_Print( "TvDeviceStateTableInit -- Error Parsing %s\n",
                          DescDocURL );
        ret = UPNP_E_INVALID_DESC;
        goto error_handler;
    }

    udn = SampleUtil_GetFirstDocumentItem( DescDoc, "UDN" );


    if( !SampleUtil_FindAndParseService( DescDoc, DescDocURL,
                                         TvServiceType[TV_SERVICE_CONTROL],
                                         &servid_ctrl, &evnturl_ctrl,
                                         &ctrlurl_ctrl ) ) {
        SampleUtil_Print( "TvDeviceStateTableInit -- Error: Could not find"
                          " Service: %s\n",
                          TvServiceType[TV_SERVICE_CONTROL] );

        ret = UPNP_E_INVALID_DESC;
        goto error_handler;
    }

    SetServiceTable( TV_SERVICE_CONTROL, udn, servid_ctrl,
                     TvServiceType[TV_SERVICE_CONTROL],
                     &tv_service_table[TV_SERVICE_CONTROL] );


    if( !SampleUtil_FindAndParseService( DescDoc, DescDocURL,
                                         TvServiceType[TV_SERVICE_PICTURE],
                                         &servid_pict, &evnturl_pict,
                                         &ctrlurl_pict ) ) {
        SampleUtil_Print( "TvDeviceStateTableInit -- Error: Could not find"
                          " Service: %s\n",
                          TvServiceType[TV_SERVICE_PICTURE] );

        ret = UPNP_E_INVALID_DESC;
        goto error_handler;
    }
    SetServiceTable( TV_SERVICE_PICTURE, udn, servid_pict,
                     TvServiceType[TV_SERVICE_PICTURE],
                     &tv_service_table[TV_SERVICE_PICTURE] );

  error_handler:

    if( udn )
        free( udn );
    if( servid_ctrl )
        free( servid_ctrl );
    if( evnturl_ctrl )
        free( evnturl_ctrl );
    if( ctrlurl_ctrl )
        free( ctrlurl_ctrl );
    if( servid_pict )
        free( servid_pict );
    if( evnturl_pict )
        free( evnturl_pict );
    if( ctrlurl_pict )
        free( ctrlurl_pict );
    if( DescDoc )
        ixmlDocument_free( DescDoc );

    return ( ret );
}


int
TvDeviceHandleSubscriptionRequest( IN struct Upnp_Subscription_Request
                                   *sr_event )
{
    unsigned int i = 0;         


    ithread_mutex_lock( &TVDevMutex );

    for( i = 0; i < TV_SERVICE_SERVCOUNT; i++ ) {
        if( ( strcmp( sr_event->UDN, tv_service_table[i].UDN ) == 0 ) &&
            ( strcmp( sr_event->ServiceId, tv_service_table[i].ServiceId )
              == 0 ) ) {



            UpnpAcceptSubscription( device_handle,
                                    sr_event->UDN,
                                    sr_event->ServiceId,
                                    ( const char ** )tv_service_table[i].
                                    VariableName,
                                    ( const char ** )tv_service_table[i].
                                    VariableStrVal,
                                    tv_service_table[i].VariableCount,
                                    sr_event->Sid );

        }
    }

    ithread_mutex_unlock( &TVDevMutex );

    return ( 1 );
}


int
TvDeviceHandleGetVarRequest( INOUT struct Upnp_State_Var_Request
                             *cgv_event )
{
    unsigned int i = 0,
      j = 0;
    int getvar_succeeded = 0;

    cgv_event->CurrentVal = NULL;

    ithread_mutex_lock( &TVDevMutex );

    for( i = 0; i < TV_SERVICE_SERVCOUNT; i++ ) {
        if( ( strcmp( cgv_event->DevUDN, tv_service_table[i].UDN ) == 0 )
            &&
            ( strcmp( cgv_event->ServiceID, tv_service_table[i].ServiceId )
              == 0 ) ) {
            for( j = 0; j < tv_service_table[i].VariableCount; j++ ) {
                if( strcmp( cgv_event->StateVarName,
                            tv_service_table[i].VariableName[j] ) == 0 ) {
                    getvar_succeeded = 1;
                    cgv_event->CurrentVal =
                        ixmlCloneDOMString( tv_service_table[i].
                                            VariableStrVal[j] );
                    break;
                }
            }
        }
    }

    if( getvar_succeeded ) {
        cgv_event->ErrCode = UPNP_E_SUCCESS;
    } else {
        SampleUtil_Print
            ( "Error in UPNP_CONTROL_GET_VAR_REQUEST callback:\n" );
        SampleUtil_Print( "   Unknown variable name = %s\n",
                          cgv_event->StateVarName );
        cgv_event->ErrCode = 404;
        strcpy( cgv_event->ErrStr, "Invalid Variable" );
    }

    ithread_mutex_unlock( &TVDevMutex );

    return ( cgv_event->ErrCode == UPNP_E_SUCCESS );
}


int
TvDeviceHandleActionRequest( INOUT struct Upnp_Action_Request *ca_event )
{


    int action_found = 0;
    int i = 0;
    int service = -1;
    int retCode = 0;
    char *errorString = NULL;

    ca_event->ErrCode = 0;
    ca_event->ActionResult = NULL;

    if( ( strcmp( ca_event->DevUDN,
                  tv_service_table[TV_SERVICE_CONTROL].UDN ) == 0 ) &&
        ( strcmp
          ( ca_event->ServiceID,
            tv_service_table[TV_SERVICE_CONTROL].ServiceId ) == 0 ) ) {

        service = TV_SERVICE_CONTROL;
    } else if( ( strcmp( ca_event->DevUDN,
                         tv_service_table[TV_SERVICE_PICTURE].UDN ) == 0 )
               &&
               ( strcmp
                 ( ca_event->ServiceID,
                   tv_service_table[TV_SERVICE_PICTURE].ServiceId ) ==
                 0 ) ) {

        service = TV_SERVICE_PICTURE;
    }

    for( i = 0; ( ( i < TV_MAXACTIONS ) &&
                  ( tv_service_table[service].ActionNames[i] != NULL ) );
         i++ ) {

        if( !strcmp( ca_event->ActionName,
                     tv_service_table[service].ActionNames[i] ) ) {

            if( ( !strcmp( tv_service_table[TV_SERVICE_CONTROL].
                           VariableStrVal[TV_CONTROL_POWER], "1" ) )
                || ( !strcmp( ca_event->ActionName, "PowerOn" ) ) ) {
                retCode =
                    tv_service_table[service].actions[i] ( ca_event->
                                                           ActionRequest,
                                                           &ca_event->
                                                           ActionResult,
                                                           &errorString );
            } else {
                errorString = "Power is Off";
                retCode = UPNP_E_INTERNAL_ERROR;
            }
            action_found = 1;
            break;
        }
    }

    if( !action_found ) {
        ca_event->ActionResult = NULL;
        strcpy( ca_event->ErrStr, "Invalid Action" );
        ca_event->ErrCode = 401;
    } else {
        if( retCode == UPNP_E_SUCCESS ) {
            ca_event->ErrCode = UPNP_E_SUCCESS;
        } else {
            strcpy( ca_event->ErrStr, errorString );
            switch ( retCode ) {
                case UPNP_E_INVALID_PARAM:
                    {
                        ca_event->ErrCode = 402;
                        break;
                    }
                case UPNP_E_INTERNAL_ERROR:
                default:
                    {
                        ca_event->ErrCode = 501;
                        break;
                    }

            }
        }
    }

    return ( ca_event->ErrCode );
}


int
TvDeviceSetServiceTableVar( IN unsigned int service,
                            IN unsigned int variable,
                            IN char *value )
{

    if( ( service >= TV_SERVICE_SERVCOUNT )
        || ( variable >= tv_service_table[service].VariableCount )
        || ( strlen( value ) >= TV_MAX_VAL_LEN ) ) {
        return ( 0 );
    }

    ithread_mutex_lock( &TVDevMutex );

    strcpy( tv_service_table[service].VariableStrVal[variable], value );



    UpnpNotify( device_handle,
                tv_service_table[service].UDN,
                tv_service_table[service].ServiceId,
                ( const char ** )&tv_service_table[service].
                VariableName[variable],
                ( const char ** )&tv_service_table[service].
                VariableStrVal[variable], 1 );

    ithread_mutex_unlock( &TVDevMutex );

    return ( 1 );

}


int
TvDeviceSetPower( IN int on )
{
    char value[TV_MAX_VAL_LEN];
    int ret = 0;

    if( on != POWER_ON && on != POWER_OFF ) {
        SampleUtil_Print( "error: can't set power to value %d\n", on );
        return ( 0 );
    }



    sprintf( value, "%d", on );
    ret = TvDeviceSetServiceTableVar( TV_SERVICE_CONTROL, TV_CONTROL_POWER,
                                      value );

    return ( ret );
}


int
TvDevicePowerOn( IN IXML_Document * in,
                 OUT IXML_Document ** out,
                 OUT char **errorString )
{
    ( *out ) = NULL;
    ( *errorString ) = NULL;

    if( TvDeviceSetPower( POWER_ON ) ) {

        if( UpnpAddToActionResponse( out, "PowerOn",
                                     TvServiceType[TV_SERVICE_CONTROL],
                                     "Power", "1" ) != UPNP_E_SUCCESS ) {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            return UPNP_E_INTERNAL_ERROR;
        }
        return UPNP_E_SUCCESS;
    } else {
        ( *errorString ) = "Internal Error";
        return UPNP_E_INTERNAL_ERROR;
    }

}


int
TvDevicePowerOff( IN IXML_Document * in,
                  OUT IXML_Document ** out,
                  OUT char **errorString )
{
    ( *out ) = NULL;
    ( *errorString ) = NULL;
    if( TvDeviceSetPower( POWER_OFF ) ) {

        if( UpnpAddToActionResponse( out, "PowerOff",
                                     TvServiceType[TV_SERVICE_CONTROL],
                                     "Power", "0" ) != UPNP_E_SUCCESS ) {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            return UPNP_E_INTERNAL_ERROR;
        }

        return UPNP_E_SUCCESS;
    }

    ( *errorString ) = "Internal Error";
    return UPNP_E_INTERNAL_ERROR;
}


int
TvDeviceSetChannel( IN IXML_Document * in,
                    OUT IXML_Document ** out,
                    OUT char **errorString )
{

    char *value = NULL;

    int channel = 0;

    ( *out ) = NULL;
    ( *errorString ) = NULL;

    if( !( value = SampleUtil_GetFirstDocumentItem( in, "Channel" ) ) ) {
        ( *errorString ) = "Invalid Channel";
        return UPNP_E_INVALID_PARAM;
    }

    channel = atoi( value );

    if( channel < MIN_CHANNEL || channel > MAX_CHANNEL ) {

        free( value );
        SampleUtil_Print( "error: can't change to channel %d\n", channel );
        ( *errorString ) = "Invalid Channel";
        return UPNP_E_INVALID_PARAM;
    }



    if( TvDeviceSetServiceTableVar( TV_SERVICE_CONTROL,
                                    TV_CONTROL_CHANNEL, value ) ) {
        if( UpnpAddToActionResponse( out, "SetChannel",
                                     TvServiceType[TV_SERVICE_CONTROL],
                                     "NewChannel",
                                     value ) != UPNP_E_SUCCESS ) {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            free( value );
            return UPNP_E_INTERNAL_ERROR;
        }
        free( value );
        return UPNP_E_SUCCESS;
    } else {
        free( value );
        ( *errorString ) = "Internal Error";
        return UPNP_E_INTERNAL_ERROR;
    }

}


int
IncrementChannel( IN int incr,
                  IN IXML_Document * in,
                  OUT IXML_Document ** out,
                  OUT char **errorString )
{
    int curchannel,
      newchannel;

    char *actionName = NULL;
    char value[TV_MAX_VAL_LEN];

    if( incr > 0 ) {
        actionName = "IncreaseChannel";
    } else {
        actionName = "DecreaseChannel";
    }

    ithread_mutex_lock( &TVDevMutex );
    curchannel = atoi( tv_service_table[TV_SERVICE_CONTROL].
                       VariableStrVal[TV_CONTROL_CHANNEL] );
    ithread_mutex_unlock( &TVDevMutex );

    newchannel = curchannel + incr;

    if( newchannel < MIN_CHANNEL || newchannel > MAX_CHANNEL ) {
        SampleUtil_Print( "error: can't change to channel %d\n",
                          newchannel );
        ( *errorString ) = "Invalid Channel";
        return UPNP_E_INVALID_PARAM;
    }



    sprintf( value, "%d", newchannel );

    if( TvDeviceSetServiceTableVar( TV_SERVICE_CONTROL,
                                    TV_CONTROL_CHANNEL, value ) ) {
        if( UpnpAddToActionResponse( out, actionName,
                                     TvServiceType[TV_SERVICE_CONTROL],
                                     "Channel", value ) != UPNP_E_SUCCESS )
        {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            return UPNP_E_INTERNAL_ERROR;
        }
        return UPNP_E_SUCCESS;
    } else {
        ( *errorString ) = "Internal Error";
        return UPNP_E_INTERNAL_ERROR;
    }
}


int
TvDeviceDecreaseChannel( IN IXML_Document * in,
                         OUT IXML_Document ** out,
                         OUT char **errorString )
{
    return IncrementChannel( -1, in, out, errorString );

}


int
TvDeviceIncreaseChannel( IN IXML_Document * in,
                         OUT IXML_Document ** out,
                         OUT char **errorString )
{
    return IncrementChannel( 1, in, out, errorString );

}


int
TvDeviceSetVolume( IN IXML_Document * in,
                   OUT IXML_Document ** out,
                   OUT char **errorString )
{

    char *value = NULL;

    int volume = 0;

    ( *out ) = NULL;
    ( *errorString ) = NULL;

    if( !( value = SampleUtil_GetFirstDocumentItem( in, "Volume" ) ) ) {
        ( *errorString ) = "Invalid Volume";
        return UPNP_E_INVALID_PARAM;
    }

    volume = atoi( value );

    if( volume < MIN_VOLUME || volume > MAX_VOLUME ) {
        SampleUtil_Print( "error: can't change to volume %d\n", volume );
        ( *errorString ) = "Invalid Volume";
        return UPNP_E_INVALID_PARAM;
    }



    if( TvDeviceSetServiceTableVar( TV_SERVICE_CONTROL,
                                    TV_CONTROL_VOLUME, value ) ) {
        if( UpnpAddToActionResponse( out, "SetVolume",
                                     TvServiceType[TV_SERVICE_CONTROL],
                                     "NewVolume",
                                     value ) != UPNP_E_SUCCESS ) {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            free( value );
            return UPNP_E_INTERNAL_ERROR;
        }
        free( value );
        return UPNP_E_SUCCESS;
    } else {
        free( value );
        ( *errorString ) = "Internal Error";
        return UPNP_E_INTERNAL_ERROR;
    }

}


int
IncrementVolume( IN int incr,
                 IN IXML_Document * in,
                 OUT IXML_Document ** out,
                 OUT char **errorString )
{
    int curvolume,
      newvolume;
    char *actionName = NULL;
    char value[TV_MAX_VAL_LEN];

    if( incr > 0 ) {
        actionName = "IncreaseVolume";
    } else {
        actionName = "DecreaseVolume";
    }

    ithread_mutex_lock( &TVDevMutex );
    curvolume = atoi( tv_service_table[TV_SERVICE_CONTROL].
                      VariableStrVal[TV_CONTROL_VOLUME] );
    ithread_mutex_unlock( &TVDevMutex );

    newvolume = curvolume + incr;

    if( newvolume < MIN_VOLUME || newvolume > MAX_VOLUME ) {
        SampleUtil_Print( "error: can't change to volume %d\n",
                          newvolume );
        ( *errorString ) = "Invalid Volume";
        return UPNP_E_INVALID_PARAM;
    }



    sprintf( value, "%d", newvolume );

    if( TvDeviceSetServiceTableVar( TV_SERVICE_CONTROL,
                                    TV_CONTROL_VOLUME, value ) ) {
        if( UpnpAddToActionResponse( out, actionName,
                                     TvServiceType[TV_SERVICE_CONTROL],
                                     "Volume", value ) != UPNP_E_SUCCESS )
        {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            return UPNP_E_INTERNAL_ERROR;
        }
        return UPNP_E_SUCCESS;
    } else {
        ( *errorString ) = "Internal Error";
        return UPNP_E_INTERNAL_ERROR;
    }

}


int
TvDeviceIncreaseVolume( IN IXML_Document * in,
                        OUT IXML_Document ** out,
                        OUT char **errorString )
{

    return IncrementVolume( 1, in, out, errorString );

}


int
TvDeviceDecreaseVolume( IN IXML_Document * in,
                        OUT IXML_Document ** out,
                        OUT char **errorString )
{

    return IncrementVolume( -1, in, out, errorString );

}


int
TvDeviceSetColor( IN IXML_Document * in,
                  OUT IXML_Document ** out,
                  OUT char **errorString )
{

    char *value = NULL;

    int color = 0;

    ( *out ) = NULL;
    ( *errorString ) = NULL;
    if( !( value = SampleUtil_GetFirstDocumentItem( in, "Color" ) ) ) {
        ( *errorString ) = "Invalid Color";
        return UPNP_E_INVALID_PARAM;
    }

    color = atoi( value );

    if( color < MIN_COLOR || color > MAX_COLOR ) {
        SampleUtil_Print( "error: can't change to color %d\n", color );
        ( *errorString ) = "Invalid Color";
        return UPNP_E_INVALID_PARAM;
    }



    if( TvDeviceSetServiceTableVar( TV_SERVICE_PICTURE,
                                    TV_PICTURE_COLOR, value ) ) {
        if( UpnpAddToActionResponse( out, "SetColor",
                                     TvServiceType[TV_SERVICE_PICTURE],
                                     "NewColor",
                                     value ) != UPNP_E_SUCCESS ) {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            free( value );
            return UPNP_E_INTERNAL_ERROR;
        }
        free( value );
        return UPNP_E_SUCCESS;
    } else {
        free( value );
        ( *errorString ) = "Internal Error";
        return UPNP_E_INTERNAL_ERROR;
    }

}



int
IncrementColor( IN int incr,
                IN IXML_Document * in,
                OUT IXML_Document ** out,
                OUT char **errorString )
{
    int curcolor,
      newcolor;

    char *actionName;
    char value[TV_MAX_VAL_LEN];

    if( incr > 0 ) {
        actionName = "IncreaseColor";
    } else {
        actionName = "DecreaseColor";
    }

    ithread_mutex_lock( &TVDevMutex );
    curcolor = atoi( tv_service_table[TV_SERVICE_PICTURE].
                     VariableStrVal[TV_PICTURE_COLOR] );
    ithread_mutex_unlock( &TVDevMutex );

    newcolor = curcolor + incr;

    if( newcolor < MIN_COLOR || newcolor > MAX_COLOR ) {
        SampleUtil_Print( "error: can't change to color %d\n", newcolor );
        ( *errorString ) = "Invalid Color";
        return UPNP_E_INVALID_PARAM;
    }



    sprintf( value, "%d", newcolor );

    if( TvDeviceSetServiceTableVar( TV_SERVICE_PICTURE,
                                    TV_PICTURE_COLOR, value ) ) {
        if( UpnpAddToActionResponse( out, actionName,
                                     TvServiceType[TV_SERVICE_PICTURE],
                                     "Color", value ) != UPNP_E_SUCCESS ) {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            return UPNP_E_INTERNAL_ERROR;
        }
        return UPNP_E_SUCCESS;
    } else {
        ( *errorString ) = "Internal Error";
        return UPNP_E_INTERNAL_ERROR;
    }
}


int
TvDeviceDecreaseColor( IN IXML_Document * in,
                       OUT IXML_Document ** out,
                       OUT char **errorString )
{

    return IncrementColor( -1, in, out, errorString );
}


int
TvDeviceIncreaseColor( IN IXML_Document * in,
                       OUT IXML_Document ** out,
                       OUT char **errorString )
{

    return IncrementColor( 1, in, out, errorString );
}


int
TvDeviceSetTint( IN IXML_Document * in,
                 OUT IXML_Document ** out,
                 OUT char **errorString )
{

    char *value = NULL;

    int tint = -1;

    ( *out ) = NULL;
    ( *errorString ) = NULL;

    if( !( value = SampleUtil_GetFirstDocumentItem( in, "Tint" ) ) ) {
        ( *errorString ) = "Invalid Tint";
        return UPNP_E_INVALID_PARAM;
    }

    tint = atoi( value );

    if( tint < MIN_TINT || tint > MAX_TINT ) {
        SampleUtil_Print( "error: can't change to tint %d\n", tint );
        ( *errorString ) = "Invalid Tint";
        return UPNP_E_INVALID_PARAM;
    }



    if( TvDeviceSetServiceTableVar( TV_SERVICE_PICTURE,
                                    TV_PICTURE_TINT, value ) ) {
        if( UpnpAddToActionResponse( out, "SetTint",
                                     TvServiceType[TV_SERVICE_PICTURE],
                                     "NewTint", value ) != UPNP_E_SUCCESS )
        {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            free( value );
            return UPNP_E_INTERNAL_ERROR;
        }
        free( value );
        return UPNP_E_SUCCESS;
    } else {
        free( value );
        ( *errorString ) = "Internal Error";
        return UPNP_E_INTERNAL_ERROR;
    }

}


int
IncrementTint( IN int incr,
               IN IXML_Document * in,
               OUT IXML_Document ** out,
               OUT char **errorString )
{
    int curtint,
      newtint;

    char *actionName = NULL;
    char value[TV_MAX_VAL_LEN];

    if( incr > 0 ) {
        actionName = "IncreaseTint";
    } else {
        actionName = "DecreaseTint";
    }

    ithread_mutex_lock( &TVDevMutex );
    curtint = atoi( tv_service_table[TV_SERVICE_PICTURE].
                    VariableStrVal[TV_PICTURE_TINT] );
    ithread_mutex_unlock( &TVDevMutex );

    newtint = curtint + incr;

    if( newtint < MIN_TINT || newtint > MAX_TINT ) {
        SampleUtil_Print( "error: can't change to tint %d\n", newtint );
        ( *errorString ) = "Invalid Tint";
        return UPNP_E_INVALID_PARAM;
    }



    sprintf( value, "%d", newtint );

    if( TvDeviceSetServiceTableVar( TV_SERVICE_PICTURE,
                                    TV_PICTURE_TINT, value ) ) {
        if( UpnpAddToActionResponse( out, actionName,
                                     TvServiceType[TV_SERVICE_PICTURE],
                                     "Tint", value ) != UPNP_E_SUCCESS ) {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            return UPNP_E_INTERNAL_ERROR;
        }
        return UPNP_E_SUCCESS;
    } else {
        ( *errorString ) = "Internal Error";
        return UPNP_E_INTERNAL_ERROR;
    }

}


int
TvDeviceIncreaseTint( IN IXML_Document * in,
                      OUT IXML_Document ** out,
                      OUT char **errorString )
{

    return IncrementTint( 1, in, out, errorString );
}


int
TvDeviceDecreaseTint( IN IXML_Document * in,
                      OUT IXML_Document ** out,
                      OUT char **errorString )
{

    return IncrementTint( -1, in, out, errorString );
}


int
TvDeviceSetContrast( IN IXML_Document * in,
                     OUT IXML_Document ** out,
                     OUT char **errorString )
{

    char *value = NULL;
    int contrast = -1;

    ( *out ) = NULL;
    ( *errorString ) = NULL;

    if( !( value = SampleUtil_GetFirstDocumentItem( in, "Contrast" ) ) ) {
        ( *errorString ) = "Invalid Contrast";
        return UPNP_E_INVALID_PARAM;
    }

    contrast = atoi( value );

    if( contrast < MIN_CONTRAST || contrast > MAX_CONTRAST ) {
        SampleUtil_Print( "error: can't change to contrast %d\n",
                          contrast );
        ( *errorString ) = "Invalid Contrast";
        return UPNP_E_INVALID_PARAM;
    }



    if( TvDeviceSetServiceTableVar( TV_SERVICE_PICTURE,
                                    TV_PICTURE_CONTRAST, value ) ) {
        if( UpnpAddToActionResponse( out, "SetContrast",
                                     TvServiceType[TV_SERVICE_PICTURE],
                                     "NewContrast",
                                     value ) != UPNP_E_SUCCESS ) {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            free( value );
            return UPNP_E_INTERNAL_ERROR;
        }
        free( value );
        return UPNP_E_SUCCESS;
    } else {
        free( value );
        ( *errorString ) = "Internal Error";
        return UPNP_E_INTERNAL_ERROR;
    }

}


int
IncrementContrast( IN int incr,
                   IN IXML_Document * in,
                   OUT IXML_Document ** out,
                   OUT char **errorString )
{
    int curcontrast,
      newcontrast;

    char *actionName = NULL;
    char value[TV_MAX_VAL_LEN];

    if( incr > 0 ) {
        actionName = "IncreaseContrast";
    } else {
        actionName = "DecreaseContrast";
    }

    ithread_mutex_lock( &TVDevMutex );
    curcontrast = atoi( tv_service_table[TV_SERVICE_PICTURE].
                        VariableStrVal[TV_PICTURE_CONTRAST] );
    ithread_mutex_unlock( &TVDevMutex );

    newcontrast = curcontrast + incr;

    if( newcontrast < MIN_CONTRAST || newcontrast > MAX_CONTRAST ) {
        SampleUtil_Print( "error: can't change to contrast %d\n",
                          newcontrast );
        ( *errorString ) = "Invalid Contrast";
        return UPNP_E_INVALID_PARAM;
    }



    sprintf( value, "%d", newcontrast );

    if( TvDeviceSetServiceTableVar( TV_SERVICE_PICTURE,
                                    TV_PICTURE_CONTRAST, value ) ) {
        if( UpnpAddToActionResponse( out, actionName,
                                     TvServiceType[TV_SERVICE_PICTURE],
                                     "Contrast",
                                     value ) != UPNP_E_SUCCESS ) {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            return UPNP_E_INTERNAL_ERROR;
        }
        return UPNP_E_SUCCESS;
    } else {
        ( *errorString ) = "Internal Error";
        return UPNP_E_INTERNAL_ERROR;
    }
}


int
TvDeviceIncreaseContrast( IN IXML_Document * in,
                          OUT IXML_Document ** out,
                          OUT char **errorString )
{

    return IncrementContrast( 1, in, out, errorString );
}


int
TvDeviceDecreaseContrast( IXML_Document * in,
                          IXML_Document ** out,
                          char **errorString )
{
    return IncrementContrast( -1, in, out, errorString );
}


int
TvDeviceSetBrightness( IN IXML_Document * in,
                       OUT IXML_Document ** out,
                       OUT char **errorString )
{

    char *value = NULL;
    int brightness = -1;

    ( *out ) = NULL;
    ( *errorString ) = NULL;

    if( !( value = SampleUtil_GetFirstDocumentItem( in, "Brightness" ) ) ) {
        ( *errorString ) = "Invalid Brightness";
        return UPNP_E_INVALID_PARAM;
    }

    brightness = atoi( value );

    if( brightness < MIN_BRIGHTNESS || brightness > MAX_BRIGHTNESS ) {
        SampleUtil_Print( "error: can't change to brightness %d\n",
                          brightness );
        ( *errorString ) = "Invalid Brightness";
        return UPNP_E_INVALID_PARAM;
    }



    if( TvDeviceSetServiceTableVar( TV_SERVICE_PICTURE,
                                    TV_PICTURE_BRIGHTNESS, value ) ) {
        if( UpnpAddToActionResponse( out, "SetBrightness",
                                     TvServiceType[TV_SERVICE_PICTURE],
                                     "NewBrightness",
                                     value ) != UPNP_E_SUCCESS ) {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            free( value );
            return UPNP_E_INTERNAL_ERROR;
        }
        free( value );
        return UPNP_E_SUCCESS;
    } else {
        free( value );
        ( *errorString ) = "Internal Error";
        return UPNP_E_INTERNAL_ERROR;
    }

}


int
IncrementBrightness( IN int incr,
                     IN IXML_Document * in,
                     OUT IXML_Document ** out,
                     OUT char **errorString )
{
    int curbrightness,
      newbrightness;
    char *actionName = NULL;
    char value[TV_MAX_VAL_LEN];

    if( incr > 0 ) {
        actionName = "IncreaseBrightness";
    } else {
        actionName = "DecreaseBrightness";
    }

    ithread_mutex_lock( &TVDevMutex );
    curbrightness = atoi( tv_service_table[TV_SERVICE_PICTURE].
                          VariableStrVal[TV_PICTURE_BRIGHTNESS] );
    ithread_mutex_unlock( &TVDevMutex );

    newbrightness = curbrightness + incr;

    if( newbrightness < MIN_BRIGHTNESS || newbrightness > MAX_BRIGHTNESS ) {
        SampleUtil_Print( "error: can't change to brightness %d\n",
                          newbrightness );
        ( *errorString ) = "Invalid Brightness";
        return UPNP_E_INVALID_PARAM;
    }



    sprintf( value, "%d", newbrightness );

    if( TvDeviceSetServiceTableVar( TV_SERVICE_PICTURE,
                                    TV_PICTURE_BRIGHTNESS, value ) ) {
        if( UpnpAddToActionResponse( out, actionName,
                                     TvServiceType[TV_SERVICE_PICTURE],
                                     "Brightness",
                                     value ) != UPNP_E_SUCCESS ) {
            ( *out ) = NULL;
            ( *errorString ) = "Internal Error";
            return UPNP_E_INTERNAL_ERROR;
        }
        return UPNP_E_SUCCESS;
    } else {
        ( *errorString ) = "Internal Error";
        return UPNP_E_INTERNAL_ERROR;
    }
}


int
TvDeviceIncreaseBrightness( IN IXML_Document * in,
                            OUT IXML_Document ** out,
                            OUT char **errorString )
{
    return IncrementBrightness( 1, in, out, errorString );
}


int
TvDeviceDecreaseBrightness( IN IXML_Document * in,
                            OUT IXML_Document ** out,
                            OUT char **errorString )
{
    return IncrementBrightness( -1, in, out, errorString );
}


int
TvDeviceCallbackEventHandler( Upnp_EventType EventType,
                              void *Event,
                              void *Cookie )
{

    switch ( EventType ) {

        case UPNP_EVENT_SUBSCRIPTION_REQUEST:

            TvDeviceHandleSubscriptionRequest( ( struct
                                                 Upnp_Subscription_Request
                                                 * )Event );
            break;

        case UPNP_CONTROL_GET_VAR_REQUEST:
            TvDeviceHandleGetVarRequest( ( struct Upnp_State_Var_Request
                                           * )Event );
            break;

        case UPNP_CONTROL_ACTION_REQUEST:
            TvDeviceHandleActionRequest( ( struct Upnp_Action_Request * )
                                         Event );
            break;


        case UPNP_DISCOVERY_ADVERTISEMENT_ALIVE:
        case UPNP_DISCOVERY_SEARCH_RESULT:
        case UPNP_DISCOVERY_SEARCH_TIMEOUT:
        case UPNP_DISCOVERY_ADVERTISEMENT_BYEBYE:
        case UPNP_CONTROL_ACTION_COMPLETE:
        case UPNP_CONTROL_GET_VAR_COMPLETE:
        case UPNP_EVENT_RECEIVED:
        case UPNP_EVENT_RENEWAL_COMPLETE:
        case UPNP_EVENT_SUBSCRIBE_COMPLETE:
        case UPNP_EVENT_UNSUBSCRIBE_COMPLETE:
            break;

        default:
            SampleUtil_Print
                ( "Error in TvDeviceCallbackEventHandler: unknown event type %d\n",
                  EventType );
    }


    SampleUtil_PrintEvent( EventType, Event );

    return ( 0 );
}


int
TvDeviceStop(  )
{
    UpnpUnRegisterRootDevice( device_handle );
    UpnpFinish(  );
    SampleUtil_Finish(  );
    ithread_mutex_destroy( &TVDevMutex );
    return UPNP_E_SUCCESS;
}


int
TvDeviceStart( char *ip_address,
               unsigned short port,
               char *desc_doc_name,
               char *web_dir_path,
               print_string pfun )
{
    int ret = UPNP_E_SUCCESS;

    char desc_doc_url[DESC_URL_SIZE];
    char desc_doc_sample_path[DESC_URL_SIZE];
    char desc_doc_path[DESC_URL_SIZE];
    
    FILE	*xml_description, *xml_description_sample;
	int		dw_filesize=0, i;
    char	*file_buff, *buildfile_buff;
    
    IXML_NodeList *baseList;
    IXML_Node *textNode = NULL;
    IXML_Node *fname_node = NULL;   
    
    unsigned char *mac_address;
    char mac_address_str[32];
    char SMC_FNAME[FNAME_SIZE];

	memset( mac_address_str, 0, 32);
	
    ithread_mutex_init( &TVDevMutex, NULL );

    SampleUtil_Initialize( pfun );

    SampleUtil_Print
        ( "Initializing UPnP Sdk with \n \t ipaddress = %s port = %d\n",
          ip_address, port );

    if( ( ret = UpnpInit( ip_address, port ) ) != UPNP_E_SUCCESS ) {
        SampleUtil_Print( "Error with UpnpInit -- %d\n", ret );
        UpnpFinish(  );
        return ret;
    }

    if( ip_address == NULL ) {
        ip_address = UpnpGetServerIpAddress(  );
    }

    if( port == 0 ) {
        port = UpnpGetServerPort(  );
    }
    
    mac_address = UpnpGetServerMacAddress(  );
    snprintf(mac_address_str, sizeof(mac_address_str), "%x:%x:%x:%x:%x:%x", 
    		*mac_address, *(mac_address+1), *(mac_address+2), *(mac_address+3), *(mac_address+4), *(mac_address+5));
    

    SampleUtil_Print( "UPnP Initialized\n \t ipaddress= %s port = %d mac_address= %s\n",
                      ip_address, port, mac_address_str);

    if( desc_doc_name == NULL )
        desc_doc_name = "tvdevicedesc.xml";

    if( web_dir_path == NULL )
        web_dir_path = DEFAULT_WEB_DIR;

	snprintf( SMC_FNAME, sizeof(SMC_FNAME), "%s_%s", "SMCI", mac_address_str );
	snprintf( desc_doc_path, DESC_URL_SIZE, "%s/%s", web_dir_path, desc_doc_name );
	snprintf( desc_doc_sample_path, DESC_URL_SIZE, "%s/%s", web_dir_path, DEFAULT_DESC_SAMPLE_FILE );
	
	xml_description = fopen(desc_doc_path, "w+");
	xml_description_sample = fopen(desc_doc_sample_path, "r");
	
	while( fgetc(xml_description_sample) != EOF )
		dw_filesize++;
	file_buff = (unsigned char *) malloc(dw_filesize + FNAME_SIZE);
	buildfile_buff = (unsigned char *) malloc(dw_filesize + FNAME_SIZE);
	
	fseek(xml_description_sample, 0, SEEK_SET);

	for(i=0; i<dw_filesize; i++)
		file_buff[i] = fgetc(xml_description_sample);
				
	sprintf(buildfile_buff, file_buff, SMC_FNAME);
	fputs(buildfile_buff, xml_description);
	free(file_buff);
	free(buildfile_buff);
	fclose(xml_description_sample);
	fclose(xml_description);

    snprintf( desc_doc_url, DESC_URL_SIZE, "http://%s:%d/%s", ip_address,
              port, desc_doc_name );

    SampleUtil_Print( "Specifying the webserver root directory -- %s\n",
                      web_dir_path );
    if( ( ret =
          UpnpSetWebServerRootDir( web_dir_path ) ) != UPNP_E_SUCCESS ) {
        SampleUtil_Print
            ( "Error specifying webserver root directory -- %s: %d\n",
              web_dir_path, ret );
        UpnpFinish(  );
        return ret;
    }

    SampleUtil_Print
        ( "Registering the RootDevice\n\t with desc_doc_url: %s\n",
          desc_doc_url );

    if( ( ret = UpnpRegisterRootDevice( desc_doc_url,
                                        TvDeviceCallbackEventHandler,
                                        &device_handle, &device_handle ) )
        != UPNP_E_SUCCESS ) {
        SampleUtil_Print( "Error registering the rootdevice : %d\n", ret );
        UpnpFinish(  );
        return ret;
    } else {
        SampleUtil_Print( "RootDevice Registered\n" );

        SampleUtil_Print( "Initializing State Table\n" );
        TvDeviceStateTableInit( desc_doc_url );
        SampleUtil_Print( "State Table Initialized\n" );

        if( ( ret =
              UpnpSendAdvertisement( device_handle, 0 ) )
            != UPNP_E_SUCCESS ) {
            SampleUtil_Print( "Error sending advertisements : %d\n", ret );
            UpnpFinish(  );
            return ret;
        }

        SampleUtil_Print( "Advertisements Sent\n" );
    }
    return UPNP_E_SUCCESS;
}
