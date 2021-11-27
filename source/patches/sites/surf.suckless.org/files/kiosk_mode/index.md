kiosk mode
==========

Description
-----------

With these steps you can change your system into a kiosk mode terminal.
Please note that you do not have any access to the system but the web
browser. To undo the changes you need a rescue system.

Software
--------

This software has to be installed on the system for my whoto to work:

* 'lxdm' login manager
* 'i3' window manager
* 'surf' web browser

Feel free to use other components if desired.

Basic setup
-----------

We have to ensure that the basic system can not be altered, so we lock
all user accounts ('root' and 'kiosk' in this example):

        passwd -l root
        passwd -l kiosk

Additionally we create a file '/etc/X11/xorg.conf.d/15-no-vt.conf'.

        Section "ServerFlags"
                Option  "DontVTSwitch"  "True"
        EndSection

Now X.org does not allow to change to the virtual terminal via
'Ctrl-Alt-F1'.

Depending on your setup you may want to stop and disable services like
ssh daemon and/or disable public key authentication.

Login manager
-------------

As the accounts are locked we need to enable auto login in the login
manager. To make sure the correct window manager is started we add this
in '/etc/lxdm/lxdm.conf', too.

        autologin=kiosk
        session=i3

Window manager
--------------

The window manager 'i3' is locked down to just start web browser 'surf'
with parameter '-K' in fullscreen mode. All key strokes are disallowed,
except Ctrl+Shift+C to poweroff the system (via 'systemd'). Save the
following file to '/home/kiosk/.i3/config':

        set $mod Mod4

        # shut down system with systemd/polkit
        bindsym Control+Shift+C exec /usr/bin/systemctl poweroff

	# make surf start in fullscreen
        for_window [class="Surf"] fullscreen

	# execute surf
        exec /usr/bin/surf -K //surf.suckless.org/

Now reboot your system and have fun. ;)

Author
------

* Christian Hesse <mail@eworm.de>
