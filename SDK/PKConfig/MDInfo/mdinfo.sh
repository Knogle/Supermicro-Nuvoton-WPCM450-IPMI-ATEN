#!/bin/bash
# note: if cpu is yarkon, it will exit mdinfo script
[ "$1" == "2" ] && exit0
echo "MDINFO tag:"
version=$2
FWv1=$(echo $version | cut -d '.' -f 1)
FWv2=$(echo $version | cut -d '.' -f 2)
v1errflag=1
v2errflag=1
while [ "$v1errflag" == "1" -o "$v2errflag" == "1" ]
do
 FWv1size=${#FWv1}
 FWv2size=${#FWv2}
 FWv1data=$(echo $FWv1 | grep '^[0-9a-fA-F]*[0-9a-fA-F]$')
 FWv2data=$(echo $FWv2 | grep '^[0-9a-fA-F]*[0-9a-fA-F]$')
 if [ "$FWv1size" -gt "2" ]; then
  echo "-->error length: Firmware revision_1 (1 byte in HEX)"
 else
  v1errflag=0
 fi
 if [ "$FWv2size" -gt "2" ]; then
  echo "-->error length: Firmware revision_2 (1 byte in HEX)"
 else
  v2errflag=0
 fi
 if [ -z "$FWv1data" ]; then
  echo "-->error format: Firmware revision_1 (1 byte in HEX)"
  v1errflag=1
 fi
 if [ -z "$FWv2data" ]; then
  echo "-->error format: Firmware revision_2 (1 byte in HEX )"
  v2errflag=1
 fi 
 if [ "$v1errflag" == "1" -o "$v2errflag" == "1" ]; then
 read -p "please input Firmware revision_1 (1 byte in HEX): " FWv1
 read -p "please input Firmware revision_2 (1 byte in HEX): " FWv2
 [ -z "$FWv1" ] && FWv1=0
 [ -z "$FWv2" ] && FWv2=0
 fi
done
echo "Firmware revision is $FWv1.$FWv2"
if [ "$1" == "0" ]; then
cd ../PKConfig/MDInfo/;./mdinfo -c 0 -v $FWv1 -m $FWv2 -f ../../images/HERMONEVB_all.bin
fi
if [ "$1" == "1" ]; then
cd ../PKConfig/MDInfo/;./mdinfo -c 1 -v $FWv1 -m $FWv2 -f ../../images/AST2050_all.bin
fi
mv *.bin ../../images
