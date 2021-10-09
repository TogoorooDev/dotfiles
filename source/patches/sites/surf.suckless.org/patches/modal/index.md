Modal
=====

Description
-----------
This patch adds an insert mode to surf. While in the insert mode the
hotkeys without a MODKEY cannot be used, which allows you to type into a
text area/field without clashing with the hotkeys.

This patch modifies both the `config.def.h` and `surf.c` and removes
MODKEY modifier from most of the hotkeys (e.g. 'MODKEY+j' is now just
'j'). If you modify the patch to only apply to `surf.c` you should at
least have two hotkeys with a function called `insert`:

    { 0,                     GDK_KEY_i,      insert,     { .i = 1 } },
    { 0,                     GDK_KEY_Escape, insert,     { .i = 0 } },

Note that if the modifier is `0`, `GDK_KEY_Escape` is the only key that
you can use to get out of the insert mode.

Download
--------
* [surf-modal-20190209-d068a38.diff](surf-modal-20190209-d068a38.diff)

Author
------
* Sunur Efe Vural <efe@efe.kim>
