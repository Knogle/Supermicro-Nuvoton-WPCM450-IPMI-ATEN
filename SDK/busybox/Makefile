BUSY_SRCDIR = $(PRJ_PATH)/busybox/
#BUSY_ZIP   = $(wildcard $(BUSY_SRCDIR)/*.tar.gz)


BUSY_ZIP   = $(BUSY_SRCDIR)/busybox-1.12.0.tar.gz

CONFIG_FILE_NAME = config_$(MYMCU)


override CFLAGS = 
override LDFLAGS =

all:
	
install:
	$(Q)echo "******************** build busybox ********************"
#copy busybox
	$(Q)if [ ! -d busybox ];then \
	mkdir busybox; cd busybox;tar zxf $(BUSY_ZIP);fi
	$(Q)cp $(CONFIG_FILE_NAME) busybox/.config
	$(Q)cd busybox; make > ../busybox.log 2>&1; make install >> ../busybox.log 2>&1 ; cp -a _install/*  $(FS_PATH)/; 
	
clean:
	$(Q)echo "******************** clean busybox ********************"
	$(Q)if [ -d $(BUSY_SRCDIR)/busybox ];then \
	cd $(BUSY_SRCDIR)/busybox; make clean; fi


