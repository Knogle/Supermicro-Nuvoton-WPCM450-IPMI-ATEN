
#ifndef _LDAT_CLIENT_C
#define _LDAT_CLIENT_C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./ldap.h"

int ldap_auth(char*ldapHost, int ldapPort, char*loginDN, char*password, 
			  char*searchBase, char* searchFilter, char** searchAttrs, int timeout, char* permissions,
			  int (* CallbackFunc)(char *),char *ResValue )
{   
    int         version, i, rc, entryCount;
    char        *attribute, *dn, **values,  *sortAttribute = "sn";       
    BerElement  *ber;
    LDAP        *ld;
    LDAPMessage *searchResult, *entry;
    struct timeval timeOut = {10,0};		

   	timeOut.tv_sec = timeout;
   
    if (!ldapHost || (strlen(ldapHost) == 0))	return 0;
    if (!ldapPort)								return 0;
    if (!loginDN || (strlen(loginDN) == 0))		return 0;

    version = LDAP_VERSION3;
    ldap_set_option( NULL, LDAP_OPT_PROTOCOL_VERSION, &version);
    ldap_set_option( NULL, LDAP_OPT_NETWORK_TIMEOUT, &timeOut);
	
#ifdef DEBUG
	int debug;
	if( ber_set_option( NULL, LBER_OPT_DEBUG_LEVEL, &debug )
			!= LBER_OPT_SUCCESS )
		{
			fprintf( stderr,
				"Could not set LBER_OPT_DEBUG_LEVEL %d\n", debug );
		}
	if( ldap_set_option( NULL, LDAP_OPT_DEBUG_LEVEL, &debug )
			!= LDAP_OPT_SUCCESS )
		{
			fprintf( stderr,
				"Could not set LDAP_OPT_DEBUG_LEVEL %d\n", debug );
		}
#endif

    if ((ld = ldap_init( ldapHost, ldapPort )) == NULL)
    {
#ifdef DEBUG    	
		printf("ldap_init fail\n");
#endif
        return 0;
    }

    rc = ldap_simple_bind_s( ld, loginDN, password );	
    if (rc != LDAP_SUCCESS )
    {
#ifdef DEBUG
		printf("ldap_simple_bind_s fail\n");
#endif
        ldap_unbind_s(ld);
        return 0;
    }

    rc = ldap_search_ext_s(ld, searchBase, 
					LDAP_SCOPE_SUBTREE, 
					searchFilter,			
					searchAttrs,			
                    0,						
                    NULL,					
                    NULL,					
                    &timeOut,				
                    LDAP_NO_LIMIT,			
                    &searchResult );		
    if ( rc != LDAP_SUCCESS ) 
    {
#ifdef DEBUG
		printf("ldap_search_ext_s fail\n");
#endif
        ldap_msgfree( searchResult );
        ldap_unbind_s( ld );
        return 0;
    }   
     
    ldap_sort_entries( ld, &searchResult, sortAttribute, strcmp ); 

    entryCount = ldap_count_entries( ld, searchResult );
    for (entry = ldap_first_entry( ld, searchResult ), i=0; 
    	 entry != NULL && i < entryCount; 
    	 entry = ldap_next_entry( ld, searchResult ), i++)
    {
        if (( dn = ldap_get_dn( ld, entry )) != NULL )            
        {
            ldap_memfree( dn );
        }
            
        for (   attribute = ldap_first_attribute( ld, entry, &ber );
                attribute != NULL; 
                attribute = ldap_next_attribute( ld, entry, ber ) ) 
        {   
            if (( values = ldap_get_values( ld, entry, attribute)) != NULL ) 
            {
                for ( i = 0; values[i] != NULL; i++ )
                {
                	if (permissions)
                		strcpy(permissions, values[i]);
                	
					if (CallbackFunc){
                		
						*ResValue = CallbackFunc(values[i]);
						if ( *ResValue > 0 )
							break;
					}
               	
                }
                ldap_value_free( values );
            }
            ldap_memfree( attribute );
        }
        ber_free(ber, 0);
    }
   
    ldap_msgfree( searchResult );
    ldap_unbind_s( ld );  
 
    return 1;
}
int ldap_auth_ssl(char*ldapHost, int ldapPort, char*loginDN, char*password, 
			  char*searchBase, char* searchFilter, char** searchAttrs, int timeout, char* permissions,
			  int (* CallbackFunc)(char *),char *ResValue)
{
    int         version, i, rc, entryCount;
    char        *attribute, *dn, **values,  *sortAttribute = "sn";       
    BerElement  *ber;
    LDAP        *ld = NULL;
    LDAPMessage *searchResult, *entry;
    struct		timeval timeOut = {10,0};   
	char ldapuri[128];
	
   	timeOut.tv_sec = timeout;
   
    if (!ldapHost || (strlen(ldapHost) == 0))	return 0;
    if (!ldapPort)								return 0;
    if (!loginDN || (strlen(loginDN) == 0))		return 0;
 
	
#ifdef DEBUG
	int debug;
	if( ber_set_option( NULL, LBER_OPT_DEBUG_LEVEL, &debug )
			!= LBER_OPT_SUCCESS )
		{
			fprintf( stderr,
				"Could not set LBER_OPT_DEBUG_LEVEL %d\n", debug );
		}
	if( ldap_set_option( NULL, LDAP_OPT_DEBUG_LEVEL, &debug )
			!= LDAP_OPT_SUCCESS )
		{
			fprintf( stderr,
				"Could not set LDAP_OPT_DEBUG_LEVEL %d\n", debug );
		}
#endif
		
    version = LDAP_VERSION3;
    if( ldap_set_option( NULL, LDAP_OPT_PROTOCOL_VERSION, &version )
			!= LDAP_OPT_SUCCESS )
	{
#ifdef DEBUG
		printf("ldap_set_option version fail\n");
#endif
        return 0;
	}
	
	sprintf(ldapuri, "ldaps://%s:%d", ldapHost,ldapPort);
    rc = ldap_initialize( &ld, ldapuri );
	if( rc != LDAP_SUCCESS )
    {
#ifdef DEBUG
		printf("ldap_initialize fail\n");
#endif
        return 0;
    }
	rc = ldap_simple_bind_s( ld, loginDN, password);
	if (rc != LDAP_SUCCESS )
	{
		char* str=ldap_err2string( rc );
#ifdef DEBUG
		printf("ldap_simple_bind_s fail, msg=%s,rc=%d\n",str, rc);
#endif
		ldap_unbind_s( ld );
		ldap_pvt_tls_destroy();
		return 0;
	}

    rc = ldap_search_ext_s(ld, searchBase, 
					LDAP_SCOPE_ONELEVEL,	
					searchFilter,			
					searchAttrs,			
                    0,						
                    NULL,					
                    NULL,					
                    &timeOut,				
                    LDAP_NO_LIMIT,			
                    &searchResult );		
    if ( rc != LDAP_SUCCESS ) 
    {
#ifdef DEBUG
		printf("ldap_search_ext_s fail\n");
#endif
        ldap_msgfree( searchResult );
        ldap_unbind_s( ld );
		ldap_pvt_tls_destroy();
        return 0;
    }   
     
    ldap_sort_entries( ld, &searchResult, sortAttribute, strcmp ); 
	
	entryCount = ldap_count_entries( ld, searchResult );
    for (entry = ldap_first_entry( ld, searchResult ), i=0; 
    	 entry != NULL && i < entryCount; 
    	 entry = ldap_next_entry( ld, searchResult ), i++)
    {
        if (( dn = ldap_get_dn( ld, entry )) != NULL )            
        {
            ldap_memfree( dn );
        }
            
        for (   attribute = ldap_first_attribute( ld, entry, &ber );
                attribute != NULL; 
                attribute = ldap_next_attribute( ld, entry, ber ) ) 
        {   
            if (( values = ldap_get_values( ld, entry, attribute)) != NULL ) 
            {
                for ( i = 0; values[i] != NULL; i++ )
                {
                	if (permissions)
                		strcpy(permissions, values[i]);
                		
					if (CallbackFunc) 
					{
						*ResValue = CallbackFunc(values[i]);
						if ( *ResValue > 0 )
							break;             	
					}
                }
                ldap_value_free( values );
            }
            ldap_memfree( attribute );
        }
        ber_free(ber, 0);
    }
   
    ldap_msgfree( searchResult );
    ldap_unbind_s( ld );
  
    ldap_pvt_tls_destroy();
	return 1;
}
int ldap_auth_by_manager(char*ldapHost, int ldapPort, char*password, 
			  			 char*searchBase, char* bindDN, char* bindPWD, char* searchFilter, 
			  			 char* searchAttrs, int timeout, char* permissions, char* errMsg)
{   
    int         version, i, rc, entryCount;
    char        *dn, **values;       
    LDAP        *ld, *ld_user;
    LDAPMessage *searchResult, *entry;
    struct timeval timeOut = {10,0};		

   	timeOut.tv_sec = timeout;
   
    if (!ldapHost || (strlen(ldapHost) == 0))	return 0;
    if (!ldapPort)								return 0;

    version = LDAP_VERSION3;
    ldap_set_option( NULL, LDAP_OPT_PROTOCOL_VERSION, &version);
    ldap_set_option( NULL, LDAP_OPT_NETWORK_TIMEOUT, &timeOut);

#ifdef DEBUG
		int debug;
	if( ber_set_option( NULL, LBER_OPT_DEBUG_LEVEL, &debug )
			!= LBER_OPT_SUCCESS )
		{
			fprintf( stderr,
				"Could not set LBER_OPT_DEBUG_LEVEL %d\n", debug );
		}
	if( ldap_set_option( NULL, LDAP_OPT_DEBUG_LEVEL, &debug )
			!= LDAP_OPT_SUCCESS )
		{
			fprintf( stderr,
				"Could not set LDAP_OPT_DEBUG_LEVEL %d\n", debug );
		}
#endif


    if ((ld = ldap_init( ldapHost, ldapPort )) == NULL)
    {
		sprintf(errMsg, "ldap_init fail\n");
        return 0;
    }
    rc = ldap_simple_bind_s( ld, bindDN, bindPWD );	
    if (rc != LDAP_SUCCESS )
    {
    	sprintf(errMsg, "bind dn=%s fail\n", bindDN);
        ldap_unbind_s(ld);
        return 0;
    }

    rc = ldap_search_ext_s(ld, searchBase, 
					LDAP_SCOPE_SUBTREE, 
					searchFilter,			
					NULL,	        
                    0,						
                    NULL,					
                    NULL,					
                    &timeOut,				
                    LDAP_NO_LIMIT,			
                    &searchResult );		
             
	if ( rc != LDAP_SUCCESS ) 
	{
		sprintf(errMsg, "ldap_search_ext_s fail\n");
        ldap_msgfree( searchResult );
        ldap_unbind_s( ld );
        return 0;
    }   
    
    entryCount = ldap_count_entries( ld, searchResult );
    for (entry = ldap_first_entry( ld, searchResult ), i=0; 
    	 entry != NULL && i < entryCount; 
    	 entry = ldap_next_entry( ld, searchResult ), i++)
   	{
	    if (( values = ldap_get_values( ld, entry, searchAttrs)) != NULL ) 
	    {	   
	        strcpy(permissions, values[0]);	        
	        ldap_value_free( values );
	    } 
		else
		{
			continue;
		}
		dn = ldap_get_dn( ld, entry );
	    if ( dn != NULL )            
	    {   	    	

		    if ((ld_user = ldap_init( ldapHost, ldapPort )) == NULL)
		    {
				sprintf(errMsg, "ldap_init fail\n");		
				ldap_memfree( dn );
				ldap_msgfree( searchResult );
	    		ldap_unbind_s(ld);
		        return 0;
		    }	
		    rc = ldap_simple_bind_s( ld_user, dn, password );	
		    if (rc == LDAP_SUCCESS )
		    {
		        ldap_unbind_s(ld_user);
	    		ldap_memfree(dn); 
	    		ldap_msgfree( searchResult );
	    		ldap_unbind_s(ld);
		        return 1;
		    } 
		    ldap_unbind_s(ld_user);
	    	ldap_memfree(dn); 
	    }  
	}
	sprintf(errMsg, "LDAP: user not found\n");
	ldap_msgfree( searchResult );
	ldap_unbind_s(ld);  
  	return 0;
}
int ldap_auth_ssl_by_manager(char*ldapHost, int ldapPort, char*password, 
			     		     char*searchBase, char* bindDN, char* bindPWD, char* searchFilter, 
			      			 char* searchAttrs, int timeout, char* permissions, char* errMsg)
{
    int         version, i, rc, entryCount;
    char        *attribute, *dn, **values,  *sortAttribute = "sn";       
    BerElement  *ber;
    LDAP        *ld = NULL, *ld_user=NULL;
    LDAPMessage *searchResult, *entry;
    struct		timeval timeOut = {10,0};   
	char ldapuri[128];
	
   	timeOut.tv_sec = timeout;
   
    if (!ldapHost || (strlen(ldapHost) == 0))	return 0;
    if (!ldapPort)								return 0; 
	
#ifdef DEBUG
	int debug;
	if( ber_set_option( NULL, LBER_OPT_DEBUG_LEVEL, &debug )
			!= LBER_OPT_SUCCESS )
		{
			fprintf( stderr,
				"Could not set LBER_OPT_DEBUG_LEVEL %d\n", debug );
		}
	if( ldap_set_option( NULL, LDAP_OPT_DEBUG_LEVEL, &debug )
			!= LDAP_OPT_SUCCESS )
		{
			fprintf( stderr,
				"Could not set LDAP_OPT_DEBUG_LEVEL %d\n", debug );
		}
#endif
		
    version = LDAP_VERSION3;
    if( ldap_set_option( NULL, LDAP_OPT_PROTOCOL_VERSION, &version )
			!= LDAP_OPT_SUCCESS )
	{
#ifdef DEBUG
		printf("ldap_set_option version fail\n");
#endif
        return 0;
	}
	
	sprintf(ldapuri, "ldaps://%s:%d", ldapHost,ldapPort);
    rc = ldap_initialize( &ld, ldapuri );
	if( rc != LDAP_SUCCESS )
    {
#ifdef DEBUG
		printf("ldap_initialize fail\n");
#endif
        return 0;
    }
	rc = ldap_simple_bind_s( ld, bindDN, bindPWD);
	if (rc != LDAP_SUCCESS )
	{
		char* str=ldap_err2string( rc );
#ifdef DEBUG
		printf("ldap_simple_bind_s fail, bindDN=%s,msg=%s,rc=%d\n",bindDN,str, rc);
#endif
		ldap_unbind_s( ld );
		ldap_pvt_tls_destroy();
		return 0;
	}

    rc = ldap_search_ext_s(ld, searchBase, 
					LDAP_SCOPE_SUBTREE,	
					searchFilter,			
					NULL,			
                    0,						
                    NULL,					
                    NULL,					
                    &timeOut,				
                    LDAP_NO_LIMIT,			
                    &searchResult );		
    if ( rc != LDAP_SUCCESS ) 
    {
		sprintf(errMsg, "ldap_search_ext_s fail\n");
        ldap_msgfree( searchResult );
        ldap_unbind_s( ld );
		ldap_pvt_tls_destroy();
        return 0;
    }   
     
	entryCount = ldap_count_entries( ld, searchResult );
    for (entry = ldap_first_entry( ld, searchResult ), i=0; 
    	 entry != NULL && i < entryCount; 
    	 entry = ldap_next_entry( ld, searchResult ), i++)

   	{
	    if (( values = ldap_get_values( ld, entry, searchAttrs)) != NULL ) 
	    {
	        strcpy(permissions, values[0]);
	        ldap_value_free( values );
	    } 
		else
		{
			continue;
		}
		dn = ldap_get_dn( ld, entry );
	    if ( dn != NULL )            
	    {   	    	

	        rc = ldap_initialize( &ld_user, ldapuri );
			if( rc != LDAP_SUCCESS )
		    {
				sprintf(errMsg, "ldap_init fail\n");		
				ldap_memfree( dn );
				ldap_msgfree( searchResult );
	    		ldap_unbind_s(ld);
	    		ldap_pvt_tls_destroy();
		        return 0;
		    }
			rc = ldap_simple_bind_s( ld_user, dn, password);
			if (rc == LDAP_SUCCESS )
			{
				ldap_unbind_s(ld_user);
	    		ldap_memfree(dn); 
	    		ldap_msgfree( searchResult );
				ldap_unbind_s(ld);
				ldap_pvt_tls_destroy();
				return 1;
			}
		    ldap_unbind_s(ld_user);
	    	ldap_memfree(dn); 
	    }  
	}
   
    ldap_msgfree( searchResult );
    ldap_unbind_s( ld );
  
    ldap_pvt_tls_destroy();
	sprintf(errMsg, "LDAP: user not found\n");
	return 0;
}
int LDAPAuthClient(char* host, int port, char* baseDN, char* user, char* pass, int timeout, char* attribute, char* permissions)
{
	int		bResult = 0;
	char	loginDN[256];
	char	searchFilter[256];
	char*	searchAttrs[] = {attribute, 0};
	
	sprintf(loginDN, "cn=%s,%s", user, baseDN);
	sprintf(searchFilter, "(cn=%s)", user);
	if(389 == port)
		bResult = ldap_auth(host, port, loginDN, pass, baseDN, searchFilter, searchAttrs, timeout, permissions,NULL,0);
	else
		bResult = ldap_auth_ssl(host, port, loginDN, pass, baseDN, searchFilter, searchAttrs, timeout, permissions,NULL,0);
	return bResult;
}

