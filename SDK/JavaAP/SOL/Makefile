-include $(PRJ_PATH)/.config
override CFLAGS =
override LDFLAGS =
override LIBS =

FEATURE_NAME=SOL
FEATURE_VERSION=0.5.2
PACK_NAME=SOL.jar.pack.gz
OTHER_LIB=

all:

install:
	@echo "=============== INSTALL $(FEATURE_NAME) ==============="
	@cp $(PACK_NAME) $(WEBFS_PATH)/$(FEATURE_NAME)__V$(FEATURE_VERSION).jar.pack.gz
ifneq ($(OTHER_LIB),)
	@cp $(OTHER_LIB) $(WEBFS_PATH)/
endif

clean:
