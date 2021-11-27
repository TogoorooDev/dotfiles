xclearwin
=========

Description
-----------
When an OCS sequence was used to change the bg color, the borders where
dirty. This simple patch just clears the window before the redraw of the
terminal when the bg color has been changed. This is apparently smooth
and solves the problem. There was a TODO comment for it on the st.c
file, which I removed.

Download
--------
* [st-xclearwin-20200419-6ee7143.diff](st-xclearwin-20200419-6ee7143.diff)

Authors
-------
* Christian Tenllado - <ctenllado@gmail.com>
