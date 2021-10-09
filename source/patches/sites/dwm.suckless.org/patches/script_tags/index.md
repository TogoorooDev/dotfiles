script_tags
===========

Description
-----------
This patch does two things:
1) It removes the code that generates the bar, but still leaves a "toggleable" area.

2) On X events, it writes all the tag and layout information to a user defined fifo.

This allows any bar that reads stdin to be used in conjuction with dwm.

The patch introduces 3 variables:

barheight: sets the size of the top gap in pixels(this gap remains toggleable with the togglebar function).

sepchar: sets the character used to delimitate different workspaces(see below).

tagfile: sets the path of the file to wich the tag and layout information is written to.

The tagfile uses an easy syntax.

Each tagname is prefixed with a character describing the state of that tag.

There are 4 different states:

state '%e': tag is empty and not focused

state '%E': tag is empty and focused

state '%o': tag is occupied and not focused

state '%O': tag is occupied and focused

Each tag name is also suffixed with %f, this makes scripting the output a bit easier.

All of these predefined strings are easily modified in dwm.c.

The different tags with respective tag information are separated by the sepchar variable defined in config.h.

A simple example would be:

Attention
-----------

Because of how named pipes work, dwm will stall if no process is reading from the fifo.
If one does not want to use any bar, one can call
```
tail -f /tmp/dwm_tags &
```
from .xinitrc or in another tty.


Example
-----------
The script I currently use in conjunction with lemonbar is:
```
tail -f /tmp/dwm_tags 2>/dev/null | while IFS= read -r line; do
         sed\
          -e "s/%O/%{F#FFFFFF}%{B#292c2e}/g"\
          -e "s/%o/%{F#FFFFFF}%{B#5F819D}/g"\
          -e "s/%O/%{F#292c2e}%{B#FFFFFF}/g"\
          -e "s/%E/%{F#292c2e}%{B#FFFFFF}/g"\
          -e 's/%f/%{F}%{B}/g' <<< $line
done  | lemonbar -d  -B "#292c2e" -F "#FFFFFF" -g x25 

```


Download
-----------
* [dwm-script_tags-6.2.diff](dwm-script_tags-6.2.diff) (2020-08-30)
* Old version without fifo, wouldn't recommend it:[dwm-script_tags-without_fifo.diff](dwm-script_tags-without_fifo.diff)

Authors
-----------
* David Wiedemann <david.wiedemann2 [at] gmail.com>




