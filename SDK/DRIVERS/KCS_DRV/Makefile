include $(PRJ_PATH)/.config
#include $(PRJ_PATH)/.ProjectName

OBJS-$(CONFIG_KCS_DRV) = kcs_drv.ko
OBJS := $(OBJS-y)
#please add the drivers here
#ex. SOURCES-y += XXX.c 

obj-m = $(patsubst %.c,%.o,$(SOURCES-y))
ifneq ($(KERNELRELEASE),)
# Pass some build information to Kernel like CFLAGS or LDFLAGS
EXECUTABLE = 
CFLAGS += -D__KERNEL__ -DMODULE  -Wall -DEXPORT_SYMTAB -O2  
#CFLAGS +=  -I$(PRJ_PATH)/SDKFILES/$(PRJNAME)/inc/

else
override LDFLAGS =
EXECUTABLE = 
all:
ifneq ($(obj-m),)
	$(Q)$(MAKE) -C "$(KERNELDIR)/linux" M=$(shell pwd) modules
endif
	@if [ ! -d $(MODULEPATH) ]; then mkdir -p  $(MODULEPATH); fi
	@if [ ! -z "$($(firstword OBJS))" ];then cp $(OBJS) $(MODULEPATH)/; fi	
endif

clean:

#include $(PRJ_PATH)/rule.mk
