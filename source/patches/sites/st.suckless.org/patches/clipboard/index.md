one clipboard
=============

The [Freedesktop
standard](http://standards.freedesktop.org/clipboards-spec/clipboards-latest.txt)
requires you to remember which clipboard you are keeping selections in.  If you
switch between a terminal and browser, you may find this UX jarring.

Description
-----------
This trivial patch sets CLIPBOARD on selection, the same as your browser.

You may want to replace selpaste with clippaste in your config.h bindings to
complete the affect.

Download
--------
* [st-clipboard-0.8.3.diff](st-clipboard-0.8.3.diff)
* [st-clipboard-0.8.2.diff](st-clipboard-0.8.2.diff)
* [st-clipboard-0.8.1.diff](st-clipboard-0.8.1.diff)
* [st-clipboard-0.6.diff](st-clipboard-0.6.diff)
* [st-clipboard-0.7.diff](st-clipboard-0.7.diff)
* [st-clipboard-20160727-308bfbf.diff](st-clipboard-20160727-308bfbf.diff)
* [st-clipboard-20170802-e2ee5ee.diff](st-clipboard-20170802-e2ee5ee.diff)
* [st-clipboard-20170925-b1338e9.diff](st-clipboard-20170925-b1338e9.diff)
* [st-clipboard-20180309-c5ba9c0.diff](st-clipboard-20180309-c5ba9c0.diff)

Authors
-------
* Kai Hendry - <hendry@iki.fi>
* Laslo Hunhold - <dev@frign.de> (git port)
* Matthew Parnell - <matt@parnmatt.co.uk> (0.7, git ports)
