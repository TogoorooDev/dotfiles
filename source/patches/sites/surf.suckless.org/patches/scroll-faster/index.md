Scroll faster
=============

Description
-----------

This patch allows you to make your mouse wheel scroll faster. It simply multiplies delta_y got from GDK event and pass it forward. 

I would be nice to make it per txt file configuration and systemwide, but I cannot make it work that way. If it's possible then please let me know. I tried systemd hwdb config but didn't success.

At the moment it's hardcoded to factor 7. Change it per your needs.

Download
--------

* [surf-scrollmultiply-2.0.diff](surf-scrollmultiply-2.0.diff) (1304) (20180413)

Authors
-------

* Marcin sZpak <szpak@reakcja.org>
