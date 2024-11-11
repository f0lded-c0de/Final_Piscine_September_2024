ifconfig -a | awk '/ether/ {printf("%s\n",$2)}'
