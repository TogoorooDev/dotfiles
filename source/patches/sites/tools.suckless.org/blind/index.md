![blind](blind.svg)

blind is a collection of command line video editing utilities.

Video format
------------
blind uses a raw video format with a simple container. A file begins with an
plain-text line, containing the number of frames, the width, the height, and
the pixel format, all separated by a single regular blank space, without and
leading or tailing white space. After this line, which ends with an LF, there
is a NUL-byte followed by the 4 characters “uivf” (unportable, interim
video format). This head is followed by the video frame-by-frame with row-major
frames. Pixels are independently encoded, and are encoded unscaled CIE XYZ with
non-premultiplied alpha and without any transfer-function, with values stored
in native `double`s or optionally in native `float`s. These two configurations
are the only options, but the container format is designed so this can be
changed arbitrarily in the future.

FAQ
---

### Creating videos without graphics, are you insane?

Yes, but see the rationale below!

### Doesn't raw video takes up a lot of space?

Yes it does, a 4-channel pixel encoded with `double` takes 32 bytes. A
1280-by-720 frame with this pixel format takes 29.4912 MB (SI), which means you
can only fit almost 3391 frames in 100 GB, which is about 113 seconds or 1:53
minutes with a framerate of 30 fps. Therefore, you probably do not want to
store anything in this format unless you know you have room for it, or if it is
very small segment of your video, which unfortunately becomes a bit of a problem
when reversing a video. However, when possible, feed the resulting video
directly to `blind-to-video` to convert it into a compressed, lossless video
format, if the video is not too large, you can choose to compress it with bzip2
instead.

### For what kind of video editing is blind designed?

It is designed for composing new videos. It is not designed for making small
changes as this can probably be done faster with a graphical video editor or
with ffmpeg which would also be much faster.

### Does it support farbfeld?

Of course. If you want to use farbfeld, you can use the `-f` flag for
`blind-to-image` and `blind-from-image`, this will cause the programs to
convert directly to or from farbfeld without using `convert(1)`.

### Why doesn't blind uses encode pixels like farbfeld?

blind and farbfeld solve completely different problems. farbfeld solves to
problem of storing pictures in a simply way that can easily be viewed and
edited. blind does not try to solve the problem of storing videos, video
takes a lot of space and need compression designed especially for video or
three-dimensional raster images. Compressed video cannot be efficiently edited
because compression takes too long. Instead blind solves the problem of
efficiently processing video: thousands of pictures. Because blind doesn't try
to create a format for storing images, therefore it's format doesn't need to be
portable. Furthermore, due to legacy in television (namely, that of
black-and-white television), video formats do not store values in sRGB, but
rather in Y'UV, so there is next to no benefit to storing colours in sRGB.

### Why doesn't blind use sRGB?

If I tell you I use CIE XYZ, you will only have two questions: “how are
values stored?” and “is Y scaled to [0, 100] or [0, 1]?” When I tell you
I use sRGB you have more questions: “do you support out-of-gamut colours?”,
“how are values stored?”, “which scale do you use?”, and “is the
transfer-function applied?”

CIE XYZ also has the advantage of having the brightness encoded in one of its
parameters, Y, and obtaining the chroma requires only simply conversion to a
non-standardise colour model that with the same Y-value.

### Why does blind use CIE XYZ instead of CIE L\*a\*b\*?

Because CIE L\*a\*b\* is not linear, meaning that it requires unnecessary
calculations when working with the colours.

### Why does blind use CIE XYZ instead of Y'UV or YUV?

Y'UV has good performance for converting to sRGB and is has good subsampling
quality, but it is not a good for editing. Y'UV is non-linear, so it has the
same disadvantages as CIE L\*a\*b\*. Y'UV does not have its transfer-function
applied directly to it's parameters, instead it is a linear transformation if
the sRGB with its transfer-function applied. This means that no performance is
gained during conversion to or from cooked video formats by using YUV. CIE XYZ
also has the advantage that it is well-known and has a one-step conversion to
almost all colour models. It also have the advantages that it's parameters are
named X, Y, Z, which makes it very easy to choose parameter when storing points
instead of colours in a video.

### Doesn't blind have any audio support?

No, it is not clear that there is actually a need for this. There are good
tools for editing audio, and ffmpeg can be used be used to extract the audio
streams from a video or add it to a video.

### Is it really feasible to edit video without a GUI?

Depends on what you are doing. Many things can be done without a GUI, and
some thing are easier to do without one. If you find that you need GUI it
possible to combine blind with a graphical editor. Furthermore, blind could be
used in by a graphical editor if one were to write a graphical editor to use
blind.

Rationale
---------
* It's source control friendly and it's easy for a user to resolve merge
  conflicts and identify changes.
* Rendering can take a very long time. With this approach, the user can use
  Make to only rerender parts that have been changed.
* It's possible to distribute the rendering to multiple computers, without any
  built in functionality for this, for example using a distributed Make.
* Parallelism is added for free.
* No room for buggy GUIs, which currently is a problem with the large video
  editors for Linux.
* Less chance that the user makes a change by mistake without noticing it, such
  as moving a clip in the editor by mistake instead of for example resizing.
* Even old, crappy computers can be used for large projects.
* Very easy to utilise command line image editors for modify frames, or to add
  your own tools for custom effects.

Development
-----------
You can browse its [source code repository](//git.suckless.org/blind) or get a
copy using git with the following command:

	git clone https://git.suckless.org/blind

Download
--------
* [blind-1.0](//dl.suckless.org/tools/blind-1.0.tar.gz) (2017-01-22)
* [blind-1.1](//dl.suckless.org/tools/blind-1.1.tar.gz) (2017-05-06)

Also make sure to check your package manager.  The following distributions
provide packages:

* [Alpine Linux](https://pkgs.alpinelinux.org/package/edge/testing/x86_64/blind)
* [Arch Linux (AUR)](https://aur.archlinux.org/packages/blind/)
* [Arch Linux (AUR), git version](https://aur.archlinux.org/packages/blind-git/)

Dependencies
------------
* [ffmpeg](https://www.ffmpeg.org/) - for converting from or to other video
  formats.
* [imagemagick](https://www.imagemagick.org/) - for converting regular images
  to frames.

Links
-----
* [Video tutorials](https://www.youtube.com/channel/UCg_nJOURt3guLtp4dQLIvQw)


Author
------
* Mattias Andrée (maandree@kth.se)
