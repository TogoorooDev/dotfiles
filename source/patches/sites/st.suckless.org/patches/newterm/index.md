New terminal in current directory
=================================

This patch allows you to spawn a new st terminal using Ctrl-Shift-Return. It
will have the same CWD (current working directory) as the original st instance.

The `getcwd_by_pid` function is inspired on [the function with the same name of
dvtm](https://github.com/martanne/dvtm/blob/master/dvtm.c#L1036).

By default the current st terminal will be the parent process of the new terminal.
This can conflict with the swallow patch for dwm and can result in the wrong st
terminal window being swallowd. The orphan variant of this patch works around this
issue by spawning the new terminal window as an orphan instead (meaning that it
will have no parent process).

Download
--------

* [st-newterm-0.8.2.diff](st-newterm-0.8.2.diff)
* [st-newterm-orphan-20210712-4536f46.diff](st-newterm-orphan-20210712-4536f46.diff)

Authors
-------
* Matías Lang
* Stein Bakkeby (orphan version)
