Run GO menu immediately at startup
====================================

Description
-----------

This patch adds options to start surf right into the GO menu.

I like to use this in combination with patches `bookmarking` and
`search engines`.

It can be enabled either by setting 
```
static int startgo = 1;
```
in `config.def.h` and recompiliing, or through the 
command-line option `-h`:
```
surf -h
```

Download
--------

* [surf-startgo-20200913-d068a38.diff](surf-startgo-20200913-d068a38.diff)

Author
------

* Luca Wellmeier <luca_wellmeier@gmx.de>
