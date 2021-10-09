externalpipe-signal
===================

Description
-----------

Run an externalpipe command upon receiving the SIGUSR1 signal. This is helpful
for supporting externalpipe scripts which work across multiple surf instances.
With the example script you can access a dmenu populated with the contents of
all tags contents of all open surf windows for directly pasting.

Apply this patch on top of surf [externalpipe](/patches/externalpipe).

Example
-------
Add the example script to your `$PATH`:
- [externalpipe_buffer.sh](externalpipe_buffer.sh)

Add to your `config.h`:
	    static char *externalpipe_sigusr1[] = {"/bin/sh", "-c", "externalpipe_buffer.sh surf_strings_read"};

Add to your WM as a hotkey:
	    externalpipe_buffer.sh dmenu_type

Download
--------

* [surf-externalpipe-signal-2.0.diff](surf-externalpipe-signal-2.0.diff)

Author
------

* Miles Alan - m@milesalan.com
