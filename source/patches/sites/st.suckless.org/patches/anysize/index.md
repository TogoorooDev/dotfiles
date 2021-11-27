anysize
=========

Description
-----------
By default, st's window size always snaps to the nearest multiple of the
character size plus a fixed inner border (set with borderpx in config.h). When
the size of st does not perfectly match the space allocated to it (when using a
tiling WM, for example), unsightly gaps will appear between st and other apps,
or between instances of st.

This patch allows st to resize to any pixel size, makes the inner border size
dynamic, and centers the content of the terminal so that the left/right and
top/bottom borders are balanced. With this patch, st on a tiling WM will always
fill the entire space allocated to it.

Download
--------
* [st-anysize-0.8.1.diff](st-anysize-0.8.1.diff)
* [st-anysize-20201003-407a3d0.diff](st-anysize-20201003-407a3d0.diff)
* [st-anysize-0.8.4.diff](st-anysize-0.8.4.diff)

Authors
-------
* Augusto Born de Oliveira - <augustoborn@gmail.com>
