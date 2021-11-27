Goals
=====

This page is to discuss and maybe add comments on the future of st.

TODO
----
* see the TODO file in the [repository](//git.suckless.org/st/plain/TODO)

Theoretical features
--------------------
* st should keep a pointer to the beginning of the oldest line, because we
  would like to keep lines and not part of them (pancake).
* Edit previous text in the terminal like in Plan 9 and 9term (jt_).

Goals
-----
* Have a working graphical terminal for terminal applications.
* Do not reimplement tmux and his comrades.

Non-goals
---------
* Filters that change colour (should be done by tmux or something doing the
  higher layers in st).
* Server to save sessions in case of X crash (should be done by dtach or tmux).
* Unlimited scrollback buffer (done by dvtm or tmux).
* URL selecting/launching in browser similiar to vimperator's mark mode and the
  urxvt script. However, this can be done by a simple shortcut in dwm which will
  launch your plumber on the current select buffer. St has easy select through
  double-click. This keeps the complex logic out of the st context.

Links
-----
* [Repository](//git.suckless.org/st)
