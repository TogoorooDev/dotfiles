Kris Maglione aka JG
====================

I'm the maintainer of wmii.

This is a place for me to post the random scripts that I'm compelled to write and consider useful.

Scripts
-------
*Note:* I've updated most of these, and haven't posted the updates... I'll get around to it eventually.

All of these scripts are written in rc, and require plan9port to run.

* webpaste - A script which reads its standard input or the files
    on its command line and prints a URI where the data can be retrieved. Requires: curl.

* pasteweb - Similar to webpaste, but reads the contents of your
   clipboard and replaces them with a URI where the contents can be retrieved.
   Requires: curl, and one of xclip, xsel, or sselp (in which case, it will print the URI)

* plastfm - An rc script which connects to Last.FM and plays its stream with
   a command-line mp3 player. Commands are read from the standard input and song info is
   printed to the standard error. Requires: mpg123 or similar client. *This has been replaced
   by "last".*

* eris.rc - This is an IRC bot, written in rc, of course, which prints mercurial
   commits to channels. The name comes from George Neis' python version. Requires: sic or similar.

* hgnotify.rc - This is an mailing list bot which posts mercurial commits
   along with their diffs to a mailing list, or arbitrary mailing address. The sender, subject,
   and date all reflect those of the commit. Requires: A sendmail compatible MTA.

* logger.rc - A simple IRC logger bot, which uses the httplog logger to handle
   log rotation. It also extracts lines beginning with 'BUG' and writes them to a separate file.
   Requires: httplog, sic.


`wmii` Scripts
==============
These are just some of the random wmii scripts I've written.
I find them immensely useful, and they serve as good examples.
Most use the `wmii.rc` script which I've written to make
`rc.wmii` more straightforward, and plugins easier. But, I haven't
released it yet, so bear with me.

`rc.keymap`
-----------
A simple keymap-changer applet. It doesn't know any keyboard
shortcuts for the moment.

    #!/bin/rc
    . 9.rc
    . wmii.rc keymap

    # Begin Configuration
    bar=s7~1keymap
    choices=(us dvorak)
    # End Configuration

    keymap=$choices(1)

    fn setkeymap {
        if(! ~ $"* '') {
            keymap=$"*
            setxkbmap $keymap
            echo km:$"keymap | wmiir create /rbar/$bar
        }
    }

    setkeymap $keymap

    fn Event-RightBarMouseDown {
        if(! $1 1 && ~ $2 $bar)
            setkeymap `{wi_9menu -initial $keymap $choices}
    }

    wi_eventloop

`rc.vol`
--------
Adjust the volume with Alt-Plus/Alt-Minus (should use `$MODKEY`...).
My first bar just happens to be named `agabaga`, because I picked
a random word which started with a ages ago, and the name stuck.

    #!/bin/rc
    . 9.rc
    . wmii.rc

    # Begin Configuration
    numbars = 20
    mixer = pcm
    bar = agabaga
    delay = 2
    # End Configuration

    fn mset {
        var=$1; shift
        eval $var' = `{hoc -e $"*}'
    }

    mset div 100 / $numbars

    fn readvol { mixer $* | awk -F'[ :]+' '{print $7}' | head }

    xpid = ()

    fn changevol {
        diff = $1; shift
        cur = `{readvol $mixer}
        mset new $cur + '(' $diff ')'

        mixer $mixer $new >/dev/null

        awk -vnew'='$new -vdiv'='$div -vn'='$numbars \
            'BEGIN{ s=sprintf("% *s", new/div, "|");
                gsub(/ /, "-", s);
                printf "[% -*s] %d%%", n, s, new;
                exit }' |
            wmiir write /rbar/$bar

        /bin/kill $xpid >[2]/dev/null # Let's hope this isn't reused...
        { sleep $delay; wmiir xwrite /rbar/$bar ' ' }& # Bug...
        xpid = $apid
    }

    fn Key-Mod1-^(KP_Add Shift-plus) {
        changevol $div
    }

    fn Key-Mod1-^(KP_Subtract Shift-minus) {
        changevol -$div
    }

    wi_eventloop

`rc.mail`
---------
A mail monitor. I've posted it elsewhere. It reads the names of
windows on the mail tag and checks for mail in Maildirs with
corresponding names. It treats `inbox` specially. This is posted
elsewhere.

    #!/bin/rc
    . 9.rc

    # Configuration
    #How often to check
    delay=5
    maildir=$home/Maildir
    # End Configuration

    echo Start mail | wmiir write /event

    {   wmiir read /event &
        while(echo Tick)
            sleep $delay
    } | while(*=`{read}) 
        switch($1) {
        case Start
            if(~ $2 mail)
                exit
        case Tick
            wmiir read /tag/mail/index |
            while(l = `{read}) {
                b = `{echo $l | awk -F: '{print $3}'}
                if(~ $b inbox)
                    b = ''
                if(! ~ $#b 0 && test -d $maildir/.$b/new) {
                    if(~ `{ls -l $maildir/.$b/new | wc -l} 0)
                        wmiir xwrite /client/$l(2)^/ctl Urgent off
                    if not
                        wmiir xwrite /client/$l(2)^/ctl Urgent on
                }
            }
        }

`rc.status`
-----------
My date/time/load average bar. Straightforward.

    #!/bin/rc
    . 9.rc
    . wmii.rc rc.status
    # periodically print date and load average to the bar

    fn date { /bin/date $* }

    bar_load=s5load
    bar_date=s9date
    bar_time=time
    bars=($bar_date $bar_load)

    fn sigterm sigint {
        for(i in ($bars $bar_time))
            wmiir remove /rbar/$i >[2]/dev/null
        exit
    }

    for(i in $bars $bar_time)
        wmiir remove /rbar/$i >[2]/dev/null

    sleep 2
    for(i in $bars)
        echo -n $wmiinormcol | wmiir create /rbar/$i
    echo -n $wmiifocuscol | wmiir create /rbar/$bar_time

    {
        while (wmiir xwrite /rbar/$bar_time `{date +'%H:%M:%S %Z'}
            && wmiir xwrite /rbar/$bar_date  `{date +'%a, %e %b'}
            && wmiir xwrite /rbar/$bar_load `{uptime | sed 's/.*://; s/,//g'})
            sleep 1
    } >[2]/dev/null

`rc.temp`
---------
A temperature monitor for the bar. It has Fahrenheit along with
Celsius, because I'm stuck using both (tell someone in the US that
it's -3°C outside and expect little more than a blank stare).

This one uses weatherget. It's in ports... I don't know where else
to find it.

    #!/bin/rc
    . 9.rc

    # Begin Configuration
    zip=12345 # For those outside the us, this needn't be a zip code.
    bar=/rbar/s7temp
    pidf=$home/.wmii-3.5/pid.temp

    deg=°
    # End Configuration

    /usr/bin/kill `{cat $pidf} >[2]/dev/null
    echo $pid >$pidf

    wmiir create $bar </dev/null

    while() {
        {weatherget -s $zip -m; weatherget -s $zip -S} |
            awk '$1=="Temperature"{print $3"'$deg'"$4}' |
            tr '\012' ' ' |
            wmiir create $bar ||
            exit
        sleep 600
    }

