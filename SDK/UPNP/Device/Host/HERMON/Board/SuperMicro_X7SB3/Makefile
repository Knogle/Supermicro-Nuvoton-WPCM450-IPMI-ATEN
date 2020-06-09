-include $(PRJ_PATH)/.SDKPath

SOURCES=$(wildcard ./IPMI_device/*.c)
OBJS=$(patsubst %.c,%.o,$(SOURCES))

EXECUTABLE  = upnp_dev
INCLUDEDIR  = -I$(PWD)/inc/
CFLAGS      = -pthread -O2 -Os -Wall -s
LDFLAGS     += -lixml -lupnp -lthreadutil -L$(PRJ_PATH)/lib


all:${OBJS}
	$(Q)${CC} $(CFLAGS) $(OBJS) -o $(BINPATH)/$(EXECUTABLE) $(LDFLAGS) $(INCLUDEDIR)
