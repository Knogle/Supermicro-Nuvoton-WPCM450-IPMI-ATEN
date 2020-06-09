include $(PRJ_PATH)/.config
#include $(SDKROOT)/.ProjectName
OBJS-y = SlaveTask.o SlaveTaskTbl.o
OBJS = $(OBJS-y) #$(SOURCES-y:.c=.o)

#CFLAGS +=  -I$(PRJ_PATH)/SDKFILES/$(PRJNAME)/inc/
EXECUTABLE = slavetask
all :$(SOURCES-y:.c=.o)
	@echo " LD "$(EXECUTABLE)
	@if [ ! -d $(BINPATH) ]; then mkdir $(BINPATH); fi
	$(CC) -o $(BINPATH)/$(EXECUTABLE) $(OBJS) $(LDFLAGS)

EXECUTABLE = slavetask
install :

clean:

#include $(SDKROOT)/rule.mk
