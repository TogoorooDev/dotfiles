while true
do
	datestr=`date '+%a, %x'`
	timestr=`date '+%H:%M'`
	
	cpuavgload=`uptime | sed -n 's/.*: //; s/, .*// p'`

	batcurrent=`sed -n 's/ mAh//; s/remaining[ a-z:]*// p' /proc/acpi/battery/BAT1/state`
	batfull=`sed -n 's/ mAh//; s/last full[ a-z:]*// p' /proc/acpi/battery/BAT1/info`
	batpercent=`echo "($batcurrent*100)/$batfull" | bc`
	if [ $batpercent -lt 10 ]
		then batpercent=`echo [c]$batpercent%[c]`
		else batpercent=`echo $batpercent%`
	fi
	
	audiofront=`amixer sget Front | sed -n 's/\] \[[^%]*\]//; s/[ ]*Front Left: Playback [0-9]* \[// p'`

	mailnew=`claws-mail --status inbox | sed -n 's/ [ 0-9ClawsMinotrug\.]*// p'`

	echo -e NEW mail: $mailnew \| VOL front: $audiofront \| BAT:[i]$batpercent[i]\| CPU: $cpuavgload \| $datestr[c]$timestr

	sleep 2
done | dwm

