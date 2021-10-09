Mediakeys
=========

Description
-----------
This patch allows using the following keys to be used while the screen is
locked:

- XF86AudioPlay
- XF86AudioStop
- XF86AudioPrev
- XF86AudioNext
- XF86AudioRaiseVolume
- XF86AudioLowerVolume
- XF86AudioMute
- XF86AudioMicMute
- XF86MonBrightnessDown
- XF86MonBrightnessUp

I don't want to unlock the screen just in order to skip the current song or
raise the volume, mute, etc that's all there is to it.

NOTE: If you are using dwm for key bindings, in your `dwm.c` file, go to the
`setup` function to the line with `wa.event_mask =` and add `|KeyPressMask`

```c
	wa.event_mask = SubstructureRedirectMask|SubstructureNotifyMask
		|ButtonPressMask|PointerMotionMask|EnterWindowMask
		|LeaveWindowMask|StructureNotifyMask|PropertyChangeMask|KeyPressMask;
```


Download
--------
* [slock-1.4](https://patch-diff.githubusercontent.com/raw/phenax/bslock/pull/1.diff)
* [slock-mediakeys-20170111-2d2a21a.diff](slock-mediakeys-20170111-2d2a21a.diff)


Authors
-------
* Klemens Nanni <kl3@posteo.org>
* Akshay Nair <akshay-n0@protonmail.com> (1.4 version)

