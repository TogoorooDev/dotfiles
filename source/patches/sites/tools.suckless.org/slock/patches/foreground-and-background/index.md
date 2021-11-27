Foreground or Background
========================

Description
-----------
This patch combines the features of blur-pixelated-screen and dwmlogo; it changes the background of slock to a blurred or pixelated version of your current desktop and the foreground of slock to a dwm logo that changes color based on the state.

Notes
-----
The size of the logo is configurable with `logosize` in the `config.h`.

This patch is not limited by the dwm logo.
By changing the `rectangles` variable in `config.h` you can create any figure based on rectangles.

Define either `BLUR` (default) or `PIXELATION` to set which type of masking you want applied to the screen. You can also change the blur radius and pixel size with `blurRadius` and `pixelSize`, respectively.

With the `dpms` patch there is a conflict in the `main` function. 
This is easly fixed by editing the `main` function in `slock.c`
so it looks like this, for it to work properly:

    main(int argc, char **argv){
        ...
            XFreeGC(dpy, locks[s]->gc);
        }

        /* reset DPMS values to inital ones */
        DPMSSetTimeouts(dpy, standby, suspend, off);
        XSync(dpy, 0);
        XCloseDisplay(dpy);
    
        return 0;
    }

Download
--------
* [slock-foreground-and-background-20210611-35633d4.diff](slock-foreground-and-background-20210611-35633d4.diff)

Authors
-------
* KNIX 3 - <nki3@protonmail.com>
* Arie Boven - <ar.boven@protonmail.com>
* Lars Niesen - <lars.niesen@gmx.de>
