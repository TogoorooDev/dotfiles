anygeometry
===========

Description
-----------
From `anysize` patch:

> By default, st's window size always snaps to the nearest multiple of the
> character size plus a fixed inner border (set with borderpx in config.h). When
> the size of st does not perfectly match the space allocated to it (when using
> a tiling WM, for example), unsightly gaps will appear between st and other 
> apps, or between instances of st.

This patch allows you to set st's width and height as pixels instead of cells,
both from the command line (with the new parameter `-G`) or the config file
(variables `geometry`, `width` and `height`).

Download
--------
* [st-anygeometry-0.8.1.diff](st-anygeometry-0.8.1.diff)

Authors
-------
* José Miguel Sánchez García - <soy.jmi2k@gmail.com>
