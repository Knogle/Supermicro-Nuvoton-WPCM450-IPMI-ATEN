include $(PRJ_PATH)/.config
#include $(SDKROOT)/.ProjectName
OBJS-y = BTL_UPDATE.o
OBJS = $(OBJS-y) #$(SOURCES-y:.c=.o)

#CFLAGS +=  -I$(PRJ_PATH)/SDKFILES/$(PRJNAME)/inc/
EXECUTABLE = BTL_UPDATE
all :$(SOURCES-y:.c=.o)
	@echo " LD "$(EXECUTABLE)
	@if [ ! -d $(BINPATH) ]; then mkdir $(BINPATH); fi
	$(CC) -o $(BINPATH)/$(EXECUTABLE) $(OBJS) $(LDFLAGS)

EXECUTABLE = BTL_UPDATE
install :

clean:

#include $(SDKROOT)/rule.mk
