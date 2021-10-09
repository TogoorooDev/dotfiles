color status bar
================

Description
-----------
This patch adds some color to the status bar. It allows you to change the
colorset of text portions from "norm" to "sel" (and back) and to invert the
colorset (the foreground becomes the background color and vice versa).

Usage
-----
Download the patch and apply it according to the [general instructions](.). The
patch will make the following changes:

* colorstatus.c: adding the file
* dwm.c: adding the include-line for 'colorstatus.c'
* dwm.c ('drawbar' function): adding the int-variable 'stextw'
* dwm.c ('drawbar' function): changing the 'drawtext' section for stext

Configuration
-------------
The configuration is done in the file '.xinitrc', where you define the status
bar text. You can add the following tags:

* '[c]' (without quotes): toggles the colorset (norm -> sel or sel -> norm
  depending on the currently selected colorset)
* '[i]' (without quotes): inverts the current colorset (fgcolor -> bgcolor and
  bgcolor -> fgcolor)

The change is applied from the position of the tag onwards. To revert the
change you have to set the same tag again.

Example
-------
	echo -e NEW mail: $mailnew \| VOL front: $audiofront \| BAT:[i]$batpercent[i]\| CPU: $cpuavgload \| $datestr[c]$timestr

Download
--------
* [dwm-5.2-colorstatus.diff](dwm-5.2-colorstatus.diff) (4.1k, 131 additional lines) (20081117)
* [.xinitrc example](dwm-5.2-colorstatus.xinitrc) (0.8k) (20081117)

