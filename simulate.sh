#!/bin/bash

qt=1
if [ $1 ] ; then
	qt=$1
fi
	
for i in `seq 1 $qt`
 do
	./cript < $i.in > $i.cript
	./decript < $i.cript
	for j in {1..25}
	do
		dif=`diff $i.in $j.out`
		if [[ -z $dif ]] ; then
			k=`expr 26 - $j`
			echo "Found key for case $i: $k"
			break
		fi
	done
	sleep 1
done


