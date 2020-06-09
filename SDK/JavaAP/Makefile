ANT_ZIP            = apache-ant-1.7.1-bin.tar.gz
ANT_BIN            = $(ANT_HOME)/bin
ANT                = $(ANT_BIN)/ant
CN                 = Shu-Yu Fu
OU                 = RD1
O                  = ATEN
C                  = TW


all:
	@$(MAKE) -C KVM;

init_jdk:

init_ant:

genkey: init_jdk

install: init_jdk init_ant #genkey
	@$(MAKE) install -C KVM;
	@$(MAKE) install -C SOL;

clean:
	@rm -rf $(ANT_HOME);
	@$(MAKE) clean -C KVM;
	@$(MAKE) clean -C SOL;


