include $(PRJ_PATH)/.config
#include $(SDKROOT)/.ProjectName
OBJS-$(CONFIG_CHNL_KCS) = kcs.o
OBJS = $(OBJS-y) #$(SOURCES-y:.c=.o)

#CFLAGS +=  -I$(PRJ_PATH)/SDKFILES/$(PRJNAME)/inc/
EXECUTABLE = ipmi_kcs
all :$(SOURCES-y:.c=.o)
	@echo " LD "$(EXECUTABLE)
	@if [ ! -d $(BINPATH) ]; then mkdir $(BINPATH); fi
	$(CC) -o $(BINPATH)/$(EXECUTABLE) $(OBJS) $(LDFLAGS)

EXECUTABLE = ipmi_kcs
install :

clean:

#include $(SDKROOT)/rule.mk
