History
=======

Description
-----------

This patch writes the loaded URI to a file and that is all it does.  You must modify config.h and 
add the following:

	static char *historyfile        = ".surf/history";

Here are some ways of using it.

1. Write a small shell script (dmenu.uri.sh)

   	tac ~/.surf/history | dmenu -l 10 -b -i | cut -d ' ' -f 3

2. Modify config.h and add the following.

   	#define SETURI(p)       { .v = (char *[]){ "/bin/sh", "-c", \
   	"prop=\"`dmenu.uri.sh`\" &&" \
   	"xprop -id $1 -f $0 8s -set $0 \"$prop\"", \
   	p, winid, NULL } }

   and in static Key keys[] add:

   	{ MODKEY,               GDK_Return, spawn,      SETURI("_SURF_GO") },

Here are some tips on using it.

1. Remove duplicates periodically:

	cat ~/.surf/history > ~/.surf/history.$$
	cat ~/.surf/history.$$ | sort | uniq >~/.surf/history
	rm -f ~/.surf/history.$$

2. Import history:

Firefox:
	sqlite3 -list $HOME/.mozilla/firefox/*.default/places.sqlite 'select url from moz_places ;' | grep ^http >> ~/.surf/history

Chromium:
	sqlite3 -list $HOME/.config/chromium/Default/History 'select url from urls' | grep ^http >> ~/.surf/history

Download
--------

* [surf-0.2-history.diff](surf-0.2-history.diff) (891) (20091019)
* [surf-0.3-history.diff](surf-0.3-history.diff) (1475) (20091203)
* [surf-tip-history.diff](surf-tip-history.diff) (2952) (20091215)
* [surf-0.4.1-history.diff](surf-0.4.1-history.diff) (1346) (20101225)
* [surf-history-20181009-2b71a22.diff](surf-history-20181009-2b71a22.diff) (3405) (20181009)

Authors
-------

* Jason Thigpen (cdarwin) <darwin@senet.us>
* Peter John Hartman (wart_) <http://durandus.trilidun.org/durandus/>
* Samuel Baldwin (shardz) <recursive.forest@gmail.com>
* Marcin sZpak <szpak@reakcja.org>
