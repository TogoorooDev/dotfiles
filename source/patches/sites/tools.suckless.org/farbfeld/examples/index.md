Examples
========
Convert image.png to a farbfeld, run it through a filter and write the result
to image-filtered.png:

        $ png2ff < image.png | filter | ff2png > image-filtered.png

[invert.c](invert.c) is an example for such a filter which inverts the colors.
Notice that there are no dependencies on external libraries. A hypothetical
farbfeld-library would hardly exceed invert.c's size.

Store a png as a compressed farbfeld:

        $ png2ff < image.png | bzip2 > image.ff.bz2

Access a compressed farbfeld as a png:

        $ bunzip2 < image.ff.bz2 | ff2png {> image.png, | feh -, ...}

Handle arbitrary image data using 2ff(1), which falls back to imagemagick's
convert(1) for unknown image types:

        $ 2ff < image | filter | ff2png > image-filtered.png

Refer to the manpages for more information. farbfeld(5) is a good start.
