font2
=====

Description
-----------
This patch allows to add spare font besides default. Some glyphs can be
not present in default font. For this glyphs st uses font-config and try
to find them in font cache first. This patch append fonts defined in
`font2` variable to the beginning of font cache. So they will be used
first for glyphs that absent in default font.

Example
-------------
`static char *font = "Bitstream Vera Sans Mono:pixelsize=11:antialias=true:autohint=true";`
without patch.

[![Screenshot1](st-font2-wopatch1.png)](st-font2-wopatch1.png)
[![Screenshot2](st-font2-wopatch2.png)](st-font2-wopatch2.png)


`static char *font2[] = {
	"Inconsolata for Powerline:pixelsize=12:antialias=true:autohint=true"
};`
[![Screenshot3](st-font2-wpatch1.png)](st-font2-wpatch1.png)
[![Screenshot4](st-font2-wpatch2.png)](st-font2-wpatch2.png)

Download
--------
* [st-font2-20190326-f64c2f8.diff](st-font2-20190326-f64c2f8.diff)
* [st-font2-20190416-ba72400.diff](st-font2-20190416-ba72400.diff)

Changelog
---------
* multiple fonts support
* size of spare fonts changes according to size of default font
* fonts loading procedure fixed

Author
-------
* Kirill Bugaev <kirill.bugaev87@gmail.com>
