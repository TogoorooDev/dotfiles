spawnprograms
=============

Description
-----------

This patch spawns each command in the `startup_programs` array on startup.
It's similar to the [autostart](../autostart/) patch,
however unlike autostart, it doesn't read anything from external files.

Example usage (put this into your `config.h`): 

``
static const char **startup_programs[] = {
    termcmd,
    someothercmd,
};
``

Download
--------

[dwm-spawnprograms-6.2.diff](dwm-spawnprograms-6.2.diff)

Author
------

* Zsolt Vadász <zsolt_vadasz@protonmail.com>
