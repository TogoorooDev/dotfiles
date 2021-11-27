autorefresh
===========

Simple script to auto refresh surf pages.
Launch the script again to stop auto reloading (easy to use with dmenu)

	#!/bin/sh
	# Simple script to refresh surf page
	# thuban@singularity.fr

	REFRESH=3
	LOCKFILE=/tmp/surfrefresh.lock


	if [ -e $LOCKFILE ]; then
		echo "stop refreshing surf"
		PID=$(cat $LOCKFILE)
		rm $LOCKFILE
		kill -KILL $PID
	else
		echo $$ > $LOCKFILE
		while true; do
			kill -HUP $1
			sleep $REFRESH
		done
	fi
	exit 0
