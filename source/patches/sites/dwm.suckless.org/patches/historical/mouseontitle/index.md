Mouse events on title
=====================
Last update: 2009-12-11

Adds mouse events on the title bar to switch between clients using the mouse
wheel and using the left click to zoom, right click kill and middle click for
toggling the floating.

This way you can easily manage tiled clients with the mouse.

The right click on the layout area maximizes the client.

If you are using the nmaster patch you will be able to change the nmaster value
using the mouse wheel.

Change the mwfact using the wheel at x=0 placing the cursor inside the bar.

Notes
-----
Last versions of dwm (5.x series) allow to bind mouse events to actions, so
this patch can be replaced by a proper config.h tweak.

Patch
-----
Patch for [dwm 4.6](http://www.lolcathost.org/b/dwm/mouseontitle-4.6.diff) is
here.

See in event.c at function 'buttonpress()' to patch older dwm releases.

Author
------
* pancake <youterm.com>
