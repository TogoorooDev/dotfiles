themed_cursor
=============

Description
-----------
Instead of a default X cursor, use the xterm cursor from your cursor
theme.

Specifically, this replaces `XCreateFontCursor` with
`XcursorLibraryLoadCursor` which depends on libXcursor.  This is
especially helpful on a HiDPI display.

Download
--------

* [st-themed\_cursor-0.8.1.diff](st-themed_cursor-0.8.1.diff)

Author
-------
Jim Fowler <kisonecat@gmail.com>
