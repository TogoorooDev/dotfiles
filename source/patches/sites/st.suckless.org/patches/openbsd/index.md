openbsd
=======

Description
-----------
OpenBSD primarily searches for terminfo descriptions in terminfo databases
before considering terminfo files. Given the terminfo currently stored in the
global database is for st 0.1.1, this leads to conflicts and misbehaviour.

This patch renames st to st-git forcing OpenBSD to use the provided terminfo
file.

Notes
-----
Once a new stable version of st is out, the corresponding changes to st.info
can be pushed upstream to ncurses and then be merged back to OpenBSD,
effectively making this patch obsolete for future stable releases. More
information on this issue can be found in this
[thread](http://marc.info/?l=openbsd-misc&m=139540215025526&w=2).

Download
--------
* [st-openbsd-20160727-308bfbf.diff](st-openbsd-20160727-308bfbf.diff)
* [st-openbsd-20210802-2ec571a.diff](st-openbsd-20210802-2ec571a.diff)

Authors
-------
* Nils Reuße - <nilsreusse@gmail.com>
* Laslo Hunhold - <dev@frign.de> (git port)
