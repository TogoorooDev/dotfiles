OSC 10, 11, 12
==============

Description
-----------
This patch adds support for OSC escape sequences 10, 11 and 12, that modify the
bg, fg and cursor colors. To decouple them from the palette you can select
entries from the colorname table after the 255 position for defaultfg, defaultbg
and defaultcs.

Download
--------
* [st-osc\_10\_11\_12-20200418-66520e1.diff](st-osc_10_11_12-20200418-66520e1.diff)


Authors
-------
* Christian Tenllado - <ctenllado at gmail dot com>
