decoration hints
================

Description
-----------

Make dwm respect \_MOTIF\_WM\_HINTS property, and not draw borders
around windows requesting for it.  Some applications use this property
to notify window managers to not draw window decorations.

Not respecting this property leads to issues with applications that draw
their own borders, like chromium (with "Use system title bar and
borders" turned off) or vlc in fullscreen mode.

Download
--------

* [dwm-decorhints-6.2.diff](dwm-decorhints-6.2.diff)

Authors
-------

* Jakub Leszczak - <szatan@gecc.xyz>
