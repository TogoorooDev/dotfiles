Environment Variables
=====================

Description
-----------
This patch loads the name of the terminal emulator to be used as `termcmd`
from the environment variable `TERMINAL` using `getenv(3p)`.
It may be set as follows:

`$ export TERMINAL="$(which st)"`

The environment variable to use may be changed with the `TERMINAL_ENVVAR`
preprocessor macro.
A similar patch could be created for the `dmenucmd`.

Download
--------
* [dwm-environmentvars-terminal-20210807-dd4b656.diff](dwm-environmentvars-terminal-20210807-dd4b656.diff)

Author
------
* Aidan Hall <aidan.hall@outlook.com>
