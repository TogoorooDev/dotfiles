nrowgrid
========

Description
-----------
This grid layout gives you the option of determining the row count, which is
set by `nmaster + 1`. So except for giving you a customizable grid, you also
get the ability to show everything in one row, or in one column (`row = 1` and
`row = client count`, respectively). When calculating the cell dimensions
utilization trackers are used to make sure all pixels are utilized. The effect
is that no overlays or no gaps are present, but on the other side all cells are
not always of equal size.

Example: splitting 2560 pixels into 6 cells gives you 2 cells with a width of
426 pixels and 4 cells with a width of 427 pixels. No gaps, but not equal size,
an off trade I believe many would be comfortable with.

I personally want the presence of only 2 clients to always result in a vertical
split. If you don't like this feature set the FORCE\_VSPLIT to 0 in `config.h`.

Download
--------
* [dwm-nrowgrid-6.1.diff](dwm-nrowgrid-6.1.diff)

Authors
-------
* Chris Noxz - <chris@noxz.tech>
