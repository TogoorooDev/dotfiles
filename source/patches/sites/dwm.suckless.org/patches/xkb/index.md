xkb
=====

Description
-----------
This patch replaces main functionality of xxkb. It will remember the client's
xkb status and restores it when client became focused.

Applying
--------
Firstly you have to configure xkb as you need as described 
[here](https://www.x.org/archive/X11R7.5/doc/input/XKB-Config.html).
The patch depends on two variables:

* `showxkb` flag defines, should patch show current xkb group on the bar or
  not;

* `xkb_layouts` array defines the text, which will appear on the bar according
  to current group if `showxkb` set to `TRUE`.

There is new field in Rule struckture, by witch you can specify default xkb
layout for window (see config.def.h for details). This could be useful with
dmenu\_run, but unfortunately for some reasons rules can't be applied to dmenu.

Download
--------
* [dwm-6.1-xkb.diff](dwm-6.1-xkb.diff) (2014-02-15)

Author
------
* Yury Shvedov - [shved AT lvk DOT cs DOT msu DOT su](mailto:shved@lvk.cs.msu.su) (or [mestofel13 AT gmail DOT com](mailto:mestofel13@gmail.com)).
