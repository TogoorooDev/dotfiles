# river

River is a dynamic tiling Wayland compositor with flexible runtime
configuration.

Join us at [#river](https://web.libera.chat/?channels=#river)
on irc.libera.chat. Read our man pages and our
[wiki](https://github.com/riverwm/river/wiki).

*Note: river is currently early in development. Expect breaking changes
and missing features. If you run into a bug don't hesitate to
[open an issue](https://github.com/riverwm/river/issues/new)*

## Design goals

- Simple and predictable behavior, river should be easy to use and have a
low cognitive load.
- Window management based on a stack of views and tags.
- Dynamic layouts generated by external, user-written executables. A default
`rivertile` layout generator is provided.
- Scriptable configuration and control through a custom Wayland protocol and
separate `riverctl` binary implementing it.

## Building

<a href="https://repology.org/project/river/versions">
    <img src="https://repology.org/badge/vertical-allrepos/river.svg" alt="Packaging status" align="right">
</a>

On cloning the repository, you must init and update the submodules as well
with e.g.

```
git submodule update --init
```

To compile river first ensure that you have the following dependencies
installed:

- [zig](https://ziglang.org/download/) 0.8.0
- wayland
- wayland-protocols
- [wlroots](https://github.com/swaywm/wlroots) 0.14.0
- xkbcommon
- libevdev
- pixman
- pkg-config
- scdoc (optional, but required for man page generation)

Then run, for example:
```
zig build -Drelease-safe --prefix ~/.local install
```
To enable experimental Xwayland support pass the `-Dxwayland` option as well.

## Usage

River can either be run nested in an X11/Wayland session or directly
from a tty using KMS/DRM. Simply run the `river` command.

On startup river will run an executable file at `$XDG_CONFIG_HOME/river/init`
if such an executable exists. If `$XDG_CONFIG_HOME` is not set,
`~/.config/river/init` will be used instead.

Usually this executable is a shell script invoking *riverctl*(1) to create
mappings, start programs such as a layout generator or status bar, and
preform other configuration.

An example init script with sane defaults is provided [here](example/init)
in the example directory.

For complete documentation see the `river(1)`, `riverctl(1)`, and
`rivertile(1)` man pages.

## Licensing

river is released under the GNU General Public License version 3, or (at your
option) any later version.

The protocols in the `protocol` directory are released under various licenses by
various parties. You should refer to the copyright block of each protocol for
the licensing information. The protocols prefixed with `river` and developed by
this project are released under the ISC license (as stated in their copyright
blocks).