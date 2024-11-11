#!/bin/bash
cat /etc/passwd | sed '/^#/d' | sed -n 'n;p' | cut -d: -f1 | rev | sort -r | awk -v var1=$FT_LINE1 -v var2=$FT_LINE2 'NR >= var1 && NR <= var2' | sed 's/$/, /' | tr -d '\n' | sed 's/, $/./'
