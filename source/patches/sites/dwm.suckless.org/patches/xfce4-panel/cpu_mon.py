#!/usr/bin/python
# coding: utf-8
"""
GENMON APPLET USAGE EXAMPLE

A Custom CPU monitor.

Challenge: We want a bit of history and cpu monitoring anyway needs some delta t.

So we run this as daemon.
It keeps writing cpu infos to file -> start me in autostart.sh

Hightlights:
- cpu per core
- top cpu eating process, customized with own config (not colliding with yours of ~/.config/procps)
- arbitray long symbol lists, will pick per percent
- output colorized using pango

Lowlights:
Linux Only. Not hard to rewrite, but now it's just Linux, looking into /proc/stat
For BSD check the suckless' slstatus regarding how to derive load.

Usage:
Start this tool e.g. in autostart.sh and leave running.
In genmon use `cat $HOME/.dwm/out.cpu_mon` for the single shot tray icon command
"""

import os, sys, psutil, time, subprocess as sp
import time

here = os.path.abspath((os.path.dirname(__file__)))

# ------------------------------------------------------------------------------ config
col_norm = '#a093c7'
col_high = '#bf568b'

# we run top whenever a core if over this:
th_cpu_min_to_snapshot_top = 20
# we show proc names whenever its utilizaition is over this:
th_cpu_min_to_show_procs = 80
# 0: show always (>0: no space taken for core)
th_min_cpu_show_core = 0
show_max_procs = 3
th_color_high_cpu = 80
top_output_max_lines = 20

top_rc_dir = here + '/.config/procps'
top = 'HOME="%s" top -b -1 -n 1 -w 56 | head -n %s' % (here, top_output_max_lines)
Sensors = ['cpu']
# Sensors = ['time']
bars = ' ▁▂▃▄▅▆▇'
# -------------------------------------------------------------------------- end config


# configure the panel item to cat this file:
fn_out = here + '/out.cpu_mon'


# maybe we want arrows stuff some day:
Traffic100 = 1024  # bytes
# arr_downs = ' 🢓↓⬇ﰬ🡇'
arr_downs = ' ↓⬇ﰬ🡇'
arr_ups = ' ↑⬆🡅'

s = []
CPUs = psutil.cpu_count()
# normal way to read load: read /proc/stat
ctx = {'proc_stat': [0 for i in range(CPUs)], 'traffic': [0, 0], 'fifo': None}


bar_intv = 100.0 / len(bars)
arr_downs_intv = 100.0 / len(arr_downs)
arr_ups_intv = 100.0 / len(arr_ups)
arrows = [[arr_downs, arr_downs_intv], [arr_ups, arr_ups_intv]]

# delivers the *cummulated* load values - per cpu.
# A difference of 100 within 1 sec means: fully loaded
proc_stat = '/proc/stat'


run_top = lambda: os.popen(top).read()


def cmd_colmn():
    # cache the position of the COMMAND column, we need it all the time
    n = 'cpu_top_cmd_col'
    c = ctx.get(n)
    if not c:
        t = ctx['cpu_top']
        c = ctx[n] = len(t.split(' COMMAND', 1)[0].rsplit('\n', 1)[1])
    return c


def add_top_cpu_eaters(r, count, cpu):
    """Get the <count> top most cpu eating procs names as shown by top"""
    # TODO: import re would not hurt
    t = ctx['cpu_top']
    p = t.split('COMMAND', 1)[1].split('\n', 1 + count)
    colmn = cmd_colmn()
    for i in range(count, 0, -1):
        if cpu[i - 1] < th_cpu_min_to_show_procs:
            continue
        # P =  p)[nr].split()[11:])
        r.insert(0, '%s ' % p[i][colmn:].replace(' ', '')[:10])


