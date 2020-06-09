HTTPD_SRCDIR = $(PRJ_PATH)/Web_Server/httpd
HTTPD_ZIP    = $(wildcard $(HTTPD_SRCDIR)/lighttpd*.tar.gz)

LIGHTTPD_HOST   = --host=$(subst -gcc,,$(notdir $(CROSS_COMPILE)gcc))
LIGHTTPD_PREFIX = --prefix=$(HTTPD_SRCDIR)/lighttpd/local --exec-prefix=$(HTTPD_SRCDIR)/lighttpd/local
LIGHTTPD_CONF   = --with-openssl=$(PRJ_PATH)/OpenSSL/openssl/local/ssl \
--without-zlib --without-bzip2 --without-pcre \
--with-openssl-includes=$(PRJ_PATH)/OpenSSL/openssl/local/include \
--with-openssl-libs=$(PRJ_PATH)/OpenSSL/openssl/local/lib


override CFLAGS = 
override LDFLAGS =
override LIBS =

all:

install:
#copy httpd
	$(Q)echo "******************** make httpd ********************"
	$(Q)if [ ! -d $(HTTPD_SRCDIR)/lighttpd ];then cd $(HTTPD_SRCDIR); tar zxvf $(HTTPD_ZIP); fi
	$(Q)if [ ! -d $(HTTPD_SRCDIR)/lighttpd/local ]; then \
	cd $(HTTPD_SRCDIR)/lighttpd; \
	./configure $(LIGHTTPD_HOST) $(LIGHTTPD_PREFIX) $(LIGHTTPD_CONF); \
	make; make install; make install-strip; fi
	$(Q)echo "******************** build httpd ********************"
	$(Q)if [ ! -d  $(FS_PATH)/usr/local/httpd ];then \
	mkdir $(FS_PATH)/usr/local/httpd; fi
	$(Q)cd $(HTTPD_SRCDIR); \
	cp -f server.pem $(FS_PATH)/usr/local/httpd/; \
	cp -f lighttpd.conf $(FS_PATH)/usr/local/httpd/; \
	cp -rf lighttpd/local/*  $(FS_PATH)/usr/local/httpd/
	
clean:
	$(Q)echo "******************** clean httpd ********************"
	$(Q)if [ -d $(HTTPD_SRCDIR)/lighttpd ];then \
	cd $(HTTPD_SRCDIR)/lighttpd; make clean; rm -rf local; fi


