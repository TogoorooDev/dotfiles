keymodes
========

Description
-----------
This patch provides key modes (like in Vim). There are two key modes:

1. `COMMANDMODE`: In this mode any key is grabbed and only the registered
   command keys have any effect.
2. `INSERTMODE`: This is the normal key mode, in which the original key
   bindings of dwm and applications are effective and text can be entered.

With key modes you can use any key binding for window management without
risking conflicts with existing key bindings in applications or have a
Vim-style dwm.

There are two different patches:

* keymodes: the minimal patch
* vim-keymodes: This patch tries to emulate the key bindings of Vim. Therefor
   it includes additional functions, which depend on the
   [flextile patch](../flextile/).

Configuration
-------------
1. Download the favoured patch and apply it according to the
   [general instructions](.). If you choose vim-keymodes you will have to apply
   the [flextile patch](../flextile/) first.
2. Transfer the changes made by the patch in `config.def.h` to your `config.h`,
   if needed; please see the patch file for details.
3. Verify the following lines in the aforementioned arrays; the key bindings
   are set in reference to a german keyboard layout. The entries in the `cmdkeys`
   array are defined like those in the original `keys` array of dwm and take
   precedence over the key bindings defined in the `commands` array. The modifier
   and keysym definitions in the `commands` array are themselves arrays with four
   entries, whereas the first entry in the modifier array corresponds to the first
   entry in the keysym array and so forth. You can find an example configuration
   [here][dwm-keymodes-vim-config.h].

	static Key keys[] = {
		/* modifier             key                 function       argument */
		{ MODKEY,               XK_Escape,          setkeymode,    {.ui = COMMANDMODE} },

	static Key cmdkeys[] = {
		/* modifier             keys                function       argument */
		{ 0,                    XK_Escape,          clearcmd,      {0} },
		{ ControlMask,          XK_c,               clearcmd,      {0} },
		{ 0,                    XK_i,               setkeymode,    {.ui = INSERTMODE} },
	};
	static Command commands[] = {
		/* modifier (4 keys)    keysyms (4 keys)    function       argument */
		...
	};

Usage
-----
With this patch dwm starts in `COMMANDMODE` and you can use the key bindings as
defined in the `commands` array in `config.h`. Press `Escape` or `CTRL+c` to
abort a command input and press `i` (in the default configuration) to enter
`INSERTMODE` and use dwm normally with the key bindings defined in the `keys`
array, navigate in applications and insert text. To get from `INSERTMODE` to
`COMMANDMODE` press `ALT+Escape` (in the default configuration).

Download
--------
* [dwm-keymodes-5.8.2.diff](dwm-keymodes-5.8.2.diff) (20100611, joten (at) freenet (dot) de)
* [dwm-keymodes-vim-5.8.2.diff](dwm-keymodes-vim-5.8.2.diff) (20100611, joten (at) freenet (dot) de)
