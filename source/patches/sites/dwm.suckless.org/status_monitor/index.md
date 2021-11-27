status monitor
==============
The status bar text of dwm is stored in the WM\_NAME X11 property of the
root window, which is managed by dwm.

It can be easily set and retrieved using standard Unix tools.

	xsetroot -name $status

	xprop -root -notype -f WM_NAME "8u" \
		| sed -n -r 's/WM_NAME = \"(.*)\"/\1/p'

Set The Status Using A Shell Script
-----------------------------------
	while true; do
		xsetroot -name "$(date)"
		sleep 2
	done

Set The Status Using Other Methods
----------------------------------
There are two status monitors maintained at suckless:

slstatus - suckless status
--------------------------
A somewhat complex status monitor which includes all batteries.

You can read more [on the project page](//tools.suckless.org/slstatus/).

dwmstatus
---------
Barebone status monitor with basic functions written in C. This follows the
suckless philosophy, to give you an easy way to extend the source code to your
needs. See the helper functions for C below, to extend it to your needs. Just
check it out and keep on hacking.

	git clone git://git.suckless.org/dwmstatus
	cd dwmstatus
	make
	make PREFIX=/usr install
	# add »dwmstatus 2>&1 >/dev/null &« to your .xinitrc

Status Monitors Submitted By Others
-----------------------------------
Feel free to add your own status monitors here (keeping the list sorted).

* [akuma-v-dwm](https://gitlab.com/narvin/avd) - event driven, modular,
  and extensible with date/time, all batteries, volume (amixer), backlight,
  memory and cpu usage out of the box.
* [barM](barM.c) - can display all, time/date, ram usage, output of commands (the New BarMonitor).
* [dsblocks](https://github.com/ashish-yadav11/dsblocks) - modular status
  monitor, written and meant to be configured in C, with support for signaling,
  clickability, cursor hinting and color.
* [dstat](https://www.umaxx.net/dl)
  [Screenshot](https://www.umaxx.net/dstat.png) - displays the current network
  throughput, CPU usage, performance settings, battery status, temperature,
  volume settings, as well as the current date and time (OpenBSD only, no support
  for Linux).
* [dwm-bar](https://github.com/joestandring/dwm-bar) - modular status bar.
  modules for date/time, alsa volume, cmus track, countdown timer,
  current keyboard layout, mail count, system resources, and weather.
* [dwmblocks](https://github.com/torrinfail/dwmblocks) - i3blocks-like
  status bar where you can refresh each "block" independently by update time
  or signal.
* [dwmblocks](https://github.com/ashish-yadav11/dwmblocks) - rewrite of
  dwmblocks with added features including clickability, cursor hinting and
  color.
* [dwms](https://github.com/ianremmler/dwms) - displays time, network, audio,
  and battery status, written in Go using XGB.
* [dwmsd](https://github.com/johnko/dwmsd) - a daemon that listens on localhost
  tcp (may be useful as a base for asynchronous updates)
* [dwm-sss](https://github.com/roadkillcat/dwm_sss) - shell script providing
  date, time and CPU temperature
* [dwmstat](https://notabug.org/kl3/dwmstat) - small and simple | IP, CPU
  temperature, system volume, current local time (and more) | config.h | OpenBSD
* [goblocks](https://github.com/Stargarth/Goblocks) - Partially inspired by dwmblocks,
  Go status bar that allows you to refresh each block independently. Includes built in
  features for frequently refreshed blocks.
* [gocaudices](https://github.com/lordrusk/gocaudices) - dwmblocks alternative written in go,
Gocaudices is a dwmblocks replacement meant to be simple, fast, and elegant. It tries to adhere
to the suckless philosophy.
* [go-dwmstatus](https://github.com/oniichaNj/go-dwmstatus) - A Go bar that
  prints current MPD song, load averages, time/date and battery percentage.
* [gods](https://github.com/schachmat/gods) - implemented in Go. prints network
  speed, cpu, ram, date/time
* [profil-dwmstatus-1.0.c](profil-dwmstatus-1.0.c) - cpufreq, battery percent
  and date/time
* [rsblocks](https://github.com/MustafaSalih1993/rsblocks) - A fast multi threaded status bar written in Rust, configurable with a yaml file.
* [sb](https://git.ckyln.com/sb/log.html) - another modular bar written in POSIX
  shell
* [spoon](https://git.2f30.org/spoon/) - set dwm status. Supports battery,
  cpu freq, date, file, load avg, keyboard layout, mpd, network speed,
  screen brightness, temperature, wifi, volume mixer.
  Works well on OpenBSD and Linux.
* [suspend-statusbar.c](https://github.com/snobb/dwm-statusbar) - date,
  loadavg, battery and more. If battery goes below threshold - run suspend
  command
* [ztatus](https://git.noxz.tech/ztatus/log.html) - simple statusbar and
  notification daemon (through fifo). Displays only date and time normally.
  Configured to work with 'statuscolors' patch by default.

Helper Functions In The Shell
-----------------------------
* [posix scripts](https://notabug.org/kl3/scripts) - basic collection of simple, fully POSIX sh compliant scripts to get various system information
* [i3blocks-contrib](https://github.com/vivien/i3blocks-contrib) - collection of python, perl and shell scripts
* Free memory: `free -h | awk '(NR==2){ print $4 }'`
* Volume (device Master): `amixer get Master | awk -F'[][]' 'END{ print $4":"$2 }'`
* Keyboard layout: `setxkbmap -query | awk '/layout/{ print $2 }'`
* Empty disk space (mountpoint /home): `df -h | awk '{ if ($6 == "/home") print $4 }'`
* wifi status (interface wlp3s0): `cat /sys/class/net/wlp3s0/operstate`
* CPU temperature: `sed 's/000$/°C/' /sys/class/thermal/thermal_zone0/temp`.
  Alternatively you can use `acpi -t` or `sensors` from lm-sensors package. For
  older systems you can get the cpu temperature from
  `/proc/acpi/thermal_zone/THM0/temperature`
* Remaining battery: `cat /sys/class/power_supply/BAT0/capacity`. Alternatively
  you can use `acpi -b`. For older systems you can get the battery capacity from
  `/proc/acpi/battery/BAT0/state`.

Using shell scripts very well leads to big scripts, which pull in unneeded
dependencies. One solution for this is to write everything in C, which is much
more efficient.

Helper Functions In C (for dwmstatus or slstatus etc.)
------------------------------------------------------
If you have simple C functions for gathering system information, feel free to
add them here (keeping the list sorted).

* [ACPI battery status on Linux](new-acpi-battery.c)
* [Battery on Linux](batterystatus.c): Battery percentage and status. + if
  charging, - if discharging, = if full.
* [Detecting Man-In-The-Middle](dwmstatus-mitm.c)
* [Disk usage and execute some check at different moments](diskspace_timechk.c)
* [FIFO info](fifo.c): Replaces dynamic_info.
* [Line per line the content of a file](dynamic_info.c): See
  tmpinfo function. It prints line after line the content of
  /tmp/dwmbuf.
* [MPD title/artist](mpdstatus.c)
* [Number of new mails in a Maildir](mail_counter.c)
* [Temperature from /sys on Linux](dwmstatus-temperature.c)
* [Uptime](uptime.c)
* [Up-, and downspeeds of all network interfaces from /proc/net on Linux](dwmstatus-netusage.c)
* [Volume via ALSA API](getvol.c)
