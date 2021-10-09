#! /bin/sh
CORECOUNT=$(sysctl hw.ncpu | cut -d" " -f 2)
CORE=0
VAL=0

while [ $CORE -lt $CORECOUNT ]; do	
	LOAD=$(sysctl dev.cpu.$CORE.cx_usage | cut -d" " -f 2 | cut -d"." -f 1)

	if [ $VAL -eq 0 ]; then
		VAL=$LOAD
		continue		
	fi
	LOAD=$(expr $(expr $VAL + $LOAD) / 2) 

	CORE=$(expr $CORE + 1)
done

echo $LOAD
