Color Message
=============

Description
-----------
Based on the message patch, This patch lets you add a message to your lock screen, using 24 bit color ANSI escape codes.

Exactly like in the original patch, You can place a default message in `config.h`, and you can also pass a message with `-m message`

For example, you can run

	slock -m "$(printf "text colored \x1b[38;2;0;255;0m green\x1b[39m\n")"

to color a single word

Or, you can go all in and run

	slock -m "$(cowsay "$(fortune)" | lolcat -ft)"

Notes
-----
This adds three items to `config.h`:

* `message` - the default message
* `text_color` - the color used when no color codes are in effect. can be a hex color or a colorname
* `font_name` - which must be some valid X11 font name like "6x10".

*A list of font names can be generated with* `slock -f`

*When using lolcat you should add the -ft options*

Download
--------
* [slock-colormessage-20200210-35633d4.diff](slock-colormessage-20200210-35633d4.diff)


Authors
-------
* Guy Shefy - guyshefyb@gmail.com
* Based on patch by Blair Drummond - blair.robert.drummond@gmail.com
