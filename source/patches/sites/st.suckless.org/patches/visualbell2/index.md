# Visual bell 2

Description
-----------
Briefly renders a configurable visual indication on terminal bell event.

Two variants are available:

### The basic variant supports:
* Invert the whole screen, or the border cells, or (only in 2020-05-13) the
  bottom-right corner or any custom group of cells.
* Configurable duration (default: 150ms).

### The enhanced variant supports in addition:
Rendeding a configurable circle:
* Position: any corner/edge, center of the screen, or anything in between.
* Size: relative to the window width or to the cell width.
* Colors: inner and outline.

Notes
-----
* All files are git patches and can be applied with either `git am` or `patch`.
* Configuration is done at `config.h`.

Download
--------
After st 0.8.3 (the enhanced patch needs the basic patch applied first):
* [st-visualbell2-basic-2020-05-13-045a0fa.diff](st-visualbell2-basic-2020-05-13-045a0fa.diff)
* [st-visualbell2-enhanced-2020-05-13-045a0fa.diff](st-visualbell2-enhanced-2020-05-13-045a0fa.diff)

st 0.8.3 or earlier (the enhanced patch also includes basic in the same file):
* [st-visualbell2-basic-2018-10-16-30ec9a3.diff](st-visualbell2-basic-2018-10-16-30ec9a3.diff)
* [st-visualbell2-enhanced-2018-10-16-30ec9a3.diff](st-visualbell2-enhanced-2018-10-16-30ec9a3.diff)

Author
------
* Avi Halachmi (:avih) - [https://github.com/avih](https://github.com/avih)

