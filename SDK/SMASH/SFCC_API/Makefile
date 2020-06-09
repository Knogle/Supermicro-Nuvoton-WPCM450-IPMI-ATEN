SMASHDIR = $(PRJ_PATH)/SMASH/SMASH
CCPREFIX = ../../SFCC/sfcc
CB_SRC = $(PRJ_PATH)/SFCB
CCEXECPREFIX =  $(CCPREFIX)/local
CCINCDIR1 = $(CCEXECPREFIX)/include/CimClientLib
CCINCDIR2 = $(CCEXECPREFIX)/include/cimc
CCLIBDIR = $(CCEXECPREFIX)/lib
CURLLIBDIR = $(PRJ_PATH)/SFCC/curl/local/lib
INSTALLDIR = $(SMASHDIR)/lib

SONAME = libSFCC_API.so
LIBNAME = libSFCC_API.so.4
TARGET = $(SONAME)

#ifdef (DEBUG)
DEBUGFLAGS = -g -DDEBUG
#else
#DEBUGFLAGS =
#endif

DEFS = -D_REENTRANT
LIBS = -L$(CCLIBDIR) -lpthread -lcmpisfcc -lcimcclient #-lcimcClientXML -lcurl -L$(CURLLIBDIR)

#LIB += -lmulti

INCLUDES = -I$(CCINCDIR1) -I$(CCINCDIR2)
CXX = $(CROSS_COMPILE)gcc
CXXFLAGS = $(DEBUGFLAGS) $(INCLUDES) $(DEFS) -Wall -fPIC

SRCS = SFCC_API.c \
show.c


#LIBS +=  -lipmi -lchnl  -lm -lsol  -lutility -lnvram  -lipmicrypt -lcommon -lsys -lrt -luart -lupdate -llan -lmqueue -lgpio
LDFLAGS = $(LIBS) 
#-L$(PRJ_PATH)/lib

OBJS = $(addsuffix .o, $(basename $(SRCS)))

.SUFFIXES : .o .c

$(TARGET):      $(LIBNAME) $(OBJS)
	cd $(INSTALLDIR); \
	if test ! -e $(SONAME); then \
		ln -s $(LIBNAME) $(SONAME); \
	fi

$(LIBNAME):     $(OBJS)
	cp *.o $(INSTALLDIR) && \
	$(CXX) -shared -Wl,-soname,$(SONAME) -o $(LIBNAME) $(OBJS) $(LDFLAGS)
	mv $(LIBNAME) $(INSTALLDIR)

.c.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ && \
	cp $@ $(INSTALLDIR)

clean:
	if [ -d $(SMASHDIR) ];then \
        rm -rf $(SMASHDIR); fi
	@rm -f *.o &> /dev/null
	@rm -f util/*.o &> /dev/null
	@rm -f /test/* &> /dev/null