int LDAPAuthByManager(char* host, int port, char* baseDN, char* bindDN, char* bindPWD, char* user, char* pass, int timeout, char* attribute, char* permissions)
{
	int		bResult = 0;
	char	loginDN[256];
	char	searchFilter[256];
	char*	searchAttrs = attribute;
	char	errMsg[128];
	
	sprintf(searchFilter, "(cn=%s)", user);
	if(389 == port)
		bResult = ldap_auth_by_manager(host, port, pass, baseDN, bindDN, bindPWD, searchFilter, searchAttrs, timeout, permissions, errMsg);
	else
		bResult = ldap_auth_ssl_by_manager(host, port, pass, baseDN, bindDN, bindPWD, searchFilter, searchAttrs, timeout, permissions, errMsg);
	return bResult;
}

int ActiveDirectoryAuthClient(char* host, int port, char* baseDN, char* user, char* pass, int timeout,
							 char* attribute, char* permissions,int (* CallbackFunc)(char *),char *ResValue)
{
	int		bResult = 0;
	char	loginDN[256];
	char	searchFilter[256];
	char    *searchAttrs[] = {attribute, 0};
	char    *ptr, *user_ptr;
	char    ab_user_name[128];
	
	memset(loginDN, 0, sizeof(loginDN));	
	memset(ab_user_name, 0, sizeof(ab_user_name));	
	memset(searchFilter, 0, sizeof(searchFilter));
	
	sprintf(loginDN, "%s", user);
	user_ptr = user;
	ptr=strstr(user_ptr, "@");
	if(ptr!=NULL)
	{
		memcpy(ab_user_name, user_ptr, ptr-user_ptr);	
	}
	else
	{		
		return bResult;
	}
	sprintf(searchFilter, "(cn=%s)", ab_user_name);
	if(389 == port)
		bResult = ldap_auth(host, port, loginDN, pass, baseDN, searchFilter, searchAttrs, timeout, permissions,CallbackFunc,ResValue);
	else
		bResult = ldap_auth_ssl(host, port, loginDN, pass, baseDN, searchFilter, searchAttrs, timeout,permissions,CallbackFunc,ResValue);
	return bResult;
}
#endif 
