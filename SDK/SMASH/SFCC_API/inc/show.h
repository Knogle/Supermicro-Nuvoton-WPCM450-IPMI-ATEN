#include <cmci.h>
#include <native.h>
#include <unistd.h>
#include "datatype.h"

extern char *value2Chars(CMPIType type, CMPIValue * value);

void showObjectPath( CMPIObjectPath * objectpath );
void showInstance( CMPIInstance * instance );
void showInstanceProperty( ShowInfo * show, CMPIInstance * instance);
void showClass( CMPIConstClass * in_class );
void showProperty( CMPIData data, char *name );
