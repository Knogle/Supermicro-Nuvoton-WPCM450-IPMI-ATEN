-include $(PRJ_PATH)/.SDKPath 
SDK_SRCS =$(SDKSRCS) $(SDKSRHS) $(SDKOBJS)
CONFIGFILE = $(SDKPATH)/DRVConfig.in
#OBJS_PATH =$(strip  $(EXTRPATH)/$(FOLDER))
CONFIGNAME = $(subst /,_,CONFIG_$(FOLDER))
MAKETEMPLATE = Makefile.drv
include $(PRJ_PATH)/PKConfig/Lx_Script/Makefile.lib

FOLDER_TOKEN = $(subst /, ,$(FOLDER))
TOKEN_NUM = $(words $(FOLDER_TOKEN))
SDK_FOLDER =  $(word 1,$(FOLDER_TOKEN))
MAIN_FOLDER = $(word 2,$(FOLDER_TOKEN))
FUNC_FOLDER = $(subst $(SDK_FOLDER)/$(MAIN_FOLDER)/,,$(FOLDER))
OBJS_PATH =$(strip  $(SDKPATH)/$(MAIN_FOLDER)/$(FUNC_FOLDER))

extract:
	@$(ADDOBJLIST)
	@if [ $(TOKEN_NUM) -gt 2 ];then \
	if [ -f $(SDKPATH)/$(MAIN_FOLDER)/config.in ];then \
	echo "DRIVER_BUILD-y += $(FUNC_FOLDER)" >> $(SDKPATH)/$(MAIN_FOLDER)/config.in; \
	else echo "DRIVER_BUILD-y := $(FUNC_FOLDER)" > $(SDKPATH)/$(MAIN_FOLDER)/config.in;fi \
	;fi


clean:
	@echo "[DRV] CLEAN" $(obj-m) 
	$(Q)rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions
