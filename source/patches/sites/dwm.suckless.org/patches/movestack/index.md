movestack
=========

Description
-----------
This plugin allows you to move clients around in the stack and swap them with
the master. It emulates the behavior off mod+shift+j and mod+shift+k in Xmonad.
movestack(+1) will swap the client with the current focus with the next client.
movestack(-1) will swap the client with the current focus with the previous
client.

Usage
-----
1. Download the patch and apply according to the [general instructions](../).
2. Include the `movestack.c` source file and add keys that call movestack.
   Example from `config.default.h`:

        #include "movestack.c"
        static Key keys[] = {
	       /* modifier                     key        function        argument */
	       ...
	       { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	       { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	       ...

Download
--------
* [dwm-movestack-6.1.diff](dwm-movestack-6.1.diff)
* [dwm-movestack-5.8.2.diff](dwm-movestack-5.8.2.diff)

Author
------
* Niki Yoshiuchi - `<`aplusbi@gmail.com`>`

Contributors
------------
* Moritz Wilhelmy (fix to work with dwm 5.8) - <moritz plus suckless at wzff dot de>

Note
----
This patch seems to be equivalent to the [push](../push/) patch.
