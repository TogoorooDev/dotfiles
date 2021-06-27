#! /bin/sh

MONCOUNT=$( xrandr -q | grep "connected" | grep -v "disconnected" | wc | cut -d" " -f 7 )

if [ $MONCOUNT -eq 2 ]; then
	xrandr --output eDP --primary --mode 1920x1080 --output HDMI-A-0 --mode 1600x900 --rotate normal --left-of eDP
	polybar monbar -r &
fi

nitrogen --restore &
polybar laptopbar -r &
export $(dbus-launch)
xautolock -locker slock -time 5 -notify 90 -notifier "brillo -S 0" &

exec bspwm
