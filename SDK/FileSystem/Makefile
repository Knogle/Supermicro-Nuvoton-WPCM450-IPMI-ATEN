-include $(PRJ_PATH)/.config
-include $(PRJ_PATH)/.machine
TMPFS_PATH = $(PRJ_PATH)/FileSystem/Host/$(MYMCU)/tmp_fs
FS_PATH    = $(PRJ_PATH)/FileSystem/Host/$(MYMCU)/tmp
FS_PATH_FINAL = $(PRJ_PATH)/FileSystem/Host/$(MYMCU)/tmp_fs_final
WEBFS_PATH = $(PRJ_PATH)/FileSystem/Host/$(MYMCU)/web_fs
WEBFS_PATH_FINAL = $(PRJ_PATH)/FileSystem/Host/$(MYMCU)/web_fs_final
FS_SRCDIR  = $(PRJ_PATH)/FileSystem/Host/$(MYMCU)
FS_ZIP     = $(wildcard $(FS_SRCDIR)/*.tar.gz)
ETCPath  = $(FS_PATH)/etc/


ROOT_FS_SIZE	= 20
ROOT_FS_NAME	= rootfs
WEB_FS_SIZE	= 9
WEB_FS_NAME	= webfs

VERSION_CTRL_KEYWORD = .svn

TC_SRCDIR  = $(subst .tar.gz,,$(wildcard $(PRJ_PATH)/ToolChain/Host/$(MYMCU)/*.tar.gz))

export TMPFS_PATH FS_PATH WEBFS_PATH
export MYMCU FS_SRCDIR

FS_ELEMENT=$(addprefix _FS_ELEMENT_,$(FS_ELEMENT_DIR))

FS_ELEMENT_INST=$(addprefix _FS_ELEMENT_INST_,$(FS_ELEMENT_DIR))
BB_ELEMENT_DIR_INST=$(addprefix _BB_ELEMENT_INST_,$(BB_ELEMENT_DIR))

all:$(FS_ELEMENT)

.PHONY: $(FS_ELEMENT) $(FS_ELEMENT_INST) $(BB_ELEMENT_DIR_INST)
$(FS_ELEMENT):
	$(Q)if [ -d $(PRJ_PATH)/ToolChain/Host/$(MYMCU)/lib ];then cp -af $(PRJ_PATH)/ToolChain/Host/$(MYMCU)/lib/* $(PRJ_PATH)/lib/; fi
	$(MAKE) --directory=$(patsubst _FS_ELEMENT_%,%,$@)

$(FS_ELEMENT_INST):
	$(MAKE) install --directory=$(patsubst _FS_ELEMENT_INST_%,%,$@) 
$(BB_ELEMENT_DIR_INST):
	$(MAKE) install --directory=$(patsubst _BB_ELEMENT_INST_%,%,$@)
	
BUILD_FS: $(FS_ELEMENT_INST) $(BB_ELEMENT_DIR_INST)
	

install:
	$(Q)echo "Pre-Run Jobs .........."
	$(Q)echo "Gen Root Filesystem (CRAMFS).........."
	$(Q)if [ -d $(FS_PATH) ];then rm -rf $(FS_PATH) $(TMPFS_PATH) ; fi
	$(Q)mkdir -p $(FS_PATH)
	$(Q)mkdir $(TMPFS_PATH); cd $(TMPFS_PATH);tar zxf $(FS_ZIP)	
	$(Q)cd $(FS_SRCDIR); cp -rf tmp_fs/* $(FS_PATH)
	$(Q)if [ ! -d $(FS_PATH)/bin/ ];then mkdir -p $(FS_PATH)/bin/; fi
	$(Q)cp $(PRJ_PATH)/bin/* $(FS_PATH)/bin/ -rf

	$(Q)echo "Gen WWW Filesystem (CRAMFS).........."
	$(Q)if [ -d $(WEBFS_PATH) ];then rm -rf $(WEBFS_PATH); fi
	$(Q)mkdir -p $(WEBFS_PATH)

ifeq ($(BUILD_OPTION),1)
	$(Q)cp $(PRJ_PATH)/lib/*.so $(FS_PATH)/lib/
	$(Q)cp $(PRJ_PATH)/lib/*.so.* $(FS_PATH)/lib/
endif
	$(Q)cp $(PRJ_PATH)/lib/libxml2.so $(FS_PATH)/lib/libxml2.so
#	$(Q)cd $(FS_PATH)/lib/ ;ln  -s libxml2.so libxml2.so.2
#copy the necessary files of the firmware here
	$(Q)chmod +x $(FS_SRCDIR)/Board/$(BOARD)/rcS; \
	cp $(FS_SRCDIR)/Board/$(BOARD)/rcS $(ETCPath)/init.d/rcS
	$(Q)if [ -f $(FS_SRCDIR)/Board/$(BOARD)/dhcp.script ]; then \
	cp $(FS_SRCDIR)/Board/$(BOARD)/dhcp.script $(FS_PATH)/usr/share/udhcpc/default.script; \
	fi
ifeq ($(MYMCU),HERMON)	
	$(Q)cp $(FS_SRCDIR)/Board/$(BOARD)/BTL  $(ETCPath)
endif	
#busybox, openssl, webserver(shttpd)	
	$(Q)$(MAKE) BUILD_FS
#enable network console
ifeq ($(CONFIG_DEBUG_NETCONSOLE),y)
	$(Q) echo "telnetd -p 1206" >> $(ETCPath)/init.d/rcS 
endif
#handle  platform independent files here
	make install --directory=Host/$(MYMCU)/Board/$(BOARD)/
#umount
	$(Q)cd $(WEBFS_PATH); \
	find ./ | grep "$(VERSION_CTRL_KEYWORD)" | xargs -n 1 rm -rf; cd $(PRJ_PATH)/FileSystem
	$(Q)if [ -d $(WEBFS_PATH_FINAL) ];then umount $(WEBFS_PATH_FINAL); rm -rf $(WEBFS_PATH_FINAL); fi
	$(Q)mkdir -p $(WEBFS_PATH_FINAL)
	$(Q)dd if=/dev/zero of=$(WEB_FS_NAME)_tmp bs=1024K count=$(WEB_FS_SIZE) >>/dev/null
	$(Q)/sbin/mke2fs -F -m0 $(WEB_FS_NAME)_tmp >>/dev/null
	$(Q)mount -o loop $(WEB_FS_NAME)_tmp $(WEBFS_PATH_FINAL)
	$(Q)cp -af $(WEBFS_PATH)/* $(WEBFS_PATH_FINAL)/
	$(Q)/sbin/mkfs.cramfs $(WEBFS_PATH_FINAL) $(PRJ_PATH)/FileSystem/$(WEB_FS_NAME)
	$(Q)umount $(WEBFS_PATH_FINAL)
	$(Q)cd $(FS_PATH); \
	find ./ | grep "$(VERSION_CTRL_KEYWORD)" | xargs -n 1 rm -rf; \
	find ./bin | grep "\.sh" | xargs -n 1 -r chmod u+x,g+x,o+x; \
	find ./usr/bin | grep "\.sh" | xargs -n 1 -r chmod u+x,g+x,o+x; \
	find ./sbin | grep "\.sh" | xargs -n 1 -r chmod u+x,g+x,o+x; \
	find ./usr/sbin | grep "\.sh" | xargs -n 1 -r chmod u+x,g+x,o+x; \
	find ./etc | grep "\.sh" | xargs -n 1 -r chmod u+x,g+x,o+x; \
	chmod u+x,g+x,o+x ./etc/ResetIP.sh; \
	chmod u+x,g+x,o+x ./etc/dhcpv6/dhcp6c-script; \
	chmod u+x,g+x,o+x ./usr/share/udhcpc/default.script; \
	chmod u+x,g+x,o+x ./etc/network/network6; \
	chmod u+x,g+x,o+x ./etc/init.d/rcS; \
	chmod u+x,g+x,o+x ./bin/htpasswd; \
	cd $(PRJ_PATH)/FileSystem
	$(Q)if [ -d $(FS_PATH_FINAL) ];then umount $(FS_PATH_FINAL); rm -rf $(FS_PATH_FINAL) ; fi
	$(Q)mkdir -p $(FS_PATH_FINAL)
	$(Q)dd if=/dev/zero of=$(ROOT_FS_NAME)_tmp bs=1024K count=$(ROOT_FS_SIZE) >>/dev/null
	$(Q)/sbin/mke2fs -F -m0 $(ROOT_FS_NAME)_tmp >>/dev/null	
	$(Q)mount -o loop $(ROOT_FS_NAME)_tmp $(FS_PATH_FINAL)
	$(Q)cp -af $(FS_PATH)/* $(FS_PATH_FINAL)/
	$(Q)/sbin/mkfs.cramfs $(FS_PATH_FINAL) $(PRJ_PATH)/FileSystem/$(ROOT_FS_NAME)
	$(Q)umount $(FS_PATH_FINAL)
	$(Q)if [ ! -d $(IMAGE_PATH) ]; then mkdir -p $(IMAGE_PATH); fi
	$(Q)cp -f $(ROOT_FS_NAME) $(WEB_FS_NAME) $(IMAGE_PATH)
	$(Q)echo "Updating Successfully......."
	$(Q)rm -rf $(FS_PATH) $(TMPFS_PATH) $(WEBFS_PATH) $(FS_PATH_FINAL) $(WEBFS_PATH_FINAL)
	
clean:
	$(Q)echo "******************** clean File System ********************"
	$(Q)for i in $(FS_ELEMENT_DIR); do make -C $$i clean; done
	$(Q)for i in $(BB_ELEMENT_DIR); do make -C $$i clean; done

-include $(PRJ_PATH)/FileSystem/fs_extractor.in

