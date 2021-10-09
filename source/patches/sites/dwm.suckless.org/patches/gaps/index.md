gaps
====

Description
-----------
This patch modifies the tile layout to add a gap between clients that helps to
visually differentiate between selected borders and normal borders and so
provides an additional visual hint to identify the currently selected client.
OTOH, there's no gap between a client and the screen frame in order to reduce
the waste of screen space.

To configure the gap size just set the configuration variable `gappx`.

There is a variation of the patch for the [xtile](../xtile/) layout also.

Download
--------
* For vanilla tile: [dwm-gaps-6.0.diff](dwm-gaps-6.0.diff)
* For xtile tile: [dwm-gaps-xtile-6.0.diff](dwm-gaps-xtile-6.0.diff)

Author
------
* Carlos Pita (memeplex) <carlosjosepita@gmail.com>
