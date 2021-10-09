externalpipe-signal
===================

Description
-----------

Run an externalpipe command upon receiving the SIGUSR1 signal. This is helpful
for supporting externalpipe scripts which work across multiple st instances.
With the example script you can access a dmenu populated with strings from all
open st instances.

Apply this patch on top of st [externalpipe](/patches/externalpipe).

Example
-------
Add the example script to your `$PATH`:
- [externalpipe_buffer.sh](externalpipe_buffer.sh)

Add to your `config.h`:
	    char *externalpipe_sigusr1[] = {"/bin/sh", "-c", "externalpipe_buffer.sh st_strings_read"};

Add to your WM as a hotkey:
	    externalpipe_buffer.sh dmenu_type

Download
--------

* [st-externalpipe-signal-0.8.2.diff](st-externalpipe-signal-0.8.2.diff)

Author
------

* Miles Alan - m@milesalan.com
