email notifications
===================

Description
-----------
This init script is based on some ideas taken from the dwm ML. It adds email
notification using `fetchmail`. It also adds the functionality of showing the
content of the file `$HOME/.message` when it exists. This can be used for
displaying info by other programs writing to this file.

When a new email arrives a flashing text message is shown on the dwm's
status bar.

Config .fetchmailrc
-------------------
This config works with GMail over IMAP with the IDLE extension for low bandwidth usage:

	poll imap.gmail.com port 993 proto IMAP user "<your_user>@gmail.com"
		there with password "<your_pass>" keep ssl idle

Init script
-----------
The notification is flashing during 60 seconds, then it is removed. Lines
written to `.message` are displayed during a second in the status bar. If
`.message` is deleted, the normal status message (date and uptime) returns.

A pipe must be used with `fetchmail` when using IDLE extension because this way
it waits for updates from the inbox not doing polling. If the `.message` file
exists with some content, it is preserved and no email notification is shown.

	fetchmail --check 2>/dev/null | while read line; do
		new=`echo $line | sed 's/(//' | awk '{print $1-$3}'`
		if [ $new != 0 ] && [ ! -e ~/.message ]; then
			echo "New mail($new)" > ~/.message
			echo "!!! !!! !!!" >> ~/.message
			sleep 60
			if grep '^New mail' ~/.message >/dev/null 2>/dev/null; then
				rm -f ~/.message
			fi
		fi
	done &
	while true; do
		if [ -r ~/.message ]; then
			while read line; do
				xsetroot -name "$line"
				sleep 1
			done < ~/.message
		else
			xsetroot -name "`date` `uptime | sed 's/.*,//'`"
			sleep 1
		fi
	done &
	exec dwm
	rm -f ~/.message

Author
------
* Ricardo Catalinas Jiménez <jimenezrick@gmail.com>
