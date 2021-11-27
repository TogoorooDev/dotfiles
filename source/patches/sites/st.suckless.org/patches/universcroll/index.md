universcroll
============

Description
-----------
With *scroll*(1) and default binds (as of 0.8.4), how to scroll?
- Inside alt screen? Mouse{4,5} to scroll {Up,Down}. :)
- Outside alt screen? Shift+Mouse{4,5} to scroll {Up,Down}. :(

With universcroll patch, always use Mouse{4,5} to scroll {Up,Down}.
Doesn't matter alt screen or not. No more `^Y^Y^Y^Y^Y^E^E^E^E^E`!

`universcroll-example` on top of `universcroll` makes some extra
changes:
- Set scroll program = "scroll"
- Mouse wheel scroll enabled only with NO_MOD.
- Mouse wheel zoom enabled with ShiftMask/ANY_MOD.

Download
--------
- [st-universcroll-0.8.4.diff](st-universcroll-0.8.4.diff)
- [st-universcroll-example-0.8.4.diff](st-universcroll-example-0.8.4.diff)

Notes
-----
In the provided config, both Mouse{4,5} and Shift+{Page_Up,Page_Down}
emit {`\033[5;2~`,`\033[6;2~`}. In default *scroll*(1) config, those
sequences scroll {Up,Down} by full page each time (like TTY). This is
maybe not desired behavior.

You can change *st*(1) config to use different sequences and define how
*scroll*(1) responds to sequences in *scroll(1)*'s config.

In *st*(1) config, some keys are defined to send certain sequences in
`key[]`. Inside `mshortcuts[]` and `shortcuts[]`, use function `ttysend`
with argument `{.s = ""}` to send sequences.

My settings:
   //st
   { XK_NO_MOD,            Button4, ttysend,        {.s = "\033[1;3A"}, 0, -1 },
   { XK_NO_MOD,            Button5, ttysend,        {.s = "\033[1;3B"}, 0, -1 },
   //scroll
   {"\033[1;3A",   SCROLL_UP,    3},       /* Mod1+Up */
   {"\033[1;3B",   SCROLL_DOWN,  3},       /* Mod1+Down */

Bugs
----
Non-readline shell (zsh, fish) can have prompt issues with *scroll*(1)
(Scrolling down by line after scrolling up, among other things). More
problems with non-PS1 prompt.

Author
------
- [Dennis Lee](mailto:dennis@dennislee.xyz)

`universcroll` was made possible by
[scrollback-mouse-altscreen](../scrollback).  All alt screen detection
code is from that patch.
