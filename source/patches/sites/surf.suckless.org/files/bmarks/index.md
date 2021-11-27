Bookmarks for surf
==================

Description
-----------

This script enables bookmarks and url handlers for surf.

Keybindings
-----------
	^b (bookmark current url with given tags)
	^g (open url with bookmark autocompletion)
	^G (open url without bookmark autocompletion)

URL handlers
------------
	This script implements several url handlers
	"d " (bookmark current url in delicious)
	"t " (create tinyurl from current page)
	"w word .." (lookup word in wikipedia)
	"g word .." (google for given word)
	"y word .." (search in youtube)

Author
------

* The code was originally from Peter John Hartman, but hardly simplified by pancake and nibble.

Installation
------------

Copy the following code into a shellscript named 'surf.sh' in $PATH. Edit config.h according to the rules explained in header.

Code
----
	#!/bin/sh
	# $1 = $xid
	# $2 = $p = _SURF_FIND _SURF_BMARK _SURF_URI _SURF_URI_RAW (what SETPROP sets in config.h)
	#
	# // replace default setprop with this one
	# #define SETPROP(p) { .v = (char *[]){ "/bin/sh", "-c", "surf.sh $0 $1", winid, p, NULL } }
	#
	# // fix shift+slash keybinding in spanish keyboard (f.example)
	# { MODKEY,               GDK_g,      spawn,      SETPROP("_SURF_URI") },
	# { MODKEY|GDK_SHIFT_MASK,GDK_g,      spawn,      SETPROP("_SURF_URI_RAW") },
	# { MODKEY,               GDK_f,      spawn,      SETPROP("_SURF_FIND") },
	# { MODKEY,               GDK_b,      spawn,      SETPROP("_SURF_BMARK") },

	font='-*-terminus-medium-*-*-*-*-*-*-*-*-*-*-*'
	normbgcolor='#181818'
	normfgcolor='#e9e9e9'
	selbgcolor='#dd6003'
	selfgcolor='#e9e9e9'
	bmarks=~/.surf/bookmarks.txt

	xid=$1
	p=$2
	uri=`xprop -id $xid _SURF_URI | cut -d '"' -f 2`
	kw=`xprop -id $xid _SURF_FIND | cut -d '"' -f 2`
	dmenu="dmenu -fn $font -nb $normbgcolor -nf $normfgcolor \
		   -sb $selbgcolor -sf $selfgcolor"

	s_xprop() {
		[ -n "$2" ] && xprop -id $xid -f $1 8s -set $1 "$2"
	}

	case "$p" in
	"_SURF_FIND")
		ret="`echo $kw | $dmenu -p find:`"
		s_xprop _SURF_FIND "$ret"
		;;
	"_SURF_BMARK")
		grep "$uri" $bmarks >/dev/null 2>&1 || echo "$uri" >> $bmarks
		;;
	"_SURF_URI_RAW")
		ret=`echo $uri | $dmenu -p "uri:"`
		s_xprop _SURF_GO "$ret"
		;;
	"_SURF_URI")
		sel=`tac $bmarks 2> /dev/null | $dmenu -p "uri [dgtwy*]:"`
		[ -z "$sel" ] && exit
		opt=$(echo $sel | cut -d ' ' -f 1)
		arg=$(echo $sel | cut -d ' ' -f 2-)
		case "$opt" in
		"d") # del.icio.us
			ret="http://del.icio.us/save?url=$uri"
			;;
		"g") # google for it
			ret="http://www.google.com/search?q=$arg"
			;;
		"t") # tinyurl
			ret="http://tinyurl.com/create.php?url=$uri"
			;;
		"w") # wikipedia
			ret="http://wikipedia.org/wiki/$arg"
			;;
		"y") # youtube
			ret="http://www.youtube.com/results?search_query=$arg&aq=f"
			;;
		*)
			ret="$sel"
			;;
		esac
		s_xprop _SURF_GO "$ret"
		;;
	*)
		echo Unknown xprop
		;;
	esac
