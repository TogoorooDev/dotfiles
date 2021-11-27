Fix Keyboard Input (Alpha version, use with caution!)
=====================================================

Description
-----------
This patch allows cli applications to use all the fancy key combinations that
are available to gui applications. The new scheme for encoding key combinations
was proposed by [Leonard](http://www.leonerd.org.uk/hacks/fixterms/) and
appears to have gained traction over the past years.

Notes
-----
Very early stage version of this patch - I'm just at the beginning of testing
it in real world settings. I tried to encode as many key combinations as
possible according to the new scheme. This might cause issues with existing
applications if they're not aware of it. Please report any issues that you come
across.

If you use `<C-[>` for `<Esc>`, I suggest that you remove the following line
from this patch to re-enable the behavior:

	{ XK_bracketleft,  ControlMask,                    "\033[91;5u",  0,  0},

If you use `<C-6>` for changing to the alternative file, I suggest that you
remove the following line from this patch to re-enable the behavior:

	{ XK_6,            ControlMask,                    "\033[54;5u",  0,  0},

I managed to bind the new mappings to actions in neovim.  If you're using
tmux make sure that it's a recent version, 2.5 works fine for me.  The
easiest way to know that this patch is working properly is to enter vim's
command mode by pressing `:` followed by pressing `<C-v>` and the desired key
combination.  This will print the key sequence that vim received.  Here are
some example mappings for vim:

	nmap <C-CR> :echo "<C-CR>"<CR>
	nmap <C-S-CR> :echo "<C-S-CR>"<CR>
	nmap <C-S-M-CR> :echo "<C-S-M-CR>"<CR>
	nmap <S-M-CR> :echo "<S-M-CR>"<CR>
	nmap <M-CR> :echo "<M-CR>"<CR>
	nmap <C-M-CR> :echo "<C-M-CR>"<CR>
	nmap <C-Tab> :echo "<C-Tab>"<CR>
	nmap <C-S-Tab> :echo "<C-S-Tab>"<CR>
	nmap <S-Tab> :echo "<S-Tab>"<CR>
	nmap <M-Tab> :echo "<M-Tab>"<CR>

Leonard suggests to bind the CSI sequence that starts an escape sequence to
`0x9b` instead of `0x1b` (Esc) followed by `0x5b` (left bracket, `[`). This
removes the double use of the Esc key in terminals. Programs that run in
terminals always have to work around the double use of the Esc key by
introducing a timeout that has to pass before a press of the plain Esc key is
acted upon. For example in vim the timeout is set by the `ttimeout` and
`ttimeoutlen` setting. If you want to get rid of the double use and the
timeout, replace all occurrences of `\033[` with `\233` in the key definition.
In addition, settings in your CLI programs have to be adjusted to disable the
timeout.

Here is an example.  This entry

	{ XK_underscore,   ControlMask,                    "\033[95;5u",  0,  0},

becomes the following:

	{ XK_underscore,   ControlMask,                    "\23395;5u",   0,  0},

Download
--------
* [st-fix-keyboard-input-20170603-5a10aca.diff](st-fix-keyboard-input-20170603-5a10aca.diff)
* [st-fix-keyboard-input-20170621-b331da5.diff](st-fix-keyboard-input-20170621-b331da5.diff)
* [st-fix-keyboard-input-20180605-dc3b5ba.diff](st-fix-keyboard-input-20180605-dc3b5ba.diff)

Authors
-------
* Jan Christoph Ebersbach - <jceb@e-jc.de>
