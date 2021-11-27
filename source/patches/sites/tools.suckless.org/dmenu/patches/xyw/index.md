Position and width
==================

The patch adds options for setting window position and width.

* The '-x' and '-y' options set the window position on the target monitor (0 if one is not supplied with '-m')
* If option '-b' is used, the y offset is computed from the bottom
* The '-x' and '-y' accept negative values
* The '-w' option sets the window width

Please note that for the 5.0 version, the width parameter is '-z' to avoid conflict with '-w windowid'.
If this change is not desired, the 4.7 version applies fine, but '-w windowid' will not work.

Download
--------
* [dmenu-xyw-5.0.diff](dmenu-xyw-5.0.diff)
* [dmenu-xyw-4.7.diff](dmenu-xyw-4.7.diff)
* [dmenu-xyw-20171207-f0a5b75.diff](dmenu-xyw-20171207-f0a5b75.diff)
* [dmenu-xyw-20160903-026827f.diff](dmenu-xyw-20160903-026827f.diff)
* [dmenu-xyw-4.6.diff](dmenu-xyw-4.6.diff)

Author
------
* Xarchus
* Jonathon Fernyhough (jonathon at manjaro-dot-org) (4.7 rewrite)
* Alex Cole <ajzcole@airmail.cc> (changes in the 5.0 version)
