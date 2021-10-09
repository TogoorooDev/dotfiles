Launching
---------
To launch dwm, ideally you should setup a `~/.xinitrc` with at least `exec
dwm`.

Introduction
------------
Using dwm can be done in pure keyboard control or through some extra mouse
handling. See the [config.def.h](//git.suckless.org/dwm/plain/config.def.h) for
what are the default bindings. They are used in this tutorial.

	[Shift]+[Alt]+[Enter] - launch terminal
	[Alt]+[p] - dmenu for running programs like the x-www-browser

By default there are 9 tags.

Window model
------------
Launch a few terminals with `[Shift]+[Alt]+[Enter]` and dwm will _tile_ the
windows between the **master** and **stack**. A new terminal appears on the
**master** window. Existing windows are pushed upon a **stack** to the right of
the screen. `[Alt]+[Enter]` toggles windows between master and stack.

        +------+----------------------------------+--------+
        | tags | title                            | status +
        +------+---------------------+------------+--------+
        |                            |                     |
        |                            |                     |
        |                            |                     |
        |                            |                     |
        |          master            |        stack        |
        |                            |                     |
        |                            |                     |
        |                            |                     |
        |                            |                     |
        +----------------------------+---------------------+

Moving Around
-------------
To **move to another terminal**, press `[Alt]+[j]` or `[Alt]+[k]`.

To **move a terminal to another _tag_**, hover to the terminal and press
`[Shift]+[Alt]+[2]`. Note! If you are a frequent user of the text editor 'nano'
the key sequence [Shift]+[Alt]+[4] will stomp on nano's softwrap M-$. To get
around this you can unbind nano's M-$ in .nanorc thus:

	unbind M-$ all

and rebind it to a new sequence thus (here bind it to 'Meta Key' + ';'):

	  bind M-; softwrap all

There are several other nano key sequences that dwm will stomp on - use the above example to fix nano up.

To **focus on another _tag_**, press `[Alt]+[tag number]`.

To **change the amount of windows in the master area**, press `[Alt]+[d]` (Decrease) or `[Alt]+[i]` (Increase).

To **toggle a window between the master and stack area**, press `[Alt]+[Return]`

As stated in the dwm manpage, you can click tags with the left mouse button and simulating `[Alt]+[tag number]`, but you can also click another tag with the right mouse button in order to bring those windows additionally
into your current focus.

To **kill a window**, press `[Shift]+[Alt]+[c]`.

Layouts
-------
By default dwm is in **tiled** layout mode. Ensure it is tiled mode with:

	[Alt]+[t]

You should also notice the `[]=` symbol between the tag numbers and the title
bar.

dwm has two further layout modes, **floating** `><>` `[Alt]+[f]` and
**monocle** `[M]` `[Alt]+[m]`. Monocle is good for ensuring a window is kept
maximized and focused. This is useful in web kiosk environments and watching
flash videos. Further layout modes can be included through
[patches](//dwm.suckless.org/patches/).

Floating
--------
Floating layout will be familiar to Windows users. Use `[Alt]+[right mouse
button]` to resize the floating window and `[Alt]+[left mouse button]` to move
it around. This can also be used to raise a floating window.

There are several ways to get specific windows into being managed as a floating
window, despite the tiled layout being activated. First there is
`[Alt]+[Shift]+[space]`, which will toggle floating mode on the active window.
Second method is to simply resize the window using `[Alt]+[right mouse button]`.
The last method is to `[Alt]+[middle mouse button]` onto the window, to toggle
it in being floating. These floating windows then can be used to force certain
window sizes, when some application requires this for aesthetics or simply to
being usable.

If you want to set some type of window to be always floating, look at the
[config.def.h](//git.suckless.org/dwm/plain/config.def.h) and the `rules`
array, where the last but one element defines this behaviour.

Quitting
--------
To quit dwm cleanly:

	[Shift]+[Alt]+[q]

Status
------
By default dwm is showing `dwm-X.X` in its statusbar. This text can be changed
by setting the `WM_NAME` property of the root window.

Using the tools of X.org, this can be set using:

	% xsetroot -name "Some Text"

There are various tools and methods to populate this text with useful
information from your system or services running on your system. A barebone for
doing this in C is [dwmstatus](../status_monitor/). See the
[xinitrc](xinitrc.example) example for how to do it using a script.
