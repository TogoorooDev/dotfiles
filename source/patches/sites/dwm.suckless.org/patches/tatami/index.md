tatami layout
=============

Description
-----------
This patch adds a new layout, tatami, that arranges all windows like
tatami tiles. This patch forms 'mats' of 5 or less windows each, and
each mat has 5 different possible arrangements. The mats then form a 
stack as shown in the `7+ windows` diagram below.

	+-----------+-----------+  +-----------+-----------+
	|           |           |  |           |           |
	|           |           |  |           |     2     |
	|           |           |  |           |           |
	|     1     |     2     |  |     1     +-----------+
	|           |           |  |           |           |
	|           |           |  |           |     3     |
	|           |           |  |           |           |
	+-----------+-----------+  +-----------+-----------+
		2 windows                  3 windows

	+-----------+-----+-----+  +-----------+-----------+
	|           |     |     |  |           |     2     |
	|           |  2  |  3  |  |           +-----+-----+
	|           |     |     |  |           |     |     |
	|     1     +-----+-----+  |     1     |  3  |  4  |
	|           |           |  |           |     |     |
	|           |     4     |  |           +-----+-----+
	|           |           |  |           |     5     |
	+-----------+-----------+  +-----------+-----+-----+
		4 windows                  5 windows

	+-----------+---+-------+  +-----------+-----------+
	|           |   |   3   |  |           |    new    |
	|           | 2 +---+---+  |           +---+-------+
	|           |   |   |   |  |           |   |   4   |
	|     1     |   | 4 |   |  |     1     | 3 +---+---+
	|           |   |   | 5 |  |           |   | 5 |   |
	|           +---+---+   |  |           +---+---+ 6 |
	|           |   6   |   |  |           |   7   |   |
	+-----------+-------+---+  +-----------+-------+---+
		6 windows                  7+ windows


Usage
-----
1. Download the patch and apply according to the [general instructions](.).
2. The patch automatically includes the `tatami.c` source file and adds `tatami` 
to the `Layout` section of your `config.def.h` file. If you have already installed
dwm, change config.def.h to be your config.h file.
3. **Note that this patch ignores resize hints.**
3. The default keybinding is [Alt]+[y] for tatami.

Download
--------
* [dwm-tatami-6.2.diff](dwm-tatami-6.2.diff)

Maintainer
----------
* Sarthak Shah - <shahsarthakw@gmail.com>
