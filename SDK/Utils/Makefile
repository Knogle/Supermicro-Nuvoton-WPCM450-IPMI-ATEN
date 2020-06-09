-include $(PRJ_PATH)/.config
-include $(PRJ_PATH)/.machine
#execute file name 
EXECUTABLE = LanNotifier 
OBJS= LanNotifier.o
OBJS_LIST = $(OBJS)  savefromPS.o restoretoPS.o cmd.o

CFLAGS+=-I$(PRJ_PATH)/libXML2/libxml2/local/include/libxml2/
SH_DIR  = $(PRJ_PATH)/Utils/Host/$(MYMCU)/Board/$(BOARD)

all:  $(OBJS_LIST)
	@echo " LD "$(EXECUTABLE)
	$(Q)$(CC)  $(OBJS) -o $(BINPATH)/$(EXECUTABLE) $(LDFLAGS)
	@echo " LD save"
	$(Q)$(CC) savefromPS.o  -o $(BINPATH)/save $(LDFLAGS) 
	@echo " LD restore"
	$(Q)$(CC) restoretoPS.o  -o $(BINPATH)/restore $(LDFLAGS) 
	@echo " LD CMD"
	$(Q)$(CC) cmd.o  -o $(BINPATH)/cmd $(LDFLAGS) 

install:
	#******************************copy script***************************	
	@echo "copy restore_file.sh"
	$(Q)cp restore_file.sh $(FS_PATH)/bin
ifeq ($(CONFIG_PLATFORM_SUPERMICRO_SUBVERSION_X8DTT),y)
	@echo "copy $(SH_DIR)/$(SUBBOARD)/define_var.sh"
	$(Q)cp $(SH_DIR)/$(SUBBOARD)/define_var.sh $(FS_PATH)/bin
else
	@echo "copy $(SH_DIR)/$(SUBBOARD)/define_var.sh"
	$(Q)cp $(SH_DIR)/define_var.sh $(FS_PATH)/bin
endif


