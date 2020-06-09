include $(PRJ_PATH)/.config
#include $(SDKROOT)/.ProjectName
OBJS-$(CONFIG_CHNL_LAN) = LanCommon.o UDPListenTask.o Lan.o LanModule.o
OBJS = $(OBJS-y) #$(SOURCES-y:.c=.o)

#CFLAGS +=  -I$(PRJ_PATH)/SDKFILES/$(PRJNAME)/inc/
EXECUTABLE = ipmi_lan
all :$(SOURCES-y:.c=.o)
	@echo " LD "$(EXECUTABLE)
	@if [ ! -d $(BINPATH) ]; then mkdir $(BINPATH); fi
	$(CC) -o $(BINPATH)/$(EXECUTABLE) $(OBJS) $(LDFLAGS)

EXECUTABLE = ipmi_lan
install :

clean:

#include $(SDKROOT)/rule.mk
