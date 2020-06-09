-include $(PRJ_PATH)/.config
-include $(PRJ_PATH)/.machine
SDRFiles = $(wildcard SDRBlock.W83* SDRBlock.N*)
FRUFiles = FRUBlock
XMLFiles = $(wildcard platform*.xml) 
CONFPath = $(FS_PATH)/etc/conf/
ETCPath  = $(FS_PATH)/etc/

ifeq ($(CONFIG_PLATFORM_SUPERMICRO_SUBVERSION_X8DTT),y)
SDRBLOCK_TAR_LOC = $(FS_SRCDIR)/Board/$(BOARD)/$(SUBBOARD)/SDRBlock.tar.gz
else
SDRBLOCK_TAR_LOC = $(FS_SRCDIR)/Board/$(BOARD)/SDRBlock.tar.gz
endif

install:
	$(Q)mkdir -p  $(CONFPath)
#SDR files
	$(Q)cp $(SDRFiles) $(CONFPath)
#XML files
	$(Q)cp $(XMLFiles)  $(CONFPath)
#FRU files
	$(Q)cp $(FRUFiles) $(CONFPath)
#create soft link for the same SDR
	$(Q)cd $(CONFPath);tar zxf $(SDRBLOCK_TAR_LOC);cd -
#IPV6 related files
	$(Q)mkdir -p $(FS_PATH)/etc/network
	$(Q)cp netconfig $(ETCPath)/network/netconfig.default
	$(Q)ln -sf /nv/network/netconfig0 $(ETCPath)/network/netconfig0
	$(Q)ln -sf /nv/network/netconfig1 $(ETCPath)/network/netconfig1
	$(Q)ln -sf /nv/network/netconfig2 $(ETCPath)/network/netconfig2
	$(Q)cp network6 $(ETCPath)/network/
	$(Q)cp $(PRJ_PATH)/Kernel/Host/$(MYMCU)/linux/drivers/net/bonding/bonding.ko $(FS_PATH)/bin/module/
#default XML conifg
	$(Q)mkdir -p $(ETCPath)/defaults
	$(Q)cp defaults/*.xml  $(ETCPath)/defaults/
#reset IP script
	$(Q)cp ResetIP.sh 	   $(ETCPath)
	$(Q)if [ -f profile ]; then \
	cp profile $(ETCPath); \
	fi
#UPNP
ifeq ($(CONFIG_UPNP),y)
	$(Q)cp IPMIdevicedesc_sample.xml $(ETCPath)
endif
#OEM project files
ifeq ($(CONFIG_PLATFORM_SUPERMICRO_SUBVERSION_X8DTT),y)
	$(Q)cp $(SUBBOARD)/defaults/*.xml  $(ETCPath)/defaults/
	$(Q)cp $(SUBBOARD)/FRUBlock	$(CONFPath)
	$(Q)cp $(SUBBOARD)/*.xml	$(CONFPath)
endif
	$(Q)ln -sf /nv/hostname_for_dhcp $(ETCPath)/hostname_for_dhcp
