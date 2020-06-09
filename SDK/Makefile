ifdef  BOARD
-include Project_File/OS/Linux/Host/$(MYMCU)/Board/$(BOARD)/Projectfile
else 
-include .config
endif
include .machine
-include ./ProjectConfig-$(MYMCU)
CC=$(CROSS_COMPILE)gcc
LD=$(CROSS_COMPILE)ld
AR=$(CROSS_COMPILE)ar
CXX=$(CROSS_COMPILE)g++
NM=$(CROSS_COMPILE)nm
RANLIB=$(CROSS_COMPILE)ranlib
OBJCOPY=$(CROSS_COMPILE)objcopy
OBJDUMP=$(CROSS_COMPILE)objdump 
STRIP = $(CROSS_COMPILE)strip
-include ./ProjectConfig-x86
X86_CC=$(X86_CROSS_COMPILE)gcc
X86_LD=$(X86_CROSS_COMPILE)ld
X86_AR=$(X86_CROSS_COMPILE)ar
X86_CXX=$(X86_CROSS_COMPILE)g++
X86_NM=$(X86_CROSS_COMPILE)nm
X86_RANLIB=$(X86_CROSS_COMPILE)ranlib
X86_OBJCOPY=$(X86_CROSS_COMPILE)objcopy
X86_OBJDUMP=$(X86_CROSS_COMPILE)objdump 
X86_STRIP = $(X86_CROSS_COMPILE)strip
export X86_CC X86_LD X86_AR X86_CXX X86_NM X86_RANLIB X86_OBJCOPY X86_OBJDUMP X86_STRIP
-include ./ProjectConfig-x86_64
X86_64_CC=$(X86_64_CROSS_COMPILE)gcc
X86_64_LD=$(X86_64_CROSS_COMPILE)ld
X86_64_AR=$(X86_64_CROSS_COMPILE)ar
X86_64_CXX=$(X86_64_CROSS_COMPILE)g++
X86_64_NM=$(X86_64_CROSS_COMPILE)nm
X86_64_RANLIB=$(X86_64_CROSS_COMPILE)ranlib
X86_64_OBJCOPY=$(X86_64_CROSS_COMPILE)objcopy
X86_64_OBJDUMP=$(X86_64_CROSS_COMPILE)objdump 
X86_64_STRIP = $(X86_64_CROSS_COMPILE)strip
export X86_64_CC X86_64_LD X86_64_AR X86_64_CXX X86_64_NM X86_64_RANLIB X86_64_OBJCOPY X86_64_OBJDUMP X86_64_STRIP
-include ./ProjectConfig-JavaAP
ifeq ($(CONFIG_PLATFORM_SUPERMICRO_SUBVERSION_X8DTT),y)
	JAVA_KVM_VIEWER_FULL_VERSION = $(JAVA_KVM_VIEWER_VERSION).$(shell cat $(PRJ_PATH)/FileSystem/Host/$(MYMCU)/Board/$(BOARD)/$(SUBBOARD)/JavaAP/BoardInfo.java | grep board_id | cut -d '=' -f 2 | sed 's/\t//g' | sed 's/ //g' | sed 's/;//g')
else
	JAVA_KVM_VIEWER_FULL_VERSION = $(JAVA_KVM_VIEWER_VERSION).$(shell cat $(PRJ_PATH)/JavaAP/KVM/src/java/tw/com/aten/ikvm/DefBoardInfo | grep board_id | cut -d '=' -f 2 | sed 's/\t//g' | sed 's/ //g' | sed 's/;//g')
