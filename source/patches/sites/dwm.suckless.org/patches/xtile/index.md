xtile
=====

Description
-----------
This patch implements a generalization of the tile layout which adds two
attributes (direction and fact) to three areas (global, master, stack). The
global area is the entire allocatable visual space and it's subdivided into the
master and stack subareas.

The direction of the global area controls the position of the master area
relatively to the stack area and it can be one of `DirHor` (traditional right
stack), `DirVer` (bottom stack), `DirRotHor` (left stack) and `DirRotVer` (top
stack). The direction of the master and of the stack areas are independently
set and can be one of `DirHor` and `DirVer`. This combines to a total of
4\*2\*2=16 layouts.

The fact numbers indicate the relative size of the first subarea/client along
the direction of the considered area (i.e. width for `DirHor` and `DirRotHor`
and height for `DirVer` and `DirRotVer`). A fact of 1 means that the first
subarea/client is on par the rest, while a fact of 2 means that its size must
double the size of each of the remaining subareas/clients, etc. So the fact for
the global area is similar to the traditional mfact in the sense that it
manages the relative allocation of visual space between the master and stack
subareas, while the fact for the master area stands for the relative importance
of the first master client against the rest of masters and, similarly, the fact
for the stack area stands for the importance of the first slave client in
relation to the rest of slaves.

xtile adds two new commands to dwm: `setdir` and `setfact` (which supersedes
`setmfact`). Both commands take an array of three values (of type `int` for
`setdir` and `float` for `setfact`), one value for each area (the first one for
the global area, the second one for the master area and the third one for the
stack area). If you pass the value `v` as `INC(v)` it will be taken as a
relative increment to be added to the current value, otherwise it will be taken
as an absolute value. Usually the resulting value will be truncated to the
valid range of values for each area/attribute combination, but relative
increments for directions wrap around the limits of the valid range. Notice
that INC(0) means "do nothing here", so it gives you a way to easily modify the
value for some area while leaving the rest untouched.

Default key bindings
--------------------
The areas are selected by modifiers as follows:

	 Modifier                Area
	--------------------------------------------------------
	 MODKEY                  Global
	 MODKEY+Shift            Master
	 MODKEY+Control          Stack
	 MODKEY+Shift+Control    All three areas simultaneously

Each of the modifiers then combines with each of the following keys up to a
total of 4\*3=12 key bindings:

	 Key   Function
	------------------------------
	  r    Rotate direction
	  h    Decrement fact by 10%.
	  l    Increment fact by 10%.

There are two provided default "presets" or "schemas" also:

	 Modifier          Key   Preset
	--------------------------------------:
	 MODKEY+Shift       t    Right stack
	 MODKEY+Control     t    Bottom stack

These presets allow to quickly switch between different no-nonsense tilings
avoiding the need to rotate through all the nonsense combinations in-between.
But notice that `MODKEY+Shift+Control+r` (i.e. simultaneously rotate all three
areas) usually produces sensible layouts (due to the way directions were
designed to rotate).

You can also easily define your own presets by calling `setdir` and `setfact`
as needed. For example, here is the configuration code for the default presets
described above:

	{ MODKEY|ShiftMask,   XK_t, setdirs, {.v = (int[]){ DirHor, DirVer, DirVer } } },
	{ MODKEY|ControlMask, XK_t, setdirs, {.v = (int[]){ DirVer, DirHor, DirHor } } },

Layout symbol
-------------

The layout symbol will probably look cryptic at first sight but it's very
easily decoded. It consists of three characters, one for the direction of each
area:

* Global area: '<', '>', 'v', '^', just think of it as an arrow that points in the
  direction of the master area.
* Master area: '|' for vertically tiled masters and '-' for horizontally tiled masters.
* Stack area: same as for the master area.

For example, '<||' stands for the default right stack tile provided by dwm and
'^--' stands for bstack (as defined by the bottom stack patch).

Digressions
-----------

