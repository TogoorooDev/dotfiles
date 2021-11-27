Dwm logo
========

Description
-----------
Instead of using the colors for the whole screen based on the state,
this patch draws the dwm logo which changes color based on the state.

Notes
-----
The size of the logo is configurable with `logosize` in the `config.h`.

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

Customization
-------------
This patch is not limited by the dwm logo.
By changing the `rectangles` variable in `config.h` you can create any figure based on rectangles.

Download
--------
* [slock-dwmlogo-20210324.diff](slock-dwmlogo-20210324.diff)

Authors
-------
* Arie Boven - <ar.boven@protonmail.com>
