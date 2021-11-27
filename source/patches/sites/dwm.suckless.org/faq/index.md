FAQ
===
	Q: I've got a 1 or 2 pixel gap between the right side of my terminal and the
	   right side of the screen, and I want to turn it off.

	A: This is due to the column-based nature of terminals. Terminals don't just
	   insert space somewhere, but tell the WM they can't be resized in a certain
	   way. The terminal can't use the "wasted space" anyway, so this is purely
	   aesthetics.

	   You can change `static const int resizehints = 1;` to `0` in
	   config.h to turn resizehints off. This wastes the same amount of  space
	   inside the terminal window that would otherwise be wasted outside.

	Q: Why are there gaps between my windows?

	A: See the question above.

	Q: How do I find out the values of the rules[] array in config.h?

	A: The class, instance and title properties of an X11 window can be
	   found out by issuing xprop(1). The corresponding values are:

	   	WM_CLASS(STRING) = instance, class
		WM_NAME(STRING) = title

