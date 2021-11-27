vtcolors
========

Description
-----------
This patch adds the ability for dwm to read colors from the linux virtual 
console: /sys/module/vt/parameters/default_{red,grn,blu}. In this way the 
colors you use in your regular tty is "mirrored" to dwm.

Color mappings (16 colors) are handled in config.h using color_ptrs:

    static const int color_ptrs[][3]    = {
        /*                              fg         bg         border    */
        [SchemeNorm]                = { -1,        -1,        5 },
        [SchemeSel]                 = { -1,        -1,        11 },
        [SchemeTagsNorm]            = { 2,         0,         0 },
        [SchemeTagsSel]             = { 6,         5,         5 },
        [SchemeTitleNorm]           = { 6,         -1,        -1 },
        [SchemeTitleSel]            = { 6,         -1,        -1 },
        [SchemeStatus]              = { 2,         0,         0 },
    };

Extra color specifications for tags, title and status are also added.

Download
--------
* [dwm-vtcolors-6.2.diff](dwm-vtcolors-6.2.diff)

Authors
-------
* Chris Noxz - <chris@noxz.tech>
