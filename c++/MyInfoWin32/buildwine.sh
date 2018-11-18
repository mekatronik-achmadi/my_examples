#!/bin/bash

export EXENAME=${1}

if [ ! -f /usr/bin/winemaker ];then
	echo "winemaker not found"
	exit
fi

if [ ! -f /usr/bin/winegcc ];then
	echo "winegcc not found"
	exit
fi

if [ ! -f /usr/bin/sed ];then
	echo "script editor not found"
	exit
fi

if [ -z "$EXENAME" ];then
	echo "usage: ./buildwine.sh EXE_NAME"
	exit
fi

winemaker --lower-all --lower-include --nomfc --windows --wine32 .
sed -i "s#LDFLAGS= -mwindows#LDFLAGS= -shared -mwindows#g" Makefile
export OUTNAME=$(cat Makefile | grep -w "EXES                  =" | cut -f2 -d\= | tr -d '[:space:]')
sed -i "s#$OUTNAME#$EXENAME#g" Makefile
#make
#rm -f $EXENAME.exe
#cp -f $EXENAME.exe.so $EXENAME.exe
