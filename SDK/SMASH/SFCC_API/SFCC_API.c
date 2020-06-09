#include "inc/SFCC_API.h"
#include <cmci.h>
#include <native.h>
#include <unistd.h>
#include <stdlib.h>



CMPIObjectPath *getInstanceObjectPath(char *NameSpace, char *ClassName, int index);



int SFCC_API_EnumerateInstances(ShowInfo *show, char *NameSpace, char *ClassName, int index)
{
    int idxCount;
	CMCIClient *cc;
	CMPIObjectPath *objectpath;
	CMPIEnumeration *enumeration;
	CMPIStatus status;
	char *cim_host, *cim_host_passwd, *cim_host_userid;

	cim_host = getenv("CIM_HOST");
	if (cim_host == NULL)
		cim_host = "localhost";
	
	cim_host_userid = getenv("CIM_HOST_USERID");
	if (cim_host_userid == NULL)
		cim_host_userid = "root";

	cim_host_passwd = getenv("CIM_HOST_PASSWD");
	if (cim_host_passwd == NULL)
		cim_host_passwd = "password";
	cc = cmciConnect(cim_host, "SfcbLocal", "5988", cim_host_userid, cim_host_passwd, NULL);
    if(cc == NULL)
    {
#ifdef API_DEBUG 
        printf("Connection fail\n");
#endif
        return SFCC_FAIL;
    }    

	objectpath = newCMPIObjectPath(NameSpace, ClassName, NULL);
	enumeration = cc->ft->enumInstances(cc, objectpath, 0, NULL, &status);
#ifdef API_DEBUG
    printf( "enumInstances() rc=%d, msg=%s\n", status.rc, (status.msg)? (char *)status.msg->hdl : NULL);
#endif	
    idxCount = 0;
    if(enumeration)
    while (enumeration->ft->hasNext(enumeration, NULL)) {
        idxCount++;
		CMPIData data = enumeration->ft->getNext(enumeration, NULL);
        if(idxCount == index)
			showInstanceProperty(show, data.value.inst);
    }
    if (enumeration) CMRelease(enumeration);
    if (objectpath) CMRelease(objectpath);
    if (status.msg) CMRelease(status.msg);
	if (cc) CMRelease(cc);

	if (!status.rc)
		return SFCC_SUCCESS;
	else
		return SFCC_FAIL;
}



int SFCC_API_EnumerateInstanceNames(ShowInfo *show, char *NameSpace, char *ClassName)
{

	int enumcount;
    CMCIClient *cc;
    CMPIObjectPath *objectpath;
    CMPIEnumeration *enumeration;
    CMPIStatus status;
    char *cim_host, *cim_host_passwd, *cim_host_userid;

    cim_host = getenv("CIM_HOST");
    if (cim_host == NULL)
        cim_host = "localhost";

    cim_host_userid = getenv("CIM_HOST_USERID");
    if (cim_host_userid == NULL)
        cim_host_userid = "root";

    cim_host_passwd = getenv("CIM_HOST_PASSWD");
    if (cim_host_passwd == NULL)
        cim_host_passwd = "password";
    cc = cmciConnect(cim_host, "SfcbLocal", "5988", cim_host_userid, cim_host_passwd, NULL);
    if(cc == NULL)
    {
#ifdef API_DEBUG
        printf("Connection fail\n");
#endif
        return SFCC_FAIL;
    }
    

    objectpath = newCMPIObjectPath(NameSpace, ClassName, NULL);
    enumeration = cc->ft->enumInstanceNames(cc, objectpath, &status);
#ifdef API_DEBUG
    printf( "enumInstanceNames() rc=%d, msg=%s\n", status.rc, (status.msg)? (char *)status.msg->hdl : NULL);
#endif	
    enumcount = 0;
    if(enumeration)
    while (enumeration->ft->hasNext(enumeration, NULL)) {
	    enumcount++;
        CMPIData data = enumeration->ft->getNext(enumeration, NULL);
    }
    show->NumSubClass = enumcount;


    if (enumeration) CMRelease(enumeration);
    if (objectpath) CMRelease(objectpath);
    if (status.msg) CMRelease(status.msg);
	if (cc) CMRelease(cc);

    if (!status.rc)
        return SFCC_SUCCESS;
    else
        return SFCC_FAIL;
}



int SFCC_API_InvokeMethod(CMPIObjectPath *objectpath, char *MethodName, CMPIArgs * args)
{
    CMCIClient      * cc;
    CMPIStatus      status;
    char            *cim_host, *cim_host_passwd, *cim_host_userid;
    CMPIData        retval;
    CMPIValue       arg;
    CMPIArgs        * inargs, * outargs;
    int idxCount;
    cim_host = getenv("CIM_HOST");
    if (cim_host == NULL)
    cim_host = "localhost";
    cim_host_userid = getenv("CIM_HOST_USERID");
    if (cim_host_userid == NULL)
    cim_host_userid = "root";
    cim_host_passwd = getenv("CIM_HOST_PASSWD");
    if (cim_host_passwd == NULL)
    cim_host_passwd = "password";
    cc = cmciConnect(cim_host, "SfcbLocal", "5988", cim_host_userid, cim_host_passwd, NULL);
    if(cc == NULL)
    {
#ifdef API_DEBUG
        printf("Connection fail\n");
#endif
        return SFCC_FAIL;
    }

    if(MethodName != NULL)
    {
        if(args == NULL)
        {
#ifdef API_DEBUG
            printf("start method invoking\n");
#endif
            inargs = newCMPIArgs(NULL);
            outargs = newCMPIArgs(NULL);
            retval = cc->ft->invokeMethod(cc, objectpath, MethodName, inargs, outargs, &status);
#ifdef API_DEBUG            
            printf("invoke done\n");
#endif
        }
        else
        {
        }
    }

#ifdef API_DEBUG
    printf( "invokeMethod() rc=%d, msg=%s\n", status.rc, (status.msg)? (char *)status.msg->hdl : NULL);
#endif
    
    if (objectpath) CMRelease(objectpath);
    if (status.msg) CMRelease(status.msg);
    if (cc) CMRelease(cc);
    if (!status.rc)
        return SFCC_SUCCESS;
    else
        return SFCC_FAIL;

}



