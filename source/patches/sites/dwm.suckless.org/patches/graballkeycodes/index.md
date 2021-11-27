graballkeycodes
===============

Description
-----------

Grab all keycodes that map to keys.keysym

There may be multiple keycodes that map to a keys.keysym. One such scenario is using xkb to remap a key: `caps:escape`

When grabbing keys, we now scan all X keycode mappings and look for match.

Changing keymaps via xkb or other means will not cause the keys to be "re-grabbed". This existing behaviour is desirable.

Download
--------
* [dwm-grab-all-keycodes-6.2.diff](dwm-grab-all-keycodes-6.2.diff) (20201231)

Author
------
* Alexander Courtis

