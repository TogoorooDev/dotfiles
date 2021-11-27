Multi-monitor setup
===================
If configured to use Xinerama libraries in `config.mk`, dwm can automatically
detect configured screen outputs (monitor, overhead projector, etc.) and their
resolutions and draw the windows in the output area accordingly.

Configuring monitors
--------------------
One of the easiest ways to configure screen outputs is via the *RandR* X server
extension using the `xrandr` tool. Without arguments it will list the current
configuration of screen outputs.

	xrandr

For each connected output the supported resolution modes will be printed.

Mirroring two outputs
---------------------
dwm will assume that two outputs should display identical windows and tags if:

* one of them is configured to display in the same area as the other
  (`--same-as` switch)
* they have the same resolution

After connecting a monitor, this could be an example of a mirroring setup

	xrandr --output VGA1 --auto --same-as LVDS1 --mode 1024x768
	xrandr --output LVDS1 --mode 1024x768

The `--auto` switch enables the output after it was connected.

Two independent outputs
-----------------------
If two screen outputs have different resolutions, dwm assumes that they should
display different windows and tag sets. It may therefore be necessary to
instruct the X server via the `xrandr` tool to draw the outputs in different
areas of the screen, as it may default to `--same-as` and the areas would
overlap.

After connecting a monitor, this could be an example of such a setup

	xrandr --output VGA1 --auto --right-of LVDS1

In this case the `--auto` switch enables the output after connecting and also
sets its preferred resolution mode.
