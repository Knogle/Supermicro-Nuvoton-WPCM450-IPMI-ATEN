-include $(PRJ_PATH)/.SDKPath
DDNS_BIN_DIR = $(PRJ_PATH)/DDNS/bin
DDNS_TOOL_DIR = $(PRJ_PATH)/DDNS/tools
BIND_DIR = $(PRJ_PATH)/DDNS/tools/bind-9.3.2-P2/arm
BIND_VERSION = bind-9.3.2-P2

ifeq ($(MYMCU),AST2050)
MY_CFG_HOST = arm-aspeed-linux-gnu
endif

ifeq ($(MYMCU),HERMON)
MY_CFG_HOST = arm-linux
endif

ifeq ($(MYMCU),YARKON)
MY_CFG_HOST = arm-none-linux-gnueabi
endif

override CFLAGS = -Os
override LDFLAGS =
override LIBS =
override INCLUDEDIR =

ddns_program:
	$(Q)echo "================ make DDNS ==================="
	$(Q)if [ ! -d  $(BIND_DIR) ];then \
    cd $(DDNS_TOOL_DIR); tar -zxf $(BIND_VERSION).tar.gz ;fi
	$(Q)cd $(BIND_DIR); ./configure --prefix=/local --host=$(MY_CFG_HOST) --without-openssl --without-randomdev \
    ;cp -f $(BIND_DIR)/gen $(BIND_DIR)/lib/dns/; make; $(STRIP) $(BIND_DIR)/bin/nsupdate/nsupdate \
    ;cp -f $(BIND_DIR)/bin/nsupdate/nsupdate $(DDNS_BIN_DIR)/
	$(Q)echo "================ make DDNS done ==================="

ddns_clean:
	$(Q)echo "================ clean DDNS ==================="
	$(Q)cd $(BIND_DIR); make clean

clean: ddns_clean
