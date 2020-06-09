#override CFLAGS = -Wall -O3
CFLAGS += -O3
LDFLAGS += -lpthread

#execute file name 
OBJS=


all: $(OBJS)
	@echo " LD usb"
	$(Q)$(CC) $(CFLAGS) USB.o -o $(BINPATH)/usb $(LDFLAGS)
	@echo " LD uima"
	$(Q)$(CC) $(CFLAGS) uima.o -o ${BINPATH}/uima $(LDFLAGS)
	@echo " LD uiso"
	$(Q)$(CC) $(CFLAGS) uiso.o mmcInterface.o mmcCommand.o -o ${BINPATH}/uiso $(LDFLAGS)
	
install:



