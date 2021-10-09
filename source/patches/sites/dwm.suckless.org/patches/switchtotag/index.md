switchtotag
===========

Description
-----------
Adds a rule option to switch to the configured tag when a window opens, then
switch back when it closes.

The patch modifies `config.def.h`. Make sure to update `config.h` accordingly,
if the file exists.

Example Configuration
---------------------

    static const Rule rules[] = {
        /* class      instance title tags mask switchtotag isfloating monitor */
        { "Gimp",     NULL,    NULL, 0,        0,          1,         -1 },
        { "Firefox",  NULL,    NULL, 1 << 8,   1,          0,         -1 },
    };

In this example, since Firefox is configured to start with tag 9 and switchtotag
is enabled, as soon as the application starts, dwm will switch to tag 9. When
Firefox closes, dwm will switch back to the tags which were active before the
application started.

Download
--------
* [dwm-switchtotag-6.2.diff](dwm-switchtotag-6.2.diff)

Author
------
* rid9 <rid99@protonmail.com>
