useless gap
===========

Description
-----------
For aesthetic purposes, this patch:

* adds "useless gaps" around windows
* removes everything (gaps and borders) when in monocle mode for aesthetic purpose.

The size of the gap is configured in `config.h`:

	static const unsigned int gappx     = 6;        /* gap pixel between windows */

Example
-------
No gaps:

	+-----------------+-------+
	|                 |       |
	|                 |       |
	|                 |       |
	|                 +-------|
	|                 |       |
	|                 |       |
	|                 |       |
	+-----------------+-------+

With gaps around windows:

	+---------------------------+
	|+----------------++-------+|
	||                ||       ||
	||                ||       ||
	||                ||       ||
	||                |+-------+|
	||                |+-------+|
	||                ||       ||
	||                ||       ||
	||                ||       ||
	|+----------------++-------+|
	+---------------------------+

NB: there are some alternatives in the patches section, adding gaps between
windows, but not between windows and the screen borders, only in the default
tile mode...

Download
--------
* [dwm-uselessgap-20200719-bb2e722.diff](dwm-uselessgap-20200719-bb2e722.diff) (20200719)
  Fixed a bug where when moving a client to a different monitor, sometimes the gaps and the border wolud be drawn, when they shouldn't.
* [dwm-uselessgap-6.2.diff](dwm-uselessgap-6.2.diff)
* [dwm-uselessgap-6.1.diff](dwm-uselessgap-6.1.diff) (4K) (20150815), now supports nmaster.
* [dwm-uselessgap-5.9.diff](dwm-uselessgap-5.9.diff) (1.8k) (20110107 updated. Thanks Jordan for your bug report)
  Updated to use the new resizeclient() function instead of resize()
* [dwm-uselessgap-5.8.diff](dwm-uselessgap-5.8.diff) (1.7k) (20100225 updated. Thanks Guillaume for your bug report)
  Fix floating clients bug and remove all borders in monocle mode.

Author
------
* [jerome](http://blog.jardinmagique.info) -  <jerome@gcu.info>
* [Cyril Cressent](https://cressent.org) - <cyril@cressent.org> (6.2 port)
* Mateus Auler - <mateusauler at protonmail dot com> (Bugfix)