endif
export JAVA_KVM_VIEWER_VERSION JAVA_KVM_LIB_VERSION JAVA_KVM_VIEWER_FULL_VERSION
PRJ_PATH=$(shell pwd)
#for tool chain
TOOLCHAIN_ZIP=$(wildcard $(PRJ_PATH)/ToolChain/Host/$(MYMCU)/*.tar.gz)
X86_TOOLCHAIN_ZIP=$(wildcard $(PRJ_PATH)/ToolChain/Host/i386/gcc*.tar.gz)
X86_64_TOOLCHAIN_ZIP=$(wildcard $(PRJ_PATH)/ToolChain/Host/x86_64/mingw-w64*.tar.bz2)

ifneq ($(CONFIG_COMPILE_FLAGS),"")
USER_DEFINE_CFLAGS := $(shell echo $(CONFIG_COMPILE_FLAGS))
else
USER_DEFINE_CFLAGS :=
endif

CFLAGS = -Wall -fpic -DKVM_VIEWER_VERSION=\"$(JAVA_KVM_VIEWER_FULL_VERSION)\" -DSOL_VIEWER_VERSION=\"$(JAVA_SOL_VIEWER_FULL_VERSION)\" -DOS_LINUX -DIPMI_RMCP_PLUS_SUB_SOL -DIPMI_RMCP_PLUS -DIPMI_RMCP_PLUS_SUB_AES -DOWN_AST_WEB_SERVER -DSMTP -DWSMAN -DIPMI_DHCP -DRAM_SENSOR_EN -DENABLE_OWN_AST_LDAP -DENABLE_AUTH_RADIUS -DBMC_VLAN -DFW_CHKSUM $(USER_DEFINE_CFLAGS)

ifeq ($(BOARD),SuperMicro_X7SB3)
CFLAGS +=   -DFRU_RECOVER
endif

ifeq ($(CONFIG_DEBUG),y)
CFLAGS +=   -DDEBUG 
endif

ifeq ($(CONFIG_NM),y)
CFLAGS +=   -DNODE_MAN_EN
endif

ifeq ($(CONFIG_MODULE_FW_FIREWALL),y)
CFLAGS +=   -DIPMI_FW_FIREWALL
CFLAGS +=   -DRAMTbl
endif

#OPENWSMAN
ifeq ($(CONFIG_OPENWSMAN),y)
CFLAGS +=   -DWSMAN_FEATURE
endif

#OPMA
ifeq ($(CONFIG_PLATFORM_IP1500),y)
CFLAGS +=   -DIPMI_OPMA_FEATURE
else
ifeq ($(CONFIG_PLATFORM_ADLINK_CMM),y)
CFLAGS +=   -DIPMI_OPMA_FEATURE
endif
ifeq ($(CONFIG_PLATFORM_NEXCOM_NSB7110),y)
CFLAGS +=   -DIPMI_OPMA_FEATURE
endif
endif

#Quiet build 
Q = @
# 0: static link  1:dynamic link
ifeq ($(CONFIG_BUILD_SHARE_LIB),y)
    BUILD_OPTION = 1
else 
    BUILD_OPTION = 0
endif 

ifeq ($(CONFIG_STRIP_OBJECTS),y)
    STRIP_OPTION = 1
else 
    STRIP_OPTION = 0
endif

ifeq ($(CONFIG_SPIFLASH_DRV),y)
CFLAGS += -DNVRAM_FLASH_UPDATE
endif

ifeq ($(CONFIG_COMPUTE_BLADE),y)
CFLAGS +=   -DOPEN_BLADE
endif

ifeq ($(CONFIG_CHASSIS_MANAGER),y)
CFLAGS +=   -DCHASSIS_MANAGER
endif

ifneq ($(CONFIG_LINK_FLAGS),"")
LDFLAGS += $(CONFIG_LINK_FLAGS)
endif
ifeq ($(CONFIG_DDNS),y)
CFLAGS +=   -DDDNS_FEATURE
endif
ifeq ($(CONFIG_NTP),y)
CFLAGS +=	-DNTP_FEATURE
endif

ifeq ($(CONFIG_DCMI),y)
CFLAGS +=   -DIPMI_DCMI_FEATURE
endif

ifeq ($(CONFIG_TFTP),y)
CFLAGS +=   -DATEN_TFTP_FEATURE
endif

# the paths of the library and executable file 
KERNELDIR = $(shell pwd)/Kernel/Host/$(MYMCU)/linux
MODULEPATH=$(shell pwd)/bin/module
BINPATH=$(shell pwd)/bin
LIBPATH=$(shell pwd)/lib
IMAGE_PATH= $(shell pwd)/images
MAKEFLAGS += --no-print-directory


include .include
#default inculde math library
LIBS +=  -lipmi -lchnl  -lm -lsol  -lutility -lnvram  -lipmicrypt -lcommon -lsys -lrt -luart -lupdate -lnet -lmqueue -lgpio -lxml2

#OPENWSMAN
ifeq ($(CONFIG_OPENWSMAN),y)
LIBS += -lwsman_account_handler
endif

ifeq ($(CONFIG_WDT_DRV),y)
LIBS += -lwdt
endif

ifeq ($(MYMCU), HERMON)
ifeq ($(CONFIG_PWM_DRV),y)
LIBS +=  -lpwm
endif
endif
LDFLAGS += $(LIBS) -L$(PRJ_PATH)/lib
CFLAGS += -I$(INCLUDEDIR)
HOSTPATH = OS/Linux/Host/$(MYMCU)/Board/$(BOARD)
export NM STRIP OBJDUMP OBJCOPY CC CXX LD AR RANLIB LDFLAGS ARFLAGS CFLAGS KERNELDIR CROSS_COMPILE ARCH MAKEFLAGS Q BUILD_OPTION WEBSTYLE WEBSTYLESUB STRIP_OPTION CXXFLAGS CCFLAGS
export INCLUDEDIR LIBS BOARD MYMCU PRJ_PATH MODULEPATH BINPATH LIBPATH HOSTPATH IMAGE_PATH 

BOOTLOADER-y =

ifeq ($(MYMCU), AST2050)
ifneq ($(BOARD), IP1500)
ifneq ($(BOARD), ADLINK_CMM)
ifneq ($(BOARD), NEXCOM_NSB7110)
override BOOTLOADER-y = $(PRJ_PATH)/BootLoader
endif
endif
endif
endif

ifeq ($(MYMCU), YARKON)
override BOOTLOADER-y = $(PRJ_PATH)/BootLoader
endif

#Kernel 
KERNEL-y = Kernel/

#FileSystem
FS-y = FileSystem/

#UploadImage
OUTPUT_IMG-y = MKIMG_Tool/

#IPMI module 
IPMI-y :=  $(PRJ_PATH)/libXML2 $(PRJ_PATH)/IPMI/ $(PRJ_PATH)/Utils 
#Open Blade module
STATE_MACHINE-$(CONFIG_COMPUTE_BLADE) :=  $(PRJ_PATH)/State_Machine/
CHASSIS_MANAGER-$(CONFIG_CHASSIS_MANAGER) := $(PRJ_PATH)/Chassis_Manager/

#Web Server
WEB_SERVER-$(CONFIG_WEBSERVER) := $(PRJ_PATH)/OpenSSL/ $(PRJ_PATH)/Web_Server/httpd $(PRJ_PATH)/OpenLDAP $(PRJ_PATH)/RADIUS $(PRJ_PATH)/SMTP/
WEB_PAGE-$(CONFIG_WEBSERVER) := $(PRJ_PATH)/Web_Server/
ifeq (y,$(CONFIG_WEBSERVER))
OPENWSMAN-$(CONFIG_OPENWSMAN) := $(PRJ_PATH)/libXML2 $(PRJ_PATH)/SFCC $(PRJ_PATH)/OpenWSMAN $(PRJ_PATH)/SFCB
else
OPENWSMAN-$(CONFIG_OPENWSMAN) := $(PRJ_PATH)/OpenSSL $(PRJ_PATH)/libXML2 $(PRJ_PATH)/SFCC $(PRJ_PATH)/OpenWSMAN $(PRJ_PATH)/SFCB
endif
# vUSB module and driver
vUSB_MODULE-$(CONFIG_VIRTUALUSB) := $(PRJ_PATH)/USB_VD/
# IKVM Module and Driver
IKVM_MODULE-$(CONFIG_IKVM) := $(PRJ_PATH)/IKVM
ifeq ($(CONFIG_EXT_DVI),y)
CFLAGS += -DEXT_DVI
CCFLAGS= -DEXT_DVI
CXXFLAGS= -DEXT_DVI
endif
ifeq ($(CONFIG_INT_VGA),y)
CFLAGS += -DINT_VGA
CCFLAGS= -DINT_VGA
CXXFLAGS= -DINT_VGA
endif

ifeq ($(CONFIG_UPNP),y)
CFLAGS += -DUPNP_FEATURE
endif

ifeq ($(CONFIG_LLDP),y)
CFLAGS += -DLLDP_FEATURE
endif

# SNMP
SNMP-$(CONFIG_SNMP) := $(PRJ_PATH)/SNMP

#DDNS
DDNS-$(CONFIG_DDNS) := $(PRJ_PATH)/DDNS

#NTP
NTP-$(CONFIG_NTP) := $(PRJ_PATH)/NTP

#TFTP
TFTP-$(CONFIG_TFTP) := $(PRJ_PATH)/TFTP

#UPNP
UPNP-$(CONFIG_UPNP) := $(PRJ_PATH)/UPNP

#LLDP
LLDP-$(CONFIG_LLDP) := $(PRJ_PATH)/LLDP

BUSYBOX-y = $(PRJ_PATH)/busybox/

ifneq ($(BOARD), YARKON_EVB)
DHCPV6-y = $(PRJ_PATH)/DHCPV6/
endif

JAVAAP-y = $(PRJ_PATH)/JavaAP/

#MDINFO
MDINFO-y = $(PRJ_PATH)/PKConfig/MDInfo

SMASH-$(CONFIG_SMASH) := $(PRJ_PATH)/SFCC/ $(PRJ_PATH)/SFCB/ $(PRJ_PATH)/SMASH/
OTHER_FOLDERS_FOR_EXTRACT := $(PRJ_PATH)/MKIMG_Tool/ $(PRJ_PATH)/PKConfig/ $(PRJ_PATH)/Project_File/

#build all module 
MODULE_DIR = $(KERNEL-y)\
             $(FS-y)

# the order of $(JAVAAP-y) must put before $(WEB_PAGE-y)
FW_ELEMENT_DIR = $(IPMI-y) \
		 $(vUSB_MODULE-y) \
		 $(JAVAAP-y)	 \
		 $(WEB_PAGE-y) \
		 $(IKVM_MODULE-y) \
		 $(STATE_MACHINE-y) \
		 $(CHASSIS_MANAGER-y) \
		 $(BOOTLOADER-y)

BB_ELEMENT_DIR = $(BUSYBOX-y) \
		 $(DHCPV6-y)

FS_ELEMENT_DIR = $(WEB_SERVER-y) \
		 $(SNMP-y) \
		 $(OPENWSMAN-y) \
		 $(SMASH-y) \
		 $(DDNS-y) \
		 $(FW_ELEMENT_DIR) \
		 $(NTP-y) \
		 $(TFTP-y) \
         $(UPNP-y) \
         $(MDINFO-y) \
         $(LLDP-y)

export BB_ELEMENT_DIR FS_ELEMENT_DIR
#export FS_ELEMENT_DIR
LxSYSTEM=$(addprefix _lxSYSTEM_,$(MODULE_DIR))
################################################################################
all: PreBuildTask $(LxSYSTEM)
ifeq ($(STRIP_OPTION),1)
	$(Q)$(MAKE) STRIPOBJS
endif
FileList = $(PRJ_PATH)/.Filelist
.PHONY: $(LxSYSTEM) PreBuildTask
PreBuildTask:
	@if [ ! -f $(FileList) ];then cd $(PRJ_PATH);find ./ -type f ! -wholename '*.metadata*' >$(FileList);fi	
ifeq ($(BOARD), Wistron_P92TB1)
	@-cd $(PRJ_PATH)/PKConfig/EnvTool; chmod 755 ./*; ./env_check.sh
endif
	@if [ ! -d $(CROSS_COMPILE_BIN_DIR) ]; then \
	cd $(PRJ_PATH)/ToolChain/Host/$(MYMCU); tar zxf $(TOOLCHAIN_ZIP); fi
	@if [ ! -d $(X86_CROSS_COMPILE_BIN_DIR) ]; then \
	cd $(PRJ_PATH)/ToolChain/Host/i386; tar zxf $(X86_TOOLCHAIN_ZIP); fi
	@if [ ! -d $(X86_64_CROSS_COMPILE_BIN_DIR) ]; then \
	cd $(PRJ_PATH)/ToolChain/Host/x86_64; mkdir mingw-w64; tar jxf $(X86_64_TOOLCHAIN_ZIP) -C mingw-w64; fi
	@if [ ! -d $(BINPATH) ];then  mkdir $(BINPATH); fi
	@if [ ! -d $(MODULEPATH) ];then  mkdir $(MODULEPATH); fi
	@if [ ! -d $(LIBPATH) ];then  mkdir $(LIBPATH); fi
	@if [ ! -d $(IMAGE_PATH) ];then  mkdir $(IMAGE_PATH); fi
#	@-cp $(BUSYBOX-y)/config_$(MYMCU) $(BUSYBOX-y)/config
$(LxSYSTEM):
ifeq  ($(BOARD_DEF),1)
	@cp Project_File/OS/Linux/Host/$(MYMCU)/Board/$(BOARD)/Projectfile .config
	@./conf -o PKConfig/Lx_Config/Config_all.in >>/dev/null 
	@cp .tmpconfig.h autoconfig.h
endif
	@if [ ! -f .config ] ;then echo "Please execute \"make menuconfig\"!!!!" ;exit 1;fi
	$(Q)$(MAKE) CXX="$(CXX)" CC="$(CC)" LD="$(LD)" AR="$(AR)" NM="$(NM)" OBJCOPY="$(OBJCOPY)" OBJDUMP="$(OBJDUMP)" RANLIB="$(RANLIB)" -C "$(patsubst _lxSYSTEM_%,%,$@)"
STRIPOBJS:
	@echo "Strip all objects......"
	$(call STRIPOBJS_INFOLDER, $(PRJ_PATH)/bin/*  $(PRJ_PATH)/lib/* )
	
################################################################################
install:
	@cd $(KERNEL-y); make install
	@cd $(FS-y); make install
	@cd $(OUTPUT_IMG-y); make install


clean: 
	for i in $(FW_ELEMENT_DIR); do (cd $$i && make CC=$(CC) clean); done
	rm -rf $(BINPATH) $(IMAGE_PATH);
	rm -rf .config autoconfig.h .tmpconfig.h
	@cd $(OUTPUT_IMG-y); make clean
	
clean_all: 
	for i in $(MODULE_DIR); do (cd $$i && make CC=$(CC) clean); done
	rm -rf $(BINPATH) $(IMAGE_PATH);
	rm -rf .config

include PKConfig/Lx_Script/Makefile.lib
ROOT_MODULE = $(call FIND_PATH,Makefile)

menuconfig:
	@if [ -f mconf ];then if [ ! -x mconf ];then chmod 755 mconf;fi;else echo "Lose mconf file";exit 1;fi
	@if [ -f PKConfig/Lx_Config/Config_all.in ];then ./mconf PKConfig/Lx_Config/Config_all.in;else echo "Lose Config file";fi
	@cp .tmpconfig.h autoconfig.h