int SFCC_API_DeleteInstance(char *NameSpace, char *ClassName, int index)
{
    
    return SFCC_SUCCESS;
}



int SFCC_API_Show(ShowInfo *show, char *NameSpace, char *ClassName, char *SubClassName, int index)
{	
	if(ClassName != NULL)
	{
		if( SFCC_FAIL ==  SFCC_API_EnumerateInstances(show, NameSpace, ClassName, index))
		{
#ifdef API_DEBUG
			printf("Enumeration Failed\n");
#endif
			return SFCC_FAIL;
		}
	}
	if(SubClassName != NULL)
        {
                if( SFCC_FAIL == SFCC_API_EnumerateInstanceNames(show, NameSpace, SubClassName))
                {
#ifdef API_DEBUG
                        printf("Enumeration Failed\n");
#endif
                        return SFCC_FAIL;
                }
        }

	return SFCC_SUCCESS;
}



int SFCC_API_Delete(char *NameSpace, char *ClassName, int index, char *MethodName, CMPIArgs * args)
{
    SFCC_API_InvokeMethod(getInstanceObjectPath(NameSpace, ClassName, index), MethodName, args);
    SFCC_API_DeleteInstance(NameSpace, ClassName, index);

    return SFCC_SUCCESS;
}



int SFCC_API_Start(char *NameSpace, char *ClassName, int index, char *MethodName, CMPIArgs *args)
{ 
    return SFCC_API_InvokeMethod(getInstanceObjectPath(NameSpace, ClassName, index), MethodName, args);
}



int SFCC_API_Stop(char *NameSpace, char *ClassName, int index, char *MethodName, CMPIArgs *args)
{
    return SFCC_API_InvokeMethod(getInstanceObjectPath(NameSpace, ClassName, index), MethodName, args);
}



int SFCC_API_Reset(char *NameSpace, char *ClassName, int index, char *MethodName, CMPIArgs *args)
{
    return SFCC_API_InvokeMethod(getInstanceObjectPath(NameSpace, ClassName, index), MethodName, args);
}



CMPIObjectPath *getInstanceObjectPath(char *NameSpace, char *ClassName, int index)
{
    CMCIClient *cc;
    CMPIObjectPath  * objectpath;
    CMPIStatus      status;
    char            *cim_host, *cim_host_passwd, *cim_host_userid;
    CMPIData        retval;
    CMPIValue       arg;
    CMPIEnumeration *enumeration;
    int idxCount;
    cim_host = getenv("CIM_HOST");
    if (cim_host == NULL)
    cim_host = "localhost";
    cim_host_userid = getenv("CIM_HOST_USERID");
    if (cim_host_userid == NULL)
    cim_host_userid = "root";
    cim_host_passwd = getenv("CIM_HOST_PASSWD");
    if (cim_host_passwd == NULL)
    cim_host_passwd = "password";
    cc = cmciConnect(cim_host, "SfcbLocal", "5988", cim_host_userid, cim_host_passwd, NULL);
    if(cc == NULL)
    {
#ifdef API_DEBUG
        printf("Connection fail\n");
#endif
        return SFCC_FAIL;
    }

    objectpath = newCMPIObjectPath(NameSpace, ClassName, NULL);

    enumeration = cc->ft->enumInstanceNames(cc, objectpath, &status);
#ifdef API_DEBUG
    printf( "enumInstanceNames() rc=%d, msg=%s\n", status.rc, (status.msg)? (char *)status.msg->hdl : NULL);
#endif    
    idxCount = 0;
    if(enumeration)
    while (enumeration->ft->hasNext(enumeration, NULL))
    {
        idxCount++;
        CMPIData data = enumeration->ft->getNext(enumeration, NULL);
        CMPIObjectPath *op = data.value.ref;
        if(idxCount == index)
        {
            int numkeys = op->ft->getKeyCount(op, NULL);
            int i;
            char *cv;
            if (numkeys)
            {
#ifdef API_DEBUG
                printf("keys:\n");
#endif
                for (i=0; i<numkeys; i++)
                {
                    CMPIString * keyname;
                    CMPIData data = op->ft->getKeyAt(op, i, &keyname, NULL);
#ifdef API_DEBUG
                    printf("\t%s=%s\n", (char *)keyname->hdl, cv=value2Chars(data.type, &data.value));
                    if(cv) free(cv);
#endif
                    CMAddKey(objectpath, (char *)keyname->hdl, value2Chars(data.type, &data.value), CMPI_chars);
                    if(keyname) CMRelease(keyname);
                }
            }
        }
    }
    if (enumeration) CMRelease(enumeration);
    if (status.msg) CMRelease(status.msg);
    if (cc) CMRelease(cc);
    return objectpath;

}