class sensors:
    def cpu():
        r = []
        l = ctx.pop('cpu_top', 0)
        if l:
            ctx['cpu_top_old'] = l
            ctx['cpu_top_old_ts'] = time.time()
        with open(proc_stat) as fd:
            t = fd.read()
        o = ctx['proc_stat']
        h = []
        for i in range(CPUs):
            v, t = t.split('cpu%s ' % i, 1)[1].split('\n', 1)
            v = int(v.split(' ', 1)[0])
            d = min(v - o[i], 99.9)
            o[i] = v
            # print(i, d, file=sys.stderr)
            h.append(d)
        h = list(reversed(sorted(h)))
        # show top process:
        if h[0] > th_cpu_min_to_snapshot_top:  # 20
            ctx['cpu_top'] = run_top()  # for hover tip - only when there is activity
            if h[0] > th_cpu_min_to_show_procs:
                add_top_cpu_eaters(r, show_max_procs, h)  # for status bar
        ctx['col_cpu'] = col_high if h[0] > th_color_high_cpu else col_norm
        v = lambda d: '' if d < th_min_cpu_show_core else bars[int(d / bar_intv)]
        [r.append(v(d)) for d in h]
        return ''.join(r)


# These would be other sensors - but for those we take the original ones from XFCE4:
#     def time():
#         t = time.ctime().split()
#         t.pop(1)  #  month
#         t.pop()
#         return ' '.join(t)

#     def mem():
#         return '%s' % psutil.virtual_memory().percent

#     def traffic():
#         r = []
#         o = ctx['traffic']
#         h = psutil.net_io_counters(pernic=False)
#         v = [h.bytes_sent, h.bytes_recv]
#         print('')
#         for i in range(2):
#             d = 100 * (min((v[i] - o[i]), Traffic100 - 1) / Traffic100)
#             # print('%s\t%s' % (v[i] - o[i], d))
#             o[i] = v[i]
#             arrs, arr_int = arrows[i]
#             col = '\x04' if i == 0 else '\x03'
#             s = arrs[int(d / arr_int)]
#             r.append('%s%s' % (col, s))
#         return ''.join(r)

#     def battery():
#         B = ''
#         P = 'ﮤ'
#         d = psutil.sensors_battery()
#         d, pp = int(d.percent), d.power_plugged
#         p = '\x02' + P[0] if pp else '\x04' + P[1]
#         s = B[int(min(d, 99) / (100 / len(B)))]
#         if d < 30:
#             s = '\x04' + s
#         if d < 60:
#             s = '\x03' + s
#         else:
#             s = '\x02' + s
#         if d > 90 and pp:
#             return ''
#         return s + ' ' + p + ' '


# for dwm's status bar (old version, caused high cpu):
# def xsetroot(sl):
#     if os.system('xsetroot -name "%s"' % sl):
#         print('exitting status.py')
#         sys.exit(1)


def to_stdout(sl):
    sl = '<txt><span fgcolor="%s">%s</span></txt>' % (ctx['col_cpu'], sl)
    t = ctx.get('cpu_top')
    if not t:
        t = ctx.get('cpu_top_old')
        if t:
            t = '%s Seconds Ago:\n' % (int(time.time() - ctx['cpu_top_old_ts'])) + t

    if t:
        sl += '<tool><span font_family="monospace">%s</span></tool>' % t
    print(sl)
    fd = ctx['fd_out']
    fd.seek(0)
    fd.write(sl)
    fd.flush()


def main():
    ctx['fd_out'] = open(fn_out, 'w')
    out = to_stdout
    while True:
        s.clear()
        for w in Sensors:
            k = getattr(sensors, w)()
            s.append('%s ' % k)
        sl = ''.join(s)
        r = os.popen('ls -lta --color=always').read()
        out(sl)
        time.sleep(1)  # other values: load calc must be adapted.


