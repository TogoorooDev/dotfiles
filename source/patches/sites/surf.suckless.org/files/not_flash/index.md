Watch flash videos with mpv
===========================

Description
-----------

Save this script as ~/bin/yt and adjust it to your needs. (Requires [youtube-dl](http://rg3.github.io/youtube-dl/))


	#!/bin/sh
	format="-f34" # leave empty for default
	player="mpv --quiet --geometry=50%:50% --idx --keep-open"
	tmpdir="$HOME/tmp"
	
	url="$1"
	filepath="$tmpdir/$(youtube-dl --id --get-filename $format $url)"
	
	youtube-dl -c -o $filepath $format $url &
	echo $! > $filepath.$$.pid
	
	while [ ! -r $filepath ] && [ ! -r $filepath.part ]; do 
		echo "Waiting for youtube-dl..."
		sleep 3
	done
	
	[ -r $filepath.part ] && $player $filepath.part || $player $filepath
	kill $(cat $filepath.$$.pid)
	rm $filepath.$$.pid


Add this to surf's config.h:


	#define WATCH {.v = (char *[]){ "/bin/sh", "-c", \
		"st -e \
		yt $(xprop -id $0 _SURF_URI | cut -d \\\" -f 2)", \
		winid, NULL } }


and in the keys section:


	{ MODKEY,               GDK_w,      spawn,      WATCH },


Author
------
* Maximilian Dietrich - <dxm_at_lavabit_dot_com>
