listfullwidth
=============
Fork of [vertfull](../vertfull), updated for 5.0, a `colorprompt` option added, and a name change (see rationale below).

When adding a prompt to dmenu (with the `-p` option or in config.h) and using a list arrangement, the items are indented at the prompt width. This patch fixes that.

The patch also adds a `colorprompt` option to `config.def.h`. When enabled, the prompt will use the same colorscheme as the highlighted option (`SchemeSel`). If disabled, the prompt text will use the normal colorscheme (`SchemeNorm`). Enabled by default.

Renaming Rational
-----------------
`vertfull` never made any sense to me. I assume "vert" is short for vertical, as I can't think of any other possibilities, but the patch changes the horizontal dimention, not the vertical. At first, I was just going to name the patch `horfull`, but that doesn't quite seem right.

I wasn't sure if simply updating the patch was enough to warrant a rename, despite my gripes with the old name, but then I thought of adding the `colorprompt` option which I consider to be sufficient justification.

Download
--------
* [dmenu-listfullwidth-5.0.diff](dmenu-listfullwidth-5.0.diff)

Author
------
* Alex Cole - <ajzcole@airmail.cc>
