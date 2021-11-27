statuscmd
=========

Description
-----------
This patch adds the ability to signal a status monitor program such as
[dwmblocks](https://github.com/torrinfail/dwmblocks) the location and button
when clicking on the status bar. Alternatively, there is a version that
executes shell commands defined in config.h instead of using signals.

Usage
-----
Both the nosignal version and the dwmblocks version will run their respective
shell commands/scripts with the environment variable BUTTON set to the button
that was pressed.

### With signals
Apply the statuscmd patch and set the `STATUSBAR` macro in config.h
to the name of the status monitor.

Apply the corresponding statuscmd patch to your status monitor if there is
one, or extend the program on your own. Feel free to add patches for other
status monitors.

#### Patching status monitors
* Associate each section with a signal number in the range of 1-31.
* When setting the status text, print each section's respective signal number
  as a raw byte before its text.
* Create a signal handler:

	void sighandler(int signum, siginfo_t *si, void *ucontext)
	{
		int signal = signum - SIGRTMIN;
		int button = si->si_value.sival_int; /* if button is zero, the signal is not from a button press */
		... /* do whatever you want */
	}

* Register the signal handler for each section in the following way, with
  'signal' being the same signal from the first step:

	struct sigaction sa = { .sa_sigaction = sighandler, .sa_flags = SA_SIGINFO };
	sigaction(SIGRTMIN+signal, &sa, NULL);

### Without signals
Apply the statuscmd-nosignal patch and fill the `statuscmds` array in config.h
with `StatusCmd` structs, which take a shell command string and an integer
identifier.

When setting the status, print the integer identifier as a raw byte before its
respective text.

For example, with `statuscmds` defined as such:

	static const StatusCmd statuscmds[] = {
		{ "volume",  1 },
		{ "cpu",     2 },
		{ "battery", 3 },
	};

And root name set like this:

	xsetroot -name "$(printf '\x01Volume |\x02 CPU |\x03 Battery')"

Clicking on 'Volume |' would run `volume`, clicking on ' CPU |'
would run `cpu` and clicking on ' Battery' would run `battery`.

Example
-------
A script run from dwm or dwmblocks with this patch might look like this:

	#!/bin/sh

	case $BUTTON in
		1) notify-send "CPU usage" "$(ps axch -o cmd,%cpu --sort=-%cpu | head)" ;;
		3) st -e htop ;;
	esac

Notes
-----
The signal version is not compatible with OpenBSD since it relies on `sigqueue`.

Be careful with newline characters in the status text since '\n' is equal to
'\x0a', which is a valid signal number. The problem where having certain
undrawable characters in the status bar can make dwm laggy is fixed since dwm
will not attempt to draw them with this patch.

Download
--------
### dwm patches
* [dwm-statuscmd-20210405-67d76bd.diff](dwm-statuscmd-20210405-67d76bd.diff)
* [dwm-statuscmd-nosignal-20210402-67d76bd.diff](dwm-statuscmd-nosignal-20210402-67d76bd.diff)

If using [status2d](https://dwm.suckless.org/patches/status2d/), use these patches instead of the
above ones on top of a build already patched with status2d:

* [dwm-statuscmd-status2d-20210405-60bb3df.diff](dwm-statuscmd-status2d-20210405-60bb3df.diff)
* [dwm-statuscmd-nosignal-status2d-20210402-60bb3df.diff](dwm-statuscmd-nosignal-status2d-20210402-60bb3df.diff)

### Status monitor patches
* [dwmblocks-statuscmd-20210402-96cbb45.diff](dwmblocks-statuscmd-20210402-96cbb45.diff)

Author
------
* Daniel Bylinka - <daniel.bylinka@gmail.com>
