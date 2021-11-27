stdin
=====

Description
-----------
dwm releases before 5.3 read the status text from stdin. This patch is mainly a
workaround for the freezing issue caused by `XSelectInput` with the previous
version of the [warp](../warp/) patch. Some people might like to write their
status to a pipe, though.

Download
--------
* [dwm-r1533-stdin.diff](dwm-r1533-stdin.diff)

Author
------
This was originally part of dwm-5.2 and written by Anselm R. Garbe. It was
ported to later versions of dwm by Moritz Wilhelmy, mw wzff de.
