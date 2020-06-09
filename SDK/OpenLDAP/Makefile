HOST = $(subst -gcc,,$(notdir $(CROSS_COMPILE)gcc))

ifeq ($(MYMCU),YARKON)
GNU_SRC_ARG=-D_GNU_SOURCE
else
GNU_SRC_ARG=
endif
	
LDAP_SRCDIR = $(PRJ_PATH)/OpenLDAP
LDAP_ZIP    = $(wildcard $(LDAP_SRCDIR)/*.tar.gz)
LDAP_CFG    =  --with-tls=openssl --without-kerberos --disable-debug --without-cyrus-sasl \
--without-threads --disable-slapd --disable-slurpd --disable-shared \
-host=${HOST} \
CFLAGS="-I$(PRJ_PATH)/OpenSSL/openssl/local/include" \
CPPFLAGS="-I$(PRJ_PATH)/OpenSSL/openssl/local/include $(GNU_SRC_ARG)" \
LDFLAGS="-L$(PRJ_PATH)/OpenSSL/openssl/local/lib -lcrypto -lssl"

#--prefix=$(LDAP_SRCDIR)/openldap/local 
LIBNAME = libldap_client.so


override CFLAGS = 
override LDFLAGS = 
override LIBS =
all:
	$(Q)echo "******************** make OpenLDAP ********************"
	$(Q)echo "CFLAGS = $(CFLAGS)"
	$(Q)cd $(LDAP_SRCDIR); \
	if [ ! -d openldap ];then mkdir openldap;cd openldap;tar zxf $(LDAP_ZIP);fi
	$(Q)cd $(LDAP_SRCDIR)/openldap;if [ ! -f $(LDAP_SRCDIR)/openldap/libraries/libldap/.libs/libldap.a ];then \
	./configure $(LDAP_CFG); make depend; make;fi
	$(Q)cd $(LDAP_SRCDIR); \
	if [ ! -d $(LIBPATH) ]; then mkdir $(LIBPATH); fi
	${CC} -shared -o $(LIBPATH)/$(LIBNAME) ldap_client.c -I$(LDAP_SRCDIR)/openldap/include \
	-L$(LDAP_SRCDIR)/openldap/libraries/libldap/.libs -lldap \
	-L$(LDAP_SRCDIR)/openldap/libraries/liblber/.libs -llber
	$(CROSS_COMPILE)strip $(LIBPATH)/$(LIBNAME)
install:
	$(Q)echo "************** copy OpenLDAP config to FS*************"
	$(Q)if [ ! -d  $(FS_PATH)/usr/local/etc ];then mkdir $(FS_PATH)/usr/local/etc; fi
	$(Q)cd $(LDAP_SRCDIR); cp -r openldap-config $(FS_PATH)/usr/local/etc/openldap
	$(Q)echo "OpenLdap finish"
clean:
	$(Q)echo "******************** clean OpenLDAP ********************"
	$(Q)if [ -d $(LDAP_SRCDIR)/openldap ];then \
	cd $(LDAP_SRCDIR)/openldap; make clean; fi
	

