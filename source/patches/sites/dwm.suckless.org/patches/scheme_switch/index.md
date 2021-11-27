schemeSwitch
============

Description
-----------
[Solarized](http://ethanschoonover.com/solarized) is a color scheme by Ethan
Schoonover which exists in a dark and a light variant.

This patch allows you defining more then one color-Scheme in the colors array
in config.def.h (or config.h) and cycle through the schemes by schemeCycle()
function (bound to Mod+Shift+z) and toggle between corresponding light and dark
schemes with schemeToggle() function (bound to Mod+Shift+t).

In the example config.def.h there are first defined the colors for the dark
variant of solarized theme, after that the colors for the light variant, and
then the original dwm colorscheme, wich has no corresponding light scheme. If
the last one is selected shemeToggle() will do nothing, but one can cycle to
the dark scheme (or the light one) and then toggle between light and dark. If
there where colors defined after the original scheme, then schemeToggle() would
toggle between original and the consecutive.

Download
--------
* [dwm-scheme\_switch-20170804-ceac8c9.diff](dwm-scheme_switch-20170804-ceac8c9.diff)

Authors
-------
* Aaron Strahlberger - <aaron.strahlberger@posteo.de>
