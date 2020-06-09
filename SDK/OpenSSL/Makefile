SSL_SRCDIR = $(PRJ_PATH)/OpenSSL
SSL_ZIP    = $(wildcard $(SSL_SRCDIR)/*.tar.gz)
SSL_CFG    = no-asm no-camellia no-gmp no-krb5 no-mdc2 no-rc5 no-rfc3779 no-seed \
shared no-tlsext no-zlib --prefix=$$PWD/local/ --openssldir=$$PWD/local/ssl
SSL_MFG    = AR="$(CROSS_COMPILE)ar r"


override CFLAGS = 
override LDFLAGS =

all:
	$(Q)echo "******************** make OpenSSL ********************"
	$(Q)cd $(SSL_SRCDIR); \
	if [ ! -d openssl ];then mkdir openssl; cd openssl;tar zxf $(SSL_ZIP); mkdir lib; fi
	$(Q)cd $(SSL_SRCDIR)/openssl; if [ ! -f $(SSL_SRCDIR)/openssl/local/lib/libssl.so ];then ./config $(SSL_CFG); make $(SSL_MFG);\
	make install; $(STRIP) local/lib/*.so.*; $(STRIP) apps/openssl; cp libcrypto.so libssl.so lib; fi;\
	if [ ! -d $(TC_LOCAL)/lib/pkgconfig ];then mkdir $(TC_LOCAL)/lib/pkgconfig;fi;\
	cp -f local/lib/pkgconfig/* $(TC_LOCAL)/lib/pkgconfig/ 

install:
#copy OpenSSL
	$(Q)echo "******************** build OpenSSL ********************"vvvvv
	$(Q)cp $(SSL_SRCDIR)/openssl/local/lib/libcrypto.so.0.9.8 $(FS_PATH)/lib/
	$(Q)cp $(SSL_SRCDIR)/openssl/local/lib/libssl.so $(FS_PATH)/lib/
	$(Q)ln -s libssl.so libssl.so.0.9.8
	$(Q)mv -f libssl.so.0.9.8 $(FS_PATH)/lib/
	$(Q)ln -s libcrypto.so.0.9.8 libcrypto.so
	$(Q)mv -f libcrypto.so $(FS_PATH)/lib/
	$(Q)cp $(SSL_SRCDIR)/openssl/apps/openssl $(FS_PATH)/bin
clean:
	$(Q)echo "******************** clean OpenSSL ********************"
	$(Q)if [ -d $(SSL_SRCDIR)/openssl ];then \
	cd $(SSL_SRCDIR)/openssl; make clean; rm -rdf local; fi


