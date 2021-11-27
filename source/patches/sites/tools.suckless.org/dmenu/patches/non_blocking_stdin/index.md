Non-blocking stdin
==================

Description
-----------
A patch to have dmenu read stdin in a non blocking way, making it wait
for input both from stdin and from X. This way, you can continue feeding
dmenu while you type. This patch can be used along with the incremental
patch, so that you can use stdout to feed stdin.

Example:
	# Make a fifo and read from it for dmenu's input
	mkfifo foo
	while true; do cat foo; done | dmenu -w "$(xdotool getactivewindow)" -l 10
    
	# Append some items
	printf %b "foo\nbar\nbaz\n" > foo
	# Append some more items
	printf %b "food\nbarn" > foo

## nonblockingstdincontrol variant
The nonblockingstdincontrol variant of this patch allows you to use
control characters to dynamically clear the options list and set curr
& sel. So in addition to being able to append entries with the normal
version of the nonblockingstdin patch, this variant effectively makes
dmenu's option list continouslly reloadable and the selected item /
positioning controllable at runtime.

Supported Control Characters:

- \f - Clear the current items prior to following line
- \a - Set the following line to be equal to sel
- \b - Set the following line to be equal to curr

Example:
	# Make a fifo and read from it for dmenu's input
	mkfifo foo
	while true; do cat foo; done | dmenu -w "$(xdotool getactivewindow)" -l 10
	
	# And then separately, load a first set of options:
	printf %b "\ffoo\nbar\nbill" > foo
	# Load a different set of options using the \f escape:
	printf %b "\fbark\nbarn\nboo" > foo
	# Using \f, \a, and \b  - load a different set of options & preselect 2nd item:
	printf %b "\f\bbark\n\abarn\nboo" > foo

Download
--------
* [dmenu-nonblockingstdincontrol-4.9.diff](dmenu-nonblockingstdincontrol-4.9.diff)
* [dmenu-nonblockingstdin-4.9.diff](dmenu-nonblockingstdin-4.9.diff)
* [dmenu-nonblockingstdin-20160702-3c91eed.diff](dmenu-nonblockingstdin-20160702-3c91eed.diff)

Author
------
* Christophe-Marie Duquesne <chm.duquesne@gmail.com>
* koniu at riseup.net (update for 20160615 git master)
* Miles Alan - m@milesalan.com (nonblockingstdincontrol)