### Why facts per area?

There is some arbitrariness in the way facts are defined by xtile: why facts
for the first master and the first slave and not, say, for the first two
clients instead? Considering that most real life layouts will have one or two
masters and a variable number of slaves, the road xtile took will enable the
user to effectively control the relative size of the three/four most important
clients in a very intuitive way that built on his previous understanding of the
mfact and the master and stack area concepts. OTOH it's not clear to me how to
allow the specification of facts for the first two clients in an intuitive way:

* If there is only one master this alternative approach is equivalent to
  xtile's one.
* If there are two masters, only one fact will be required to specify the share
  of the master area that belongs to each one, so what to do with the second
  fact?
* If this second fact is taken as the share of the second master vs the share
  of the rest (the slaves), it's not clear how to define these inter-area shares.

### Why not deck area?

One obvious additional generalization would have been to extrapolate the
nmaster idea to all three areas, or at least to the stack area. So if you
allowed only m masters and n slaves you would end up with m+n tiled windows and
with the rest of the clients in the current tagset stacked or decked "below"
the last tiled client. flextile, clients-per-tag and deck patches provide
variations on this kind of layout. I've also implemented a version of xtile
that supports it and even subsumes monocle, but I think this promotes a bad
pattern of usage. Coupled with stack manipulation operations as the ones
provided by the stacker or push patches, there is the temptation to manage
visibility by moving the desired clients in the current tagset to the first n+m
visible positions of the focus stack (not to be confused with the stack area).
There are a number of problems with this approach:

* The stack is global to dwm, so pushing around clients in one tag will
  rearrange them in other tags also. This could become a problem if you rely too
  much on explicit stack management.

* The deck area badly violates the principle of least surprise. If you only
  change focus sequentially by using `mod-j`/`mod-k` there is no way to exit the
  deck at a client different to the last/first decked one. If you use the mouse
  or the `focusstack` command provided by the stacker patch to jump directly from
  the deck to a non-decked client, each time you reach the deck again by using
  `mod-j`/`mod-k` the visible decked client will be replaced by the first/last
  decked one. In general, there is a devilish interplay of the focus stack and
  the z-stack that makes the deck unusable as a tabbed view of the decked
  clients, at least for more than one or two decked clients.

Fortunately, dwm provides a much better mechanism to restrict visibility: tags.
IMO there is no need to provide a half-assed alternative to one of dwm's
strongest selling points.

Mandatory dependencies:
* [pertag](../pertag/): we all know this one.

Download
--------
* [dwm-xtile-6.2.diff](dwm-xtile-6.2.diff) (11/06/2020)
* [dwm-6.0-xtile.diff](dwm-6.0-xtile.diff)

Recommended complementary patches:
----------------------------------
Gaps
----
Added a new patch with separate inner and outer gaps which can be adjusted  
at runtime. Also includes an option to disable gaps when only one window  
is open (on by default.)

`Mod+Shift+i/o - increase size (i - inner, o - outer)`    
`Mod+Control+i/o - decrease size (i - inner, o - outer)`   
`Mod+Shift+Control+i/o - disable gaps (i - inner, o - outer)`   

Download
--------
* [dwm-xtile-gaps-6.2.diff](dwm-xtile-gaps-6.2.diff) (15/06/2020)
* Visit [gaps](../gaps/) page for older versions.

Stacker
-------
A patch to better accommodate the clients to the more elaborate layouts allowed  
by xtile. But I would add: subject to the caveats that I've expressed above.

Download
--------
* Visit [stacker](../stacker/) page to download. (6.2 version available)

Patches related to xtile:
[bottom stack](../bottomstack/), [flextile](../flextile/), 
[cfacts](../cfacts/), [stackmfact](../stackmfact/).


Authors
-------
* MLquest8 (gaps and update for 6.2) (miskuzius at gmail.com)
* Carlos Pita (memeplex) <carlosjosepita@gmail.com>
