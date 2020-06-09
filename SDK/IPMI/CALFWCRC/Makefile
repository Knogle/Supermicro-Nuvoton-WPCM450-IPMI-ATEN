include $(PRJ_PATH)/.config
#include $(SDKROOT)/.ProjectName
OBJS-y = calfwcrc16.o
OBJS = $(OBJS-y) #$(SOURCES-y:.c=.o)

#CFLAGS +=  -I$(PRJ_PATH)/SDKFILES/$(PRJNAME)/inc/
EXECUTABLE = calfwcrc16
all :$(SOURCES-y:.c=.o)
	@echo " LD "$(EXECUTABLE)
	@if [ ! -d $(BINPATH) ]; then mkdir $(BINPATH); fi
	$(CC) -o $(BINPATH)/$(EXECUTABLE) $(OBJS) $(LDFLAGS)

EXECUTABLE = calfwcrc16
install :

clean:

#include $(SDKROOT)/rule.mk
