#!/bin/bash

export EXENAME=${1}

if [ ! -f /usr/bin/winemaker ];then
	echo "winemaker not found"
	exit
fi

#if [ ! -f /usr/bin/winegcc ];then
#if [ ! -f /usr/bin/x86_64-w64-mingw32-gcc ];then
if [ ! -f /usr/bin/i686-w64-mingw32-gcc ];then
	echo "mingw32-gcc not found"
	exit
fi

if [ ! -f /usr/bin/sed ];then
	echo "script editor not found"
	exit
fi

if [ -z "$EXENAME" ];then
	echo "usage: ./make_mingw32.sh EXE_NAME"
	exit
fi

winemaker --lower-all --lower-include --nomfc --wine32 -luser32 .

export OUTNAME=$(cat Makefile | grep -w "EXES                  =" | cut -f2 -d\= | tr -d '[:space:]')

sed -i "s#$OUTNAME#$EXENAME.exe#g" Makefile

sed -i "s#winegcc#i686-w64-mingw32-gcc#g" Makefile
sed -i "s#wineg++#i686-w64-mingw32-g++#g" Makefile

sed -i "s#AR = ar#AR = i686-w64-mingw32-ar#g" Makefile
sed -i "s#RC = wrc#RC = i686-w64-mingw32-windres#g" Makefile

sed -i "s#-mno-cygwin#-static-libgcc#g" Makefile
# make
