movethrow
=========

Description
-----------
This patch is very similar to [moveplace](https://dwm.suckless.org/patches/moveplace/),
but with slightly altered functionality.

It allows you to "throw" windows in 4 directions. Thrown windows will be moved along
just the X or Y axis as far as possible without them exceeding the screen borders.
Unlike in [moveplace](https://dwm.suckless.org/patches/moveplace/), they get to keep their
original size. There's also an option to center a window.

This patch modifies the `config.def.h` file, be sure to copy your preferred bindings
to `config.h`.

Download
--------
* [dwm-movethrow-6.2.diff](dwm-movethrow-6.2.diff)

Authors
-------
* Randoragon `<`randoragongamedev@gmail.com`>`
* cd (original moveplace)
