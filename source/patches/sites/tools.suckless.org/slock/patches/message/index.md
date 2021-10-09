Message
=======

Description
-----------
This patch lets you add a message to your lock screen. You can place a default
message in `config.h`, and you can also pass a message with `-m message`

So, for instance, you can run

	slock -m "Locked at  $(date "+%a %d, %H:%M:%S")"

Or if you want a silly lockscreen

	slock -m "$(cowsay "$(fortune)")"

Notes
-----
This adds three items to `config.h`: 

* `message` - the default message 
* `text_color` - which can be a hex color or a colorname (like "black")
* `font_name` - which must be some valid X11 font name like "6x10". This variable was (somewhat wrongly) named "text_size" in the previous version.

*A list of font names can be generated with* `slock -f`

Download
--------
* [slock-message-20191002-b46028b.diff](slock-message-20191002-b46028b.diff) --- [bug-fixes](bug-fixes)


Previous Version
----------------
* [slock-message-20180626-35633d4.diff](slock-message-20180626-35633d4.diff)

Authors
-------
* Blair Drummond - blair.robert.drummond@gmail.com
