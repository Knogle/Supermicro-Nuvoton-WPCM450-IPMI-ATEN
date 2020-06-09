-include $(PRJ_PATH)/.config
-include $(PRJ_PATH)/.machine

TOOL_PATH   = $(PRJ_PATH)/MKIMG_Tool/Host/$(MYMCU)/Board/$(BOARD)
WORK_PATH   = $(PRJ_PATH)/MKIMG_Tool/tmp

HOST_CC    = gcc 
CHECK_CC_RULE = $(shell if $(HOST_CC) $(1)  -S -o /dev/null -xc /dev/null  > /dev/null 2>&1 ;then echo $(1) ;fi)
HOST_CC_CFLAG    = $(call CHECK_CC_RULE,-fno-stack-protector)


#u-boot MYMCUTYPE 1
ifeq ($(MYMCU),YARKON)
MYMCUTYPE=2
endif
ifeq ($(MYMCU),AST2050)
MYMCUTYPE=1
endif
#bootloader MYMCUTYPE 0
ifeq ($(MYMCU),HERMON)
MYMCUTYPE=0
endif
FWVERSION=$(ver)
#IMAGE_PATH
install:
	$(Q)echo "HOSTCC mkbin"
	$(Q)gcc $(HOST_CC_CFLAG)  mkbin.c -o mkbin

ifeq ($(MYMCU),AST2050)
	$(Q)cd $(IMAGE_PATH); mv uImage.bin kernel.bin;
endif
ifeq ($(MYMCU),HERMON)
	$(Q)cd $(TOOL_PATH)/../..;$(HOST_CC) mkimage.c -o mkimage;cp -rf mkimage $(TOOL_PATH)
	$(Q)cd $(IMAGE_PATH); mv image.bin kernel.bin;
endif
ifeq ($(BOARD),SuperMicro_X7SB3)
	$(Q)cd $(TOOL_PATH); chmod 744 ./BTL_diff_test.sh; \
	./BTL_diff_test.sh $(PRJ_PATH)/FileSystem/Host/$(MYMCU)/Board/$(BOARD)/BTL $(TOOL_PATH)/bootloader_pcb_rev_b.bin
endif
ifeq ($(MYMCU),YARKON)
	$(Q)cd $(IMAGE_PATH); mv uImage.bin kernel.bin;
endif
	$(Q)if [ -d $(WORK_PATH) ];then rm -rf $(WORK_PATH); fi
	$(Q)mkdir $(WORK_PATH);cp $(TOOL_PATH)/* $(WORK_PATH)/ -rf
	$(Q)cp $(IMAGE_PATH)/* $(WORK_PATH)/ -rf
	$(Q)cp $(PRJ_PATH)/MKIMG_Tool/mkbin $(WORK_PATH)/
	$(Q)cd ${WORK_PATH};sh ${WORK_PATH}/cmd_script.sh
	$(Q)if [ ! -z  $(IMAGE_PATH) ] && [ -d  $(IMAGE_PATH) ] ;then \
	rm -f $(IMAGE_PATH)/*; \
	cd ${WORK_PATH};cp *.bin $(IMAGE_PATH)/; fi
	$(Q)rm -rf $(WORK_PATH)
	$(Q)bash $(PRJ_PATH)/PKConfig/MDInfo/mdinfo.sh $(MYMCUTYPE) $(FWVERSION)
clean:	
	$(Q)if [ -d $(IMAGE_PATH) ]; then \
	rm -rf $(WORK_PATH); fi	


