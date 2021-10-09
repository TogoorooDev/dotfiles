pertag
======

Description
-----------
More general approach to [taglayouts patch](../historical/taglayouts).
This patch keeps layout, mwfact, barpos and nmaster per tag.

Download
--------
* [dwm-pertag-20200914-61bb8b2.diff](dwm-pertag-20200914-61bb8b2.diff)
* [dwm-pertag-6.2.diff](dwm-pertag-6.2.diff)
* [dwm-pertag-6.1.diff](dwm-pertag-6.1.diff) (6.4K) (20151109)
* [dwm-git-20120406-pertag.diff](dwm-git-20120406-pertag.diff) (5955b)
* [dwm-pertag-6.0.diff](dwm-pertag-6.0.diff) (5955b) (20120406)
* [dwm-r1578-pertag.diff](dwm-r1578-pertag.diff) (nmaster included in mainline)
* [dwm-pertag-5.8.2.diff](dwm-pertag-5.8.2.diff)
* [dwm-pertag-5.7.2.diff](dwm-pertag-5.7.2.diff)
* [dwm-pertag-5.4.diff](dwm-pertag-5.4.diff)
* [dwm-pertag-5.2.diff](dwm-pertag-5.2.diff)
* [dwm-pertag-5.1.diff](dwm-pertag-5.1.diff)

* Using pertag but with the same barpos
  * [dwm-6.1-pertag\_without\_bar.diff](dwm-6.1-pertag_without_bar.diff) (5.2K) (20151109)
  * [dwm-6.0-pertag\_without\_bar.diff](dwm-6.0-pertag_without_bar.diff) (5578b) (20140530)
  * [dwm-5.8.2-pertag\_without\_bar.diff](dwm-5.8.2-pertag_without_bar.diff)

* With this version of pertag, changes are always applied to all selected tags.  
  For exmaple: If tag 2 and tag 3 are selected, changes to barpos, layout, mfact, nmaster will apply to both tags.  
  With the original pertag patch, changes only effect the tag which was selected first.
  * [dwm-pertag-perseltag-6.2.diff](dwm-pertag-perseltag-6.2.diff) (20200622)


Authors
-------
* Jan Christoph Ebersbach - <jceb@e-jc.de>
* Updated by V4hn - `v4hn.de`
* Updated by Jerome Andrieux - `<jerome at gcu dot info>`
* Updated by Sidney Amani - `<seed at uffs dot org>`
* Updated by William Light - `<wrl at illest dot net>`
* Updated by termac - `<terror.macbeth.I at gmail dot com>`
* Updated by Ivan Tham - `pickfire at riseup dot net`
* [Jochen Sprickerhof](mailto:project@firstname.lastname.de) (Updated to current git)
* Lucas Gabriel Vuotto - <lvuotto92@gmail.com> (git ports)
* Aaron Duxler - <aaron@duxler.xyz> (dwm-pertag-perseltag-6.2)
