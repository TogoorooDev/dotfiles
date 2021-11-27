spoiler
=======

Description
-----------
Use inverted defaultbg/fg for selection when bg/fg are the same

The background/foreground of selected text is currently set by setting
ATTR\_REVERSE, which flips its normal bg/fg. When the text being selected has
the same bg and fg, it won't be readable after selecting it, either.

The main use case is black-on-black text used to mark 'spoilers'.

This patch allows that text to be read by selecting it, turning it into text
with white bg and black fg (given default values for defaultbg/fg), just like
most normal unformatted text when selected.

Download
--------
* [st-spoiler-0.6.diff](st-spoiler-0.6.diff)
* [st-spoiler-0.7.diff](st-spoiler-0.7.diff)
* [st-spoiler-20160727-308bfbf.diff](st-spoiler-20160727-308bfbf.diff)
* [st-spoiler-20170802-e2ee5ee.diff](st-spoiler-20170802-e2ee5ee.diff)
* [st-spoiler-20180309-c5ba9c0.diff](st-spoiler-20180309-c5ba9c0.diff)

Author
------
* dequis - <dx@dxzone.com.ar>
* Laslo Hunhold - <dev@frign.de> (git port)
* Matthew Parnell - <matt@parnmatt.co.uk> (0.7, git ports)
