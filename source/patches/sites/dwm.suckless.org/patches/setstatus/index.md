setstatus
=========

Description
-----------
Enables to set the status with dwm itself. No more xsetroot bloat!
To change the status to `foo bar` execute:

    dwm -s "foo bar"

Piping into `dwm -s` is currently not supported but you can set the
status to the output of any command by doing something like:

    dwm -s "$(run_command_which_outputs_the_status)"

For example to set the status to the current date run:

    dwm -s "$(date)"

Download
--------
* [dwm-setstatus-6.2.diff](dwm-setstatus-6.2.diff)

Author
------
* Aleksandrs Stier (6.2)
