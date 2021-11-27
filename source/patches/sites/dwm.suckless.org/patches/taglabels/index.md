taglabels
=========

Description
-----------
Displays the executable name of each tag's current master client after the tag name in the dwm bar.
* For example, if `st` is the master client on tag `1`, then the bar would display `[1: st]` as opposed to just `1`.

The format of the label, for both non-empty and empty tags, is configurable through the configuration variables `ptagf` and `etagf` respectively. There is also a config variable, `lcaselbl`, that, when enabled, makes the first letter lowercase (out of personal preference).

Download
--------
* [dwm-taglabels-6.2.diff](dwm-taglabels-6.2.diff)

This patch looks best with [hide\_vacant\_tags](../hide_vacant_tags), and, as such, there are seperate versions that support that patch (since, by default, they conflict badly).
* [dwm-taglabels-hide\_vacant\_tags\_funcionality-6.2.diff](dwm-taglabels-hide_vacant_tags_funcionality-6.2.diff) (install on top of hide\_vacant\_tags)
* [dwm-taglabels+hide\_vacant\_tags-6.2.diff](dwm-taglabels+hide_vacant_tags-6.2.diff) (comes with both patches for simplicity's sake)

Author
------
* Timmy Keller <applesrcol8796@gmail.com>
