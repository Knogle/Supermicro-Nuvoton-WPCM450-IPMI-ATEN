HOST = $(subst -gcc,,$(notdir $(CROSS_COMPILE)gcc))
LIBNAME = libradius_client.so

all:
	$(Q)echo "******************** make RADIUS ********************"
	${CC} -shared -o $(LIBPATH)/$(LIBNAME) -I. util.c md5.c dict.c radius_client.c
install:
	$(Q)echo "************** nothing to do *************"

clean:
	$(Q)echo "******************** clean RADIUS ********************"
	$(Q)rm -f radtest


