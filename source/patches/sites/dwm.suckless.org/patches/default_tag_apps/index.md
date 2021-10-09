default tag applications
========================

Description
-----------
This patch is for those who dedicate each tag to certain general tasks.  Tag 1 might be the tag used for all terminal tasks, tag 2 might be for internet/browser things etc.  When you have these tags already mapped out, generally you open one application more than any other in each tag.  This patch aims at harnessing this workflow for improvement of speed and practicality.

This project is managed and the patch is generated through [this git repo](https://github.com/NlGHT/dwm-default-tag-apps).

Usage
-----
Setting a key to spawndefault will launch the default application set for the tag you are currently on.  You can set the applications to be run for each tag in `config.h` as seen here:

`*defaulttagapps[] = { "st", "librewolf", "onlyoffice-desktopeditors", "nautilus", NULL, "lutris", "krita", "ardour", "mirage" };`

The example keyboard shortcut included is `Mod+s` but of course feel free to change it to whatever you want.

Currently multi-monitor is supported up to 8.  You can change this by changing the size of `lastchosentag[8]` and `previouschosentag[8]` in `dwm.c`.

Download
--------
* [dwm-default-tag-apps-20210327-61bb8b2.diff](dwm-default-tag-apps-20210327-61bb8b2.diff)

Author
------
* Night - <night@nightmusic.net>

