Keycodes
========
With this patch, key input handling is done with keycodes instead of keysyms.
This way, input is independant from keyboard layout.
You can adapt config.h to your keyboard by looking up keycodes, for example, with xev.

Download
--------
* [surf-webkit2-keycodes-20170424-5c52733.diff](surf-webkit2-keycodes-20170424-5c52733.diff)
* [surf-webkit1-keycodes-20170424-9ba143b.diff](surf-webkit1-keycodes-20170424-9ba143b.diff)

Author
------
* Quentin Rameau <quinq@fifth.space>
