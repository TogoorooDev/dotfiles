steam
=====

Description
-----------
The Steam client, and steam windows (games), tends to trigger a ConfigureNotify request every time
the window gets focus. More so, the configure events passed along from Steam may have the wrong x
and y coordinates which can make the window, if floating, jump around the screen. Another observed
symptom is the steam window continuously sliding towards the bottom right corner of the screen.

This patch works around this age-old issue by ignoring the x and y co-ordinates for ConfigureNotify
requests relating to Steam windows.

It should be noted that this is a simple and crude patch, and while it can be made more generic
I have intentionally left it hardcoded against steam in particular as few other windows behaves
this badly.

Download
--------
* [dwm-steam-6.2.diff](dwm-steam-6.2.diff)

Author
------
* Stein Bakkeby <bakkeby@gmail.com>
