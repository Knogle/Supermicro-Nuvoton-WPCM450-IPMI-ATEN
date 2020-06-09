#include <cmci.h>
#include <unistd.h>
#include <stdlib.h>
#include "show.h"

#define SFCC_FAIL       -1
#define SFCC_SUCCESS     0

int SFCC_API_EnumerateInstances(ShowInfo *show, char *NameSpace, char *ClassName, int index);
int SFCC_API_EnumerateInstanceNames(ShowInfo *show, char *NameSpace, char *ClassName);
int SFCC_API_InvokeMethod(CMPIObjectPath *objectpath, char *MethodName, CMPIArgs * args);
int SFCC_API_DeleteInstance(char *NameSpace, char *ClassName, int index);
int SFCC_API_Show(ShowInfo *show, char *NameSpace, char *ClassName, char *SubClassName, int index);
int SFCC_API_Delete(char *NameSpace, char *ClassName, int index, char *MethodName, CMPIArgs * args);
int SFCC_API_Start(char *NameSpace, char *ClassName, int index, char *MethodName, CMPIArgs *args);
int SFCC_API_Stop(char *NameSpace, char *ClassName, int index, char *MethodName, CMPIArgs *args);
int SFCC_API_Reset(char *NameSpace, char *ClassName, int index, char *MethodName, CMPIArgs *args);
