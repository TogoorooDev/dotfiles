Synchronized rendering
======================

Summary
-------
Better draw timing to reduce flicker/tearing and improve animation smoothness.

Background
----------

Terminals have to guess when to draw and refresh the screen. This is because
the terminal doesn't know whether the application has completed a "batch" of
output, or whether it's about to have more output right after the refresh.

This means that sometimes the terminal draws before the application has
completed an output "batch", and usually this results in flicker or tearing.

In st, the parameters which control the timing are `xfps` and `actionfps`.
`xfps` determines how long st waits before drawing after interactive X events
(KB/mouse), and `actionfps` determines the draw frequency for output which
doesn't follow X events - i.e. unattended output - e.g. during animation.


Part 1: auto-sync
-----------------

*NOTE*: this patch (part 1) is not required if you use st-master. It was
merged upsream on 2020-05-10 and will be included in the next release.

This patch replaces the timing algorithm and uses a range instead of fixed
timing values. The range gives it the flexibility to choose when to draw, and
it tries to draw once an output "batch" is complete, i.e. when there's some
idle period where no new output arrived. Typically this eliminates flicker and
tearing almost completely.

The range is defined with the new configuration values `minlatency` and
`maxlatency` (which replace xfps/actionfps), and you should ensure they're at
your `config.h` file.

This range has equal effect for both X events and unattended output; it doesn't
care what the trigger was, and only cares when idle arrives. Interactively idle
usually arrives very quickly so latency is near `minlatency`, while for
animation it might take longer until the application completes its output.
`maxlatency` is almost never reached, except e.g. during `cat huge.txt` where
idle never happens until the whole file was printed.

Note that the interactive timing (mouse/KB) was fine before this patch, so the
main improvement is for animation e.g. `mpv --vo=tct`, `cava`, terminal games,
etc, but interactive timing also benefits from this flexibility.

Part 2: application-sync
------------------------

The problem of draw timing is not unique to st. All terminals have to deal
with it, and a new suggested standard tries to solve it. It's called
"Synchronized Updates" and it allows the application to tell the terminal when
the output "batch" is complete so that the terminal knows not to draw partial
output - hence "application sync".

The suggestion - by iTerm2 author - is available here:
https://gitlab.com/gnachman/iterm2/-/wikis/synchronized-updates-spec

This patch adds synchronized-updates/application-sync support in st. It
requires the auto-sync patch above installed first. This patch has no effect
except when an application uses the synchronized-update escape sequences.

Note that currently there are very few terminals or applications which support
it, but one application which does support it is `tmux` since 2020-04-18. With
this patch nearly all cursor flicker is eliminated in tmux, and tmux detects
it automatically via terminfo and enables it when st is installed correctly.


Download
--------
Part 1 is independent, but part 2 needs part 1 first. Both files are git
patches and can be applied with either `git am` or with `patch`. Both files
add values at `config.def.h`, and part 2 also updates `st.info`.

* Part 1 (merged upstream): [st-autosync-0.8.3.diff](st-autosync-0.8.3.diff)
* Part 2 (st 0.8.3): [st-appsync-0.8.3.diff](st-appsync-0.8.3.diff)
* Part 2 (st master 2020-06-17 or later):
  [st-appsync-20200618-b27a383.diff](st-appsync-20200618-b27a383.diff)


Author
------
* Avi Halachmi (:avih) - [https://github.com/avih](https://github.com/avih)
  Contact email is available inside the patch files.
