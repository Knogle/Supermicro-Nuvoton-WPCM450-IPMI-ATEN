#!/bin/sh
PATH=/SMASH:/SFCB/local/bin:/SFCB/local/sbin:/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin
export PATH
cp_files="bmc_hostname ddns SDRBlock FWBlock PSBlock MouseMode network ntp resolv.conf server.pem timezone vm_image.conf wsman"
#1.for factory default setting
#rm_files is defined in SM_SRC\Utils\Host\HERMON\Board\(board defined)\define_var.sh
if [ $1 == '1' ]; then
	source define_var.sh
	for file in $rm_files
	do
		rm -r "/nv/"$file 
	done
#2.for save ipmi config
#process who calls this script need to putenv of $SAVE_CONF_DIR $TARGET_FOLDER $SAVE_TAG_PATH...
elif [ $1 == '0' ]; then
	for file in $cp_files 
	do
		if [ ! -d "$SAVE_CONF_DIR/$TARGET_FOLDER" ]; then
			mkdir $SAVE_CONF_DIR/$TARGET_FOLDER
		fi
		cp -rdf "/nv/"$file $SAVE_CONF_DIR/$TARGET_FOLDER
	done
	cp $SAVE_XML_PATH $SAVE_CONF_DIR/$TARGET_FOLDER
	cp $SAVE_TAG_PATH $SAVE_CONF_DIR/$TARGET_FOLDER
	dmesg > /tmp/log
	cp -rdf /tmp/log  $SAVE_CONF_DIR/$TARGET_FOLDER
	cd /tmp
	tar -zcvf $SAVE_CONF_DIR/$SAVE_TARGET_ZIP ./$TARGET_FOLDER/ > /dev/null
	mv $SAVE_CONF_DIR/$SAVE_TARGET_ZIP $SAVE_CONF_DIR/$SAVE_TARGET_BIN
	rm -r $SAVE_CONF_DIR/$TARGET_FOLDER
#3.for reload ipmi config
#cd /tmp and decompress the target file and replace the files in /nv 
#process who calls this script need to putenv of $SAVE_CONF_DIR $TARGET_FOLDER $TARGET_FILE
elif [ $1 == '2' ]; then
	cd $SAVE_CONF_DIR
	tar zxvf $SAVE_CONF_DIR/$TARGET_FILE > /dev/null
	if [ $? -ne 0 ];then
	echo "tar_fail"
	return
	fi
	for file in $cp_files
	do
		if [ $file != "SDRBlock" ]; then
		rm -r /nv/$file
		cp -rdf $SAVE_CONF_DIR/$TARGET_FOLDER/$file /nv
		fi
	done
fi