
#include <stdio.h>
#include "../inc/sample_util.h"
#include "../inc/upnp_IPMI_device.h"

#define	DEFAULT_DESC_FILE		"IPMIdevicedesc.xml"
#define	DEFAULT_DESC_FILE_PATH	"/nv"




void
linux_print( const char *string )
{
    printf( "%s", string );
}


void *
TvDeviceCommandLoop( void *args )
{
    int stoploop = 0;
    char cmdline[100];
    char cmd[100];

    while( !stoploop ) {
        sprintf( cmdline, " " );
        sprintf( cmd, " " );

        SampleUtil_Print( "\n>> " );

        fgets( cmdline, 100, stdin );

        sscanf( cmdline, "%s", cmd );

        if( strcasecmp( cmd, "exit" ) == 0 ) {
            SampleUtil_Print( "Shutting down...\n" );
            TvDeviceStop(  );
            exit( 0 );
        } else {
            SampleUtil_Print( "\n   Unknown command: %s\n\n", cmd );
            SampleUtil_Print( "   Valid Commands:\n" );
            SampleUtil_Print( "     Exit\n\n" );
        }

    }

    return NULL;
}


int
main( IN int argc,
      IN char **argv )
{

    //unsigned int portTemp = 0;
    //char *ip_address = NULL,
     char *desc_doc_name = NULL,
     *web_dir_path = NULL;
    //ithread_t cmdloop_thread;
    //int code, rc;
    //unsigned int port = 0;
    int sig;
    sigset_t sigs_to_catch;

    //int i = 0;

    SampleUtil_Initialize( linux_print );



	
	desc_doc_name = DEFAULT_DESC_FILE;
	web_dir_path  = DEFAULT_DESC_FILE_PATH;	
	

    TvDeviceStart( NULL, 0, desc_doc_name, web_dir_path,
                   linux_print );




    sigemptyset( &sigs_to_catch );
    sigaddset( &sigs_to_catch, SIGINT );
    sigwait( &sigs_to_catch, &sig );

    SampleUtil_Print( "Shutting down on signal %d...\n", sig );
    TvDeviceStop(  );
    exit(0);
}
