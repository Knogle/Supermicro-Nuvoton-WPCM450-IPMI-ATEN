
ifeq ($(MYMCU),AST2050)
BUILD_HOST = arm-aspeed-linux-gnu
else
BUILD_HOST = arm-linux
endif

UPNP_VERSION = libupnp-1.3.1
UPNP_SRCDIR = $(PRJ_PATH)/UPNP
UPNP_LIBDIR = $(PRJ_PATH)/UPNP/$(UPNP_VERSION)
UPNP_ZIP    = $(wildcard $(UPNP_SRCDIR)/*.tar.gz)

export	UPNP_LIBDIR

override CFLAGS = 
override LDFLAGS =
override LIBS =
override INCLUDEDIR =

all:
	$(Q)echo "******************** build UPNP LIB & Device ********************"
	$(Q)cd $(UPNP_SRCDIR); \
	if [ ! -d $(UPNP_LIBDIR) ];then mkdir $(UPNP_LIBDIR);cd $(UPNP_LIBDIR);tar zxf $(UPNP_ZIP); fi
	$(Q)cd $(UPNP_LIBDIR); ./configure --host=$(BUILD_HOST); make; make install;
	$(Q)cp -f $(UPNP_LIBDIR)/upnp/.libs/libupnp.a $(LIBPATH);
	$(Q)cp -f $(UPNP_LIBDIR)/ixml/.libs/libixml.a $(LIBPATH);
	$(Q)cp -f $(UPNP_LIBDIR)/threadutil/.libs/libthreadutil.a $(LIBPATH);
	@make -C Device/Host/$(MYMCU)/Board/$(BOARD)/
	$(Q)rm -f $(LIBPATH)/libupnp.a
	$(Q)rm -f $(LIBPATH)/libixml.a
	$(Q)rm -f $(LIBPATH)/libthreadutil.a
	
	


install:
#copy UPNP LIB & Device
	$(Q)echo "******************** build UPNP ********************"


clean:
	$(Q)echo "******************** clean UPNP ********************"
	@rm -f $(UPNP_SRCDIR)/Device/Host/$(MYMCU)/Board/$(BOARD)/IPMI_device/*.o
	$(Q)if [ -d $(UPNP_LIBDIR) ];then make -C $(UPNP_LIBDIR) clean; fi

	
