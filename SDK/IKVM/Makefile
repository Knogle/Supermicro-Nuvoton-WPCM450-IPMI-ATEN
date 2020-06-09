include $(PRJ_PATH)/.config
OBJS-$(CONFIG_IKVM) = ServerEntry.o libserverlib.a
OBJS = $(OBJS-y)


EXECUTABLE = ikvmserver
all :
	@echo $(OBJS)
	@echo " LD "$(EXECUTABLE)
	@if [ ! -d $(BINPATH) ]; then mkdir $(BINPATH); fi
	$(CXX) -o $(BINPATH)/$(EXECUTABLE) $(OBJS) $(LDFLAGS)

EXECUTABLE = ikvmserver
install:

clean:


#include $(PRJ_PATH)/rule.mk
