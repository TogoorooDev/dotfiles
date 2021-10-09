#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

#define IFNAMSIZ 16


static const char* determine_def_if(void) {
    FILE *f;
    const char* ret = 0;
    static char buf[IFNAMSIZ];
    char filebuf[256];
    f = fopen("/proc/net/route", "r");
    if (f) {
        while (fgets(filebuf, sizeof filebuf, f)) {
            char *tab = strchr(filebuf, '\t');
            if (tab && !strncmp(tab + 1, "00000000", 8)) {
                memcpy(buf, filebuf, tab - filebuf);
                buf[tab - filebuf] = 0;
                ret = buf;
                break;
            }
        }
        fclose(f);
    }
    return ret;
}

static uint64_t readfile(const char* filename) {
    FILE* f;
    uint64_t ret = 0, tmp;
    f = fopen(filename, "r");
    if (f) {
        if (fscanf(f, "%"SCNu64, &tmp) == 1)
            ret = tmp;
        fclose(f);
    }
    return ret;
}

static uint64_t get_rx_bytes(const char* interface)
{
    char fnbuf[sizeof "/sys/class/net//statistics/rx_bytes" + IFNAMSIZ];
    strcpy(fnbuf, "/sys/class/net/");
    strcat(fnbuf, interface);
    strcat(fnbuf, "/statistics/rx_bytes");
    return readfile(fnbuf);
}

static uint64_t get_tx_bytes(const char* interface)
{
    char fnbuf[sizeof "/sys/class/net//statistics/rx_bytes" + IFNAMSIZ];
    strcpy(fnbuf, "/sys/class/net/");
    strcat(fnbuf, interface);
    strcat(fnbuf, "/statistics/tx_bytes");
    return readfile(fnbuf);
}

static int get_suff(uint64_t x)
{
    int r = -1 + !x;
    while (x) {
        r++;
        x >>= 10;
    }
    return r;
}

int main(void) {
    Display *dpy;
    Window root;
    int loadfd;

    setlocale(LC_ALL, "");
    dpy = XOpenDisplay(0);
    if (dpy) {
        struct timespec tm, s;
        ssize_t rv;
        char oldif[IFNAMSIZ] = {0};
        uint64_t rxb, txb;
        static const char suffixes[] = " KMGT"; // let's stay real here
        root = XDefaultRootWindow(dpy);
        clock_gettime(CLOCK_REALTIME, &tm);
        s.tv_sec = 0;
        s.tv_nsec = 1000000000 - tm.tv_nsec;
        do rv = nanosleep(&s, &s);
        while (rv == -1 && s.tv_nsec);
        for (;;) {
            char buf[100]; // estimate
            const char *thisif = determine_def_if();
            uint64_t currxb, curtxb;
            int idx;
            int i;
            if (thisif)
            {
                if (strcmp(thisif, oldif))
                {
                    strcpy(oldif, thisif);
                    rxb = txb = 0;
                }
                i = 0;
                buf[i++] = oldif[0];
                buf[i++] = ' ';
                buf[i++] = 'v';
                currxb = get_rx_bytes(oldif);
                curtxb = get_tx_bytes(oldif);
                idx = get_suff(currxb - rxb);
                i += snprintf(buf + i, sizeof buf - i, "%.1f%c", (double)(currxb - rxb) / pow(1024, idx), suffixes[idx]);
                rxb = currxb;
                buf[i++] = ' ';
                buf[i++] = '^';
                idx = get_suff(curtxb - txb);
                i += snprintf(buf + i, sizeof buf - i, "%.1f%c", (double)(curtxb - txb) / pow(1024, idx), suffixes[idx]);
                txb = curtxb;
            }
            else
                buf[i++] = 'n';
            buf[i++] = ' ';
            buf[i++] = '|';
            buf[i++] = ' ';
            time_t t;
            size_t l;
            t = time(0);
            l = strftime(buf + i, sizeof buf - i, "%c", localtime(&t));
            XStoreName(dpy, root, buf);
            XSync(dpy, False);
            sleep(1);
        }
    }
}
