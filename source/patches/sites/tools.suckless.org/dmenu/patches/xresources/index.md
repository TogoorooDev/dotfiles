xresources
==========

Description
-----------
This patch was originally made by Michał Lemke has been slightly modified to
work with dmenu 4.9.

This patch adds the ability to configure dmenu via Xresources. At startup,
dmenu will read and apply the change to the applicable resource. Below are the
resources that can be changed and what they change:

- dmenu.font          : font or font set
- dmenu.background    : normal background color
- dmenu.foreground    : normal foreground color
- dmenu.selbackground : selected background color
- dmenu.selforeground : selected foreground color

Note: Values in Xresources will override values in config.h, but will be
overridden by command line arguments.

Download
--------
* [dmenu-xresources-4.9.diff](dmenu-xresources-4.9.diff)

Authors
-------
* Michał Lemke - @melek on [Bitbucket](https://bitbucket.org/melek/dmenu2/)
* Pratik Bhusal - dmenu-xresources-4.9 port
* Nihal Jere <nihal@nihaljere.xyz> (20200302)
* Francesco Minnocci <ad17fmin@uwcad.it> - command line parameters fix
