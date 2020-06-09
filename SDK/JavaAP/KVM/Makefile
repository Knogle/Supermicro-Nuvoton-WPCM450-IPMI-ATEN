-include $(PRJ_PATH)/.config
override CFLAGS =
override LDFLAGS =
override LIBS =

FEATURE_NAME=iKVM
FEATURE_VERSION=1.67.2.0x0
PACK_NAME=iKVM__V1.67.2.0x0.jar.pack.gz
OTHER_LIB=lib*.pack.gz

all:

install:
	@echo "=============== INSTALL $(FEATURE_NAME) ==============="
	@cp $(PACK_NAME) $(WEBFS_PATH)/$(FEATURE_NAME)__V$(FEATURE_VERSION).jar.pack.gz
ifneq ($(OTHER_LIB),)
	@cp $(OTHER_LIB) $(WEBFS_PATH)/
endif

clean:
