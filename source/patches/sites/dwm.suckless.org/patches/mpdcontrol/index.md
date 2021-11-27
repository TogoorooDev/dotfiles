mpdcontrol
==========

Description
-----------
Control Music Player Daemon via keybinds.

By default `MODKEY + Escape` stops/pauses the current song or plays it
depending on the state of the player. If the song is a file on disk it pauses
it, if it's a stream it stops it since pause on a stream doesn't make sense.

`MODKEY + F1` goes to previous song.
`MODKEY + F2` goes to next song.

`libmpdclient` is needed for this patch to work.

Download
--------
* [dwm-r1615-mpdcontrol.diff](dwm-r1615-mpdcontrol.diff)

Author
------
* Barbu Paul - Gheorghe <barbu.paul.gheorghe@gmail.com>
