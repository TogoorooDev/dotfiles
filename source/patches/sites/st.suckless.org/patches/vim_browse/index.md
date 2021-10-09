Vim Browse
==========
The vim-browse patch offers the possibility to move through the terminal history-buffer, search for strings using VIM-like motions, operations and quantifiers. It overlays the screen with highlighted search results and displays the current operation / motions / search string in the bottom right corner. The patch operates on top of the [history-patch](https://github.com/juliusHuelsmann/st-history-vim), which comes with a set of optional features that can be compiled-in as separate patches. Please [leave a star](https://github.com/juliusHuelsmann/st-history-vim).

Contributions & Bug Reports
---------------------------
* [Report / Solve Patching issues](https://github.com/juliusHuelsmann/st) with a new version of `st`
* [Contributions and Bug reports](https://github.com/juliusHuelsmann/st-history-vim)


Default Behavior:
-----------------
A more detailed overview on the commands can be found [here](https://github.com/juliusHuelsmann/st-history-vim/wiki/Vim-browse-manual) and in the file `normalMode.c`.

**Enter / Leave different modes**:

- `Alt`+`c`: Enter normal mode
- `[esc]`/`[enter]`/`i`: Enter insert mode or abort current operation / motion

**Operations:**

- `y`/`v`/`V`: enter `yank` / `visual` / `visual line` mode.

**Motions:**

- `k`, `j`, `h`, `l`, `H`, `M`, `L`, `0`, `$`, `n`, `N`, `w`, `W`, `b`, `B`, `e`, `E`, `Ctrl u`,
  `Ctrl d`, `Ctrl b`, `Ctrl f`, `y`, `?`, `/` like in Vim
- `.` re-execute last command (which is shown in the overlay)
- Infixes `i`, `a`: like in Vim, in conjunction with an operation and motion or pre-defined search char `(){}[]<>"'` (`yiw`, `vi[`, ...)
- `[0-9]` Quantifiers
- `[backspace]` erase last quantifier / letter in search and command string
- `r` manual repaint
- `K`, `J` Scroll buffer up / down
- `s`, `S` toggle [once] `MODE_ALTSCREEN`
- `G`, `g` move the history cursor to the current insert position / offset
- `t` toggle rectangle / normal selection mode
- `Ctrl h` hide overlay
- Custom commands can be defined in the configuration files (see `nmKeys`)

Patching and customization
--------------------------
The VIM patch performs changes in the `config.def.h` file, which need to be manually merged into a pre-existing custom `config.h` file. The following variables can be adapted from the defaults defined in `config.def.h`:
- `buffSize`: Size of the buffer history in lines
- `highlightBg` `highlightFg`: Background / Foreground color of search results
- `currentBg`: Background color used in order to highlight the current history cursor via a cross
- `nmKeys`: custom commands (= sequence of operations/motion), the first character is the key to be used in order to execute the sequence of operations / motions.
- `styleSearch` style of the search string overlay
- `style` styles of the command string overlay depending on the currently active operation ([`yank`, `visual`, `visualLine`, `no operation`]).

Download
--------
If you want to try out the current version of the patch before patching your own build, check out [this repository](https://github.com/juliusHuelsmann/st), which contains a merged version of this patch with a reasonable configuration.

Based on a [custom history patch](https://github.com/juliusHuelsmann/st-history-vim), which is already applied in the patches below with full set of `history` features.  A more minimal version of the vim patch can be generated from the [st-history repository](https://github.com/juliusHuelsmann/st-history-vim).
- *Based on `st-0.8.4`*:
- [Version 2.2 (latest)](https://github.com/juliusHuelsmann/st/releases/download/vim2_2/st-meta-vim-full-20210425-43a395a-8.4.patch)
- [Version 2](st-vim-0.8.4.patch)
- *Based on `st-0.8.3`*:
- [Version 2.2 (latest)](https://github.com/juliusHuelsmann/st/releases/download/vim2_2/st-meta-vim-full-20210425-43a395a.diff)
- [Version 2](st-vim-0.8.3.patch)

Authors of the Vim-Browse Patch
--------------------------------
* [Julius Hülsmann](https://github.com/juliusHuelsmann) - <juliusHuelsmann [at] gmail [dot] com>
* [Kevin Velghe](https://github.com/paretje): Fix: Underline highlight
* [dadaurs](mailto:david.wiedemann@outlook.com): Port Version 1 to `st-295a43f`
* [smartding](https://github.com/smartding): detect and fix clipboard bug

