#!/bin/bash

kata=""

for i in `cat -A $1`; do
	j=${#i}
	k=$(($j-1))
	if [ ${i:$k} == "$" ];then
		kata=$(echo "$kata ${i:0:$k}")
		echo $kata
		kata=""
	else
		kata=$(echo "$kata $i")
	fi
done


