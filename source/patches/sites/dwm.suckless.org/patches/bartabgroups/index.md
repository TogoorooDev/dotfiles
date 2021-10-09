# bartabgroups

This patch turns the titlebar area into a mfact-respecting tabbar showing each
client's title. In tiling mode, the tabs are split into two groups (based on
nmaster) at the mfact location. This maybe reminiscent of i3's tabbed layout
or using the multiple instance of the tabbed program with the caveat that
this patch reserves left and right hand space in the bar for dwm's tags and
status area respectivly (so ideally minimize the amount of space you use for
each). When you are not in tiling mode (float/monocole), a single tab bar just
occupies the entire horizontal space available. Custom layouts are assumed
to respect mfact and be similar to the tiling mode (and this works well
with the deck patch for example), but if you need to add an exception
refer to the provided config.def.h.

Clicking on each tab in the bar will focus that window.

This patch also incorporates a few optional niceties configurable in your
config.h such as drawing a 1px border between tabs, adding an indicator to show
which tags each client is on, and an option to add a bottom border to the bar.

## Screenshot
Bartabgroups patch shown used in conjunction with the [taggrid](/patches/taggrid)
and gaps patches in tile mode:
![screenshot](dwm-bartabgroups.png)

## Download
* [dwm-bartabgroups-6.2.diff](dwm-bartabgroups-6.2.diff) (01/25/2020)
* [dwm-bartabgroups-20210802-138b405.diff](dwm-bartabgroups-20210802-138b405.diff) (02/08/2021)

## Author
- Miles Alan (m@milesalan.com)
- Jack Bird (jack.bird@dur.ac.uk) (138b405 port)
