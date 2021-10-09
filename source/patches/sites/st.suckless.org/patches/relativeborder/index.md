relativeborder
==============

Description
-----------
When working with a mixture of different DPI scales on different monitors, you
need to use a flexible font that will size correctly no matter the DPI - for
example, `DejaVu Sans Mono-10`. If you have a border set in pixels, this border
will look vastly different in size depending on the DPI of your display.

This patch allows you to specify a border that is relative in size to the width
of a cell in the terminal.

Download
--------
* [st-relativeborder-20171207-0ac685f.diff](st-relativeborder-20171207-0ac685f.diff)
* [st-relativeborder-0.8.3.diff](st-relativeborder-0.8.3.diff)

Authors
-------
* Doug Whiteley - <dougwhiteley@gmail.com>
* Francesco Minnocci - <ad17fmin@uwcad.it> (0.8.3 port)
