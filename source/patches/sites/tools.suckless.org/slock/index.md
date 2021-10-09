slock
=====
Simple X display locker. This is the simplest X screen locker we are aware of.
It is stable and quite a lot of people in our community are using it every day
when they are out with friends or fetching some food from the local pub.

Configuration
-------------
slock is configured via `config.h` like most other suckless.org software. Per
default it will turn the screen red on any keyboard press, if you are less
paranoid and turning red on failed login attempts suffices for you, set
`failonclear = 0` in `config.h`.

Development
-----------
You can [browse](//git.suckless.org/slock) its source code repository or get a
copy using the following command:

	git clone https://git.suckless.org/slock

Download
--------
* [slock-1.4](//dl.suckless.org/tools/slock-1.4.tar.gz) (20161120)

Xautolock
---------
slock can be started after a specific period of user inactivity using
[xautolock](http://www.ibiblio.org/pub/linux/X11/screensavers/). The command
syntax is:

	xautolock -time 10 -locker slock

Simpler alternatives to xautolock might be
[xssstate](//git.suckless.org/xssstate/) or
[xss](http://woozle.org/~neale/src/xss.html).

