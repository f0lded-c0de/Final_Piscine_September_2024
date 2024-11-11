#!/bin/sh
loop=0
for login in $(awk -F':' '!/^#/ {print $1}' /etc/passwd ); do
	if [ $(expr $loop % 2) -ne 0 ] && [ $login != "" ]; then 
		login=$(echo $login | rev)
		echo $login"," 
	fi
	loop=$(expr $loop + 1)
done | sort -r | head -${FT_LINE2} | tail -${FT_LINE1} | tr '\n' ' ' | sed 's/, $/./g'
