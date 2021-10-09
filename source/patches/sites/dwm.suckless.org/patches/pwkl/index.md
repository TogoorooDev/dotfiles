Per-window keyboard layout
==========================

Description
-----------
Basically, this patch implements per-window keyboard layout support in dwm. It
makes dwm remember current keyboard layout when a window is unfocused, and
restore it back when that window is focused again.

Notes
-----------
Andreas Amann pointed out that "you cannot switch between tags per mouse if an
alternate layout is activated". He kindly created a patch that fixes this:
[see ml](//lists.suckless.org/dev/1010/6195.html).

Download
--------
* [dwm-pwkl-5.9.diff](dwm-pwkl-5.9.diff) (1.4K) (2010-10-13)
* [dwm-pwkl-6.1.diff](dwm-pwkl-6.1.diff) (1.5K) (2017-01-28)
* [dwm-pwkl-6.2.diff](dwm-pwkl-6.2.diff) (1.6K) (2020-12-01)

Author
------
* Evgeny Grablyk - <evgeny.grablyk@gmail.com>
