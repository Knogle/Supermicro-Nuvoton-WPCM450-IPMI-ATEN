NTP_BIN_DIR = $(PRJ_PATH)/NTP/bin
NTP_ETC_DIR = $(PRJ_PATH)/NTP/etc
NTP_TOOL_ROOTDIR = $(PRJ_PATH)/NTP/tools
NTP_VERSION = ntp-4.2.4p4
NTP_TOOL_DIR = $(PRJ_PATH)/NTP/tools/$(NTP_VERSION)

#override CFLAGS = -Os
#override LDFLAGS =
override LIBS =
override INCLUDEDIR =

all:
	$(Q)echo "CFLAGS = $(CFLAGS)"
	$(Q)echo "================  Build NTP ================"
	$(Q)echo "LDFLAGS = $(LDFLAGS)"
	$(Q)if [ ! -f $(NTP_BIN_DIR)/ntpdate ] || [ ! -f $(NTP_BIN_DIR)/ntpd ];then \
	cd $(NTP_TOOL_ROOTDIR); make ntp_program; fi
	$(Q)cd $(NTP_BIN_DIR); $(CC) $(LDFLAGS) -o ntp_setenv ntp_setenv.o

install:
	$(Q)echo "================  Install NTP ================" 
	$(Q)cd $(NTP_BIN_DIR); cp -f ntpd ntpdate *.sh ntp_setenv $(FS_PATH)/bin 
	$(Q)if [ ! -d  $(FS_PATH)/usr/local/etc/ntp ];then \
    mkdir $(FS_PATH)/usr/local/etc/ntp; fi
	$(Q)cd $(NTP_ETC_DIR); cp -f ./ntp.conf $(FS_PATH)/usr/local/etc/ntp
	$(Q)ln -sf /nv/ntp/ntp.conf $(FS_PATH)/etc/ntp.conf
	$(Q)ln -sf /nv/timezone $(FS_PATH)/usr/local/etc/timezone
	$(Q)echo "================ build NTP done ================"

clean:
	$(Q)cd $(NTP_BIN_DIR); rm -rf ./ntpdate; rm -rf ./ntpd; rm -rf ./ntp_setenv; rm -rf ./ntp_setenv.o
	$(Q)if [ -d $(NTP_TOOL_DIR) ];then cd $(NTP_TOOL_ROOTDIR); make clean; fi


