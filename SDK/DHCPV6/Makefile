tmp_dir=wide-dhcpv6
Conf_Dest=$(FS_PATH)/etc/dhcpv6
PACKAGE=wide-dhcpv6-20080615.tar.gz
ifeq ($(MYMCU),AST2050)
EXTCFLAGS=-DLINE_MAX=2048
endif
all:
	
install:
	@echo "Build DHCPv6Cleint ........"
	$(Q)if [ ! -d $(tmp_dir) ];then mkdir $(tmp_dir);cd $(tmp_dir);tar zxf ../$(PACKAGE);fi
	$(Q)if [ ! -f $(tmp_dir)/dhcp6c ];then cd $(tmp_dir);CFLAGS=$(EXTCFLAGS) make  CC=$(CC) LD=$(LD) AR=$(AR) ;fi
	@cp -f $(tmp_dir)/dhcp6c $(FS_PATH)/bin/
	@if [ ! -d $(Conf_Dest) ];then mkdir $(Conf_Dest);fi
	@cp conf/* $(Conf_Dest)

clean:
	@rm -rf $(tmp_dir)


