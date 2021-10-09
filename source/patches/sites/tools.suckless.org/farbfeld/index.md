![farbfeld](farbfeld.svg)

farbfeld is a lossless image format which is easy to parse, pipe and compress.
It has the following format:

	╔════════╤═════════════════════════════════════════════════════════╗
	║ Bytes  │ Description                                             ║
	╠════════╪═════════════════════════════════════════════════════════╣
	║ 8      │ "farbfeld" magic value                                  ║
	╟────────┼─────────────────────────────────────────────────────────╢
	║ 4      │ 32-Bit BE unsigned integer (width)                      ║
	╟────────┼─────────────────────────────────────────────────────────╢
	║ 4      │ 32-Bit BE unsigned integer (height)                     ║
	╟────────┼─────────────────────────────────────────────────────────╢
	║ [2222] │ 4x16-Bit BE unsigned integers [RGBA] / pixel, row-major ║
	╚════════╧═════════════════════════════════════════════════════════╝

The RGB-data should be sRGB for best interoperability and not
alpha-premultiplied.

Dependencies
------------
* [libpng](http://www.libpng.org/pub/png/libpng.html) - for png conversions
* [libjpeg-turbo](http://libjpeg-turbo.virtualgl.org/) - for jpg conversions

Development
-----------
You can [browse](//git.suckless.org/farbfeld) its source code repository or get
a copy using the following command:

	git clone https://git.suckless.org/farbfeld

Download
--------
* [farbfeld-1](//dl.suckless.org/farbfeld/farbfeld-1.tar.gz) (2016-01-06)
* [farbfeld-2](//dl.suckless.org/farbfeld/farbfeld-2.tar.gz) (2016-03-14)
* [farbfeld-3](//dl.suckless.org/farbfeld/farbfeld-3.tar.gz) (2017-04-14)
* [farbfeld-4](//dl.suckless.org/farbfeld/farbfeld-4.tar.gz) (2018-04-11)

Also make sure to check your package manager. The following distributions
provide packages:

* [Alpine Linux](https://pkgs.alpinelinux.org/package/edge/community/x86_64/farbfeld)
* [Arch Linux (AUR)](https://aur.archlinux.org/packages/farbfeld)
* [Debian](https://packages.debian.org/farbfeld)
* [FreeBSD](https://svnweb.freebsd.org/ports/head/graphics/farbfeld/)
* [Gentoo](https://packages.gentoo.org/packages/media-gfx/farbfeld)
* [NixOS](https://github.com/NixOS/nixpkgs/tree/master/pkgs/development/libraries/farbfeld)
* [OpenBSD](http://ports.su/graphics/farbfeld)
* [Ubuntu](https://packages.ubuntu.com/farbfeld)
* [Void Linux](https://github.com/void-linux/void-packages/tree/master/srcpkgs/farbfeld)

Implementations
---------------
* [image](https://crates.io/crates/image) Rust crate for image processing
* [imlib2](https://sourceforge.net/projects/enlightenment/files/imlib2-src/) library (implies support in feh,
  w3m, giblib, sxiv, conky, magicpoint, scrot, libcaca, etc.)
* [lel](https://git.codemadness.org/lel/) farbfeld image viewer
* [sent](//tools.suckless.org/sent/) presentation tool
* [ff-tools](https://github.com/sirjofri/ff-tools) image filter/generator collection
* [ffmk](https://github.com/sirjofri/ffmk) makefile-based farbfeld mixer
* [Go encoder/decoder](https://github.com/hullerob/go.farbfeld)
* [resize](https://github.com/ender672/farbfeld-resize) image filter
* [gamut](https://github.com/erik/gamut) image filter collection
* [gimp-farbfeld](https://github.com/ids1024/gimp-farbfeld) gimp plug-in
* [farbfeld utilities](http://zzo38computer.org/fossil/farbfeld.ui/) huge collection of image filters
* [ff2sixel](https://gitlab.com/link2xt/ff2sixel) farbfeld image viewer for SIXEL terminals
* [xscreenshot](https://git.codemadness.org/xscreenshot/file/README.html) screen capture tool


Author
------
* Laslo Hunhold (dev@frign.de)

Please contact me when you find information that could be added to this page.
