#! /bin/sh

if [ "$1" = "absolute" ]; then	
	MB=$(top -d1 | grep "Mem" | cut -d" " -f 10) 
	GB=$(units -t "$MB megabytes" gigabytes)
	SHORTGB=$(printf %.3s "$GB")

	echo $SHORTGB
fi

if [ "$1" = "percentage" ]; then
	FREEMB=$(top -d1 | grep "Mem" | cut -d" " -f 10 | cut -d"M" -f 1) 
	INSTBYTES=$(sysctl hw.physmem | cut -d" " -f 2)
	INSTMB=$(units -t "$INSTBYTES bytes" megabytes | cut -d"." -f 1)
	#echo $FREEMB
	#echo $INSTM
	LFREEMB=$(expr $FREEMB \* 100)
	PERC=$(expr $LFREEMB / $INSTMB)
	echo $PERC

fi