# Follows the top config - you cant use CLI flags for this.
# Created by: `HOME=~/.dwm top` -> F (select fields) -> W (write toprc)
# then:
# cat .dwm/.config/procps/toprc | base64  >> $HOME/bin/cpu_mon.py (is binary)
top_cfg = '''
dG9wJ3MgQ29uZmlnIEZpbGUgKExpbnV4IHByb2Nlc3NlcyB3aXRoIHdpbmRvd3MpCklkOmosIE1v
ZGVfYWx0c2NyPTAsIE1vZGVfaXJpeHBzPTEsIERlbGF5X3RpbWU9My4wLCBDdXJ3aW49MApEZWYJ
ZmllbGRzY3VyPaWmqDO0Oz1AxLe6OcUnKSorLC0uLzAxMjU2ODw+P0FCQ0ZHSElKS0xNTk9QUVJT
VFVWV1hZWltcXV5fYGFiY2RlZmdoaWprbG1ub3BxcnN0dXZ3eHl6Cgl3aW5mbGFncz0xNjEwNzYs
IHNvcnRpbmR4PTE4LCBtYXh0YXNrcz0wLCBncmFwaF9jcHVzPTAsIGdyYXBoX21lbXM9MCwgZG91
YmxlX3VwPTAsIGNvbWJpbmVfY3B1cz0wCglzdW1tY2xyPTEsIG1zZ3NjbHI9MSwgaGVhZGNscj0z
LCB0YXNrY2xyPTEKSm9iCWZpZWxkc2N1cj2lprm3uiiztMS7vUA8p8UpKissLS4vMDEyNTY4Pj9B
QkNGR0hJSktMTU5PUFFSU1RVVldYWVpbXF1eX2BhYmNkZWZnaGlqa2xtbm9wcXJzdHV2d3h5egoJ
d2luZmxhZ3M9MTkzODQ0LCBzb3J0aW5keD0wLCBtYXh0YXNrcz0wLCBncmFwaF9jcHVzPTAsIGdy
YXBoX21lbXM9MCwgZG91YmxlX3VwPTAsIGNvbWJpbmVfY3B1cz0wCglzdW1tY2xyPTYsIG1zZ3Nj
bHI9NiwgaGVhZGNscj03LCB0YXNrY2xyPTYKTWVtCWZpZWxkc2N1cj2lurs8vb6/wMFNQk7DRDM0
t8UmJygpKissLS4vMDEyNTY4OUZHSElKS0xPUFFSU1RVVldYWVpbXF1eX2BhYmNkZWZnaGlqa2xt
bm9wcXJzdHV2d3h5egoJd2luZmxhZ3M9MTkzODQ0LCBzb3J0aW5keD0yMSwgbWF4dGFza3M9MCwg
Z3JhcGhfY3B1cz0wLCBncmFwaF9tZW1zPTAsIGRvdWJsZV91cD0wLCBjb21iaW5lX2NwdXM9MAoJ
c3VtbWNscj01LCBtc2dzY2xyPTUsIGhlYWRjbHI9NCwgdGFza2Nscj01ClVzcglmaWVsZHNjdXI9
paanqKqwube6xMUpKywtLi8xMjM0NTY4Ozw9Pj9AQUJDRkdISUpLTE1OT1BRUlNUVVZXWFlaW1xd
Xl9gYWJjZGVmZ2hpamtsbW5vcHFyc3R1dnd4eXoKCXdpbmZsYWdzPTE5Mzg0NCwgc29ydGluZHg9
MywgbWF4dGFza3M9MCwgZ3JhcGhfY3B1cz0wLCBncmFwaF9tZW1zPTAsIGRvdWJsZV91cD0wLCBj
b21iaW5lX2NwdXM9MAoJc3VtbWNscj0zLCBtc2dzY2xyPTMsIGhlYWRjbHI9MiwgdGFza2Nscj0z
CkZpeGVkX3dpZGVzdD0wLCBTdW1tX21zY2FsZT0xLCBUYXNrX21zY2FsZT0wLCBaZXJvX3N1cHBy
ZXNzPTAK
'''.strip()


import base64


def write_top_cfg():
    os.makedirs(top_rc_dir, exist_ok=True)
    with open(top_rc_dir + '/toprc', 'wb') as fd:
        fd.write(base64.standard_b64decode(top_cfg))


if __name__ == '__main__':
    write_top_cfg()
    try:
        main()
    finally:
        ctx['fd_out'].close()
