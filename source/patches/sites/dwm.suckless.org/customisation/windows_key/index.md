Change Mod1 key to the Windows key in config.h
==============================================
dwm's documentation refers to Mod1 as the modifier key that you must press to
issue commands to it. On most keyboards, Mod1 is mapped to the left Alt key.
Most new keyboards now come equipped with the *Windows* key. Since no known
UNIX/X applications are known to use the Windows key, it is an excellent
alternative mapping to issue commands to dwm.

In config.h, under the comment `/* key definitions */`, you can find the line

	#define MODKEY Mod1Mask

In order to change dwm's modifier key to the Windows key, you can simply change
its value definition to Mod4Mask.

	#define MODKEY Mod4Mask

The following patch also produces the same result:

	--- a/config.def.h      Sun Jul 27 03:34:57 2008 +0100
	+++ b/config.def.h      Sun Jul 27 23:04:57 2008 +0100
	@@ -35,7 +35,7 @@
	 };
	
	 /* key definitions */
	-#define MODKEY Mod1Mask
	+#define MODKEY Mod4Mask
	 #define TAGKEYS(KEY,TAG) \
	        { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	        { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \

Can I use any other modifier key?
---------------------------------
Yes. There are 5 modifiers, Mod1Mask to Mod5Mask. They are associated to up-to
three keysyms (keycodes) from the X window server. To show the current
association on your keyboard, run `xmodmap` with no arguments. It will show
something like:

	$ xmodmap 
	xmodmap:  up to 3 keys per modifier, (keycodes in parentheses):
	
	shift       Shift_L (0x32),  Shift_R (0x3e)
	lock        Caps_Lock (0x42)
	control     Control_L (0x25),  Control_R (0x6d)
	mod1        Alt_L (0x40),  Alt_L (0x7d),  Meta_L (0x9c)
	mod2        Num_Lock (0x4d)
	mod3      
	mod4        Super_L (0x7f),  Hyper_L (0x80)
	mod5        Mode_switch (0x5d),  ISO_Level3_Shift (0x7c)

Using `xev`, a utility to show X events, such as key presses, we can quickly
identify which keysym (keycode) combination a particular key has, and associate
that to a modifier using `xmodmap`.
