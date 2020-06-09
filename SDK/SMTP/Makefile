HOST = $(subst -gcc,,$(notdir $(CROSS_COMPILE)gcc))
SMTP_SRCDIR = $(PRJ_PATH)/SMTP
SMTP_ZIP    = $(wildcard $(SMTP_SRCDIR)/*.tar.gz)
SMTP_CFG    = --host=${HOST} -with-ssl=openssl --libdir=$(PRJ_PATH)/OpenSSL/openssl/lib/


override CFLAGS = 
override LDFLAGS = 
override LIBS =

all:
	$(Q)echo "******************** make SMTP ********************"
	$(Q)echo "CC=" $(CC)
	$(Q)echo "AR=" $(AR)
	$(Q)cd $(SMTP_SRCDIR); \
	if [ ! -d smtp ];then mkdir smtp;cd smtp;tar zxf $(SMTP_ZIP);fi
	$(Q)cd $(SMTP_SRCDIR)/smtp;if [ ! -f $(SMTP_SRCDIR)/smtp/src/msmtp ];then \
	./configure $(SMTP_CFG);make;fi
	$(CROSS_COMPILE)strip $(SMTP_SRCDIR)/smtp/src/msmtp
	$(Q)cp $(SMTP_SRCDIR)/smtp/src/msmtp $(BINPATH)/msmtp
	$(Q)cp $(SMTP_SRCDIR)/smtpclient.sh $(BINPATH)/
install:
	#******************************do nothing***************************
clean:
	$(Q)echo "*************** clean SMTP ********************"
	$(Q)if [ -d $(SMTP_SRCDIR)/smtp ];then \
	cd $(SMTP_SRCDIR)/smtp; make clean; fi
	

