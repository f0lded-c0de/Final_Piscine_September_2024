#!/bin/sh
loop=0
ls -l | while read line; do
	if [ $(expr $loop % 2) -eq 0 ]; then
		echo "$line"
	fi
	loop=$(expr $loop + 1)
done 
