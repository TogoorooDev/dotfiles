print input text
================

Description
-----------
This patch adds a flag (`-t`) which makes Return key to ignore selection and
print the input text to stdout. The flag basically swaps the functions of
Return and Shift+Return hotkeys.

The default behaviour of dmenu makes sense when selecting from given options
(i.e. as a program launcher) but it is annoying when you might be entering text
that is different than the given options (i.e. as surf's url bar).

Usage in Surf
-------------
Just add the `-t` flag to the dmenu in the SETPROP function of surf's
config.def.h. Now the url bar should behave just like in all other browsers.

Download
--------
* [dmenu-printinputtext-20190822-bbc464d.diff](dmenu-printinputtext-20190822-bbc464d.diff)

Author
------
* efe - efe@efe.kim
