#include<stdlib.h>

typedef struct _PList
{
        char *name;
        char *value;
        struct _PList *next;
}PList;

typedef struct _ShowInfo
{
        int NumSubClass;
        PList *PropertyList;
}ShowInfo;

