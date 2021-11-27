Keycodes
========
With this patch, handling key input is done with keycodes instead of keysyms.
This way, input is independent from keyboard layout (you can get keycodes using
xev to adapt config.h)

Download
--------
* [dwm-keycodes-6.1.diff](dwm-keycodes-6.1.diff)
* [dwm-keycodes-20170511-ceac8c9.diff](dwm-keycodes-20170511-ceac8c9.diff)

Authors
-------
* Quentin Rameau <quinq@fifth.space>
