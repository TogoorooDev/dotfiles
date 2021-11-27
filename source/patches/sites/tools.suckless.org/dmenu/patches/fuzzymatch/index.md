fuzzymatch
==========

Description
-----------
This patch adds support for fuzzy-matching to dmenu, allowing users to type
non-consecutive portions of the string to be matched.

Adds the option *fuzzy* to config.def.h and the flag *-F* to dmenu which enable
to turn fuzzy-matching on and off.

Notes
-----
* Supports dmenu's case insensitive switch (`-i`)

Download
--------
* [dmenu-fuzzymatch-4.9.diff](dmenu-fuzzymatch-4.9.diff)
* [dmenu-fuzzymatch-20170603-f428f3e.diff](dmenu-fuzzymatch-20170603-f428f3e.diff)
* [dmenu-fuzzymatch-4.6.diff](dmenu-fuzzymatch-4.6.diff)

Authors
-------
* Jan Christoph Ebersbach - jceb@e-jc.de
* Laslo Hunhold - dev@frign.de (dmenu-4.6)
* Aleksandrs Stier (4.9)
