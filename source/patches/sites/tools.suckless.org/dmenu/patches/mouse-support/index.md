Mouse support
=============
With this patch dmenu will have basic mouse support. The following features are
supported:

Mouse actions supported:

* Left-mouse click:
  * On prompt and input field: clear input text and selection.
  * In horizontal and vertical mode on item: select and output item (same as
    pressing enter).
  * In horizontal mode on arrows: change items to show left or right.
* Ctrl-left-mouse click: multisel modifier.
* Right-mouse click: close.
* Middle-mouse click:
  * Paste current selection.
  * While holding shift: paste primary selection.
* Scroll up:
  * In horizontal mode: same as left-clicking on left arrow.
  * In vertical mode: show items above.
* Scroll down:
  * In horizontal mode: same as left-clicking on right arrow.
  * In vertical mode: show items below.

Download
--------
* [dmenu-mousesupport-5.0.diff](dmenu-mousesupport-5.0.diff)
* [dmenu-mousesupport-4.9.diff](dmenu-mousesupport-4.9.diff)
* [dmenu-mousesupport-4.7.diff](dmenu-mousesupport-4.7.diff)
* [dmenu-mousesupport-4.6.diff](dmenu-mousesupport-4.6.diff)
* [dmenu-mousesupport-20160702-3c91eed.diff](dmenu-mousesupport-20160702-3c91eed.diff)
* [dmenu-mousesupporthoverbgcol-20210123-1a13d04.diff](dmenu-mousesupporthoverbgcol-20210123-1a13d04.diff)
  set selectbg color on hovered item.
* [dmenu-mousesupporthoverbgcol-5.0.diff](dmenu-mousesupporthoverbgcol-5.0.diff)
* [dmenu-mousesupportwithgrid-5.0.diff](dmenu-mousesupportwithgrid-5.0.diff)
  variant compatible with [grid](../grid).


Author
------
* Hiltjo Posthuma - <hiltjo@codemadness.org>
* Xarchus (for multisel support).
* prx (for selectbg color on hovered item)
* Nathan Sketch (for grid compatibility) - <sketchn98@gmail.com>
