#if 0

TITLE

 subject: ntile/nmaster/tilecols layouts with cpt patch included for dwm-4.6
 author: pancake <youterm.com> *


NOTES

 Remember to append a ISTILE line like that one in your config.h:

#define ISTILE  isarrange(tile) || isarrange(ntile) || isarrange(dntile) || isarrange(tilecols)


INSTALLATION

 Copy this file into the dwm root directory (the one) and follow the instructions
 related into the configuration section.


CONFIGURATION

You should modify your config.h to include "nmaster.c" from it after
setting the NMASTER, NCOLS and NROWS macro definitions.


  *** NMASTER ***

#define NMASTER 1
#include "nmaster.c"

Layout layouts[] = {
        { "-|=",                ntile }, /* first entry is default */
..
        { MODKEY|ShiftMask,             XK_j,           setnmaster,     "+1"}, \
        { MODKEY|ShiftMask,             XK_k,           setnmaster,     "-1"}, \



  *** TILECOLS ***

#define NCOLS 2
#define NROWS 1
#include "nmaster.c"

Layout layouts[] = {
        { "E|]",                tilecols }, /* first entry is default */
..
	{ MODKEY|ShiftMask,		XK_j,		setnrows,	"+1" }, \
	{ MODKEY|ShiftMask,		XK_k,		setnrows,	"-1" }, \
	{ MODKEY|ShiftMask,		XK_l,		setncols,	"+1" }, \
	{ MODKEY|ShiftMask,		XK_h,		setncols,	"-1" }, \


  *** CLIENTS PER TAG ***

  Valid values are:
   -1  -  show all clients
    0  -  show no clients
   >0  -  show N clients

  Example configuration:
        { MODKEY|ShiftMask,             XK_q,           clientspertag,  "0" }, \
        { MODKEY,                       XK_q,           clientspertag,  "^1" }, \
        { MODKEY,                       XK_w,           clientspertag,  "^2" }, \
        { MODKEY,                       XK_e,           clientspertag,  "^3" }, \

#endif

int cpt = -1;
void clientspertag(const char *arg) {
        if (arg[0]=='^') {
                if (cpt==-1) cpt = atoi(arg+1);
                else cpt = -1;
        } else cpt = atoi(arg);
        arrange();
}

#ifdef NMASTER
int nmaster = NMASTER;
void
ntile(void) {
	unsigned int i, n, nx, ny, nw, nh, mw, mh, th;
	Client *c;

	for(n = 0, c = nexttiled(clients); c; c = nexttiled(c->next))
		n++;

	if (cpt!=-1 && n>cpt) n = cpt;

	/* window geoms */
	mh = (n <= nmaster) ? wah / (n > 0 ? n : 1) : wah / nmaster;
	mw = (n <= nmaster) ? waw : mwfact * waw;
	th = (n > nmaster) ? wah / (n - nmaster) : 0;
	if(n > nmaster && th < bh)
		th = wah;

	nx = wax;
	ny = way;
	for(i = 0, c = nexttiled(clients); c; c = nexttiled(c->next), i++) {
		if (cpt!=-1 && i>=cpt) {
			ban(c);
			continue;
		}
		c->ismax = False;
		if(i < nmaster) { /* master */
			ny = way + i * mh;
			nw = mw - 2 * c->border;
			nh = mh;
			if(i + 1 == (n < nmaster ? n : nmaster)) /* remainder */
				nh = wah - mh * i;
			nh -= 2 * c->border;
		}
		else {  /* tile window */
			if(i == nmaster) {
				ny = way;
				nx += mw;
			}
			nw = waw - mw - 2 * c->border;
			if(i + 1 == n) /* remainder */
				nh = (way + wah) - ny - 2 * c->border;
			else
				nh = th - 2 * c->border;
		}
		resize(c, nx, ny, nw, nh, False);
		if(n > nmaster && th != wah)
			ny += nh + 2 * c->border;
	}
}

void
dntile(void) {
	unsigned int i, n, nx, ny, nw, nh, mw, mh, th, inc;
	Client *c;

	for(n = 0, c = nexttiled(clients); c; c = nexttiled(c->next))
		n++;
	if (cpt!=-1 && n>cpt) n = cpt;

	/* dynamic nmaster */
	if (n<5) inc = 0;
	else if (n<7) inc = 1;
	else inc = 2;
	nmaster+=inc;

	/* window geoms */
	mh = (n <= nmaster) ? wah / (n > 0 ? n : 1) : wah / nmaster;
	mw = (n <= nmaster) ? waw : mwfact * waw;
	th = (n > nmaster) ? wah / (n - nmaster) : 0;
	if(n > nmaster && th < bh)
		th = wah;

	nx = wax;
	ny = way;
	for(i = 0, c = nexttiled(clients); c; c = nexttiled(c->next), i++) {
		if (cpt!=-1 && i>=cpt) {
			ban(c);
			continue;
		}
		c->ismax = False;
		if(i < nmaster) { /* master */
			ny = way + i * mh;
			nw = mw - 2 * c->border;
			nh = mh;
			if(i + 1 == (n < nmaster ? n : nmaster)) /* remainder */
				nh = wah - mh * i;
			nh -= 2 * c->border;
		}
		else {  /* tile window */
			if(i == nmaster) {
				ny = way;
				nx += mw;
			}
			nw = waw - mw - 2 * c->border;
			if(i + 1 == n) /* remainder */
				nh = (way + wah) - ny - 2 * c->border;
			else
				nh = th - 2 * c->border;
		}
		resize(c, nx, ny, nw, nh, False);
		if(n > nmaster && th != wah)
			ny += nh + 2 * c->border;
	}
	nmaster-=inc;
}

void
setnmaster(const char *arg) {
	int i;

	if(!isarrange(ntile)&&!isarrange(dntile))
		return;
	if(!arg)
		nmaster = NMASTER;
	else {
		i = atoi(arg);
		if((nmaster + i) < 1 || wah / (nmaster + i) <= 2 * BORDERPX)
			return;
		nmaster += i;
	}
	if(sel)
		arrange();
}
#endif

#ifdef NCOLS
#ifdef NROWS
unsigned int ncols = NCOLS;
unsigned int nrows = NROWS;

void
setncols(const char *arg) {
	int i;

	if(!isarrange(tile))
		return;
	if(!arg)
		i = NCOLS;
	else if(arg[0] != '+' && arg[0] != '-')
		i = atoi(arg);
	else
		i = ncols + atoi(arg);

	if((i < 1) || (i >= 1 && waw / i <= 2 * BORDERPX))
		return;
	ncols = i;

	if(sel)
		arrange();
}

void
setnrows(const char *arg) {
	int i;

	if(!isarrange(tile))
		return;
	if(!arg)
		i = NROWS;
	else if(arg[0] != '+' && arg[0] != '-')
		i = atoi(arg);
	else
		i = nrows + atoi(arg);

	if(i < 1 || wah <= 2 * BORDERPX * i)
		return;
	nrows = i;
 
	if(sel)
		arrange();
}

void
tilecols(void) {
	unsigned int i, n, nx, ny, nw, nh, mw, mh, tw, th, tw1, cols, rows, rows1;
	Client *c;

	for(n = 0, c = nexttiled(clients); c; c = nexttiled(c->next))
		n++;
 	/* calculate correct number of rows */
 	if(ncols > 0 && n - nmaster > nrows * ncols)
 		rows = (n - nmaster) / ncols + ((n - nmaster) % ncols ? 1 : 0);
	else
 		rows = nrows;

	if (cpt!=-1 && n>cpt) n = cpt;

	/* window geoms */
	mh = (n <= nmaster) ? wah / (n > 0 ? n : 1) : wah / nmaster;

	if (nmaster == 0) {
		mh = mw = 0;
	}
	else if (n <= nmaster) {
		mh = wah / (n > 0 ? n : 1);
		mw = waw;
	}
	else {
		mh = wah / nmaster;
		mw = mwfact * waw;
	}

	if(rows == 0 || n <= nmaster + rows) {
		rows1 = n > nmaster ? n - nmaster : 1;
		tw = tw1 = waw - mw; 
		th = wah / rows1;
	}
	else {
		rows1 = 1 + (n - nmaster - 1) % rows;
		cols = (n - nmaster) / rows + ((n - nmaster) % rows ? 1 : 0);
		tw = (waw - mw) / cols;
		tw1 = waw - mw - (cols - 1) * tw;
		th = wah / rows;
	}

	nx = wax;
	ny = way;

	for(i = 0, c = nexttiled(clients); c; c = nexttiled(c->next), i++) {
		if (cpt!=-1 && i>=cpt) {
			ban(c);
			continue;
		}
		c->ismax = False;
		if(i < nmaster) { /* master column */
			ny = way + i * mh;
			nw = mw - 2 * c->border;
 			nh = mh - 2 * c->border;
 			if(i == 0)
 				nh += wah - mh * (n < nmaster ? n : nmaster);
			//nh = mh;
			if(i + 1 == (n < nmaster ? n : nmaster)) /* remainder */
				nh = wah - mh * i;
			nh -= 2 * c->border;
		}
 		else if(i < nmaster + rows1) { /* first stack column */
 			if(i == nmaster) { /* initialise */
				ny = way;
				nx += mw;
 				nh = wah - 2*c->border - (rows1 - 1) * th;
			} else
				nh = th - 2 * c->border;
 			nw = tw1 - 2 * c->border;
 		}
 		else { /* successive stack columns - rows > 0 if we reach here */
 			if((i - nmaster - rows1) % rows == 0) { /* reinitialise */
 				ny = way;
 				nx += nw + 2 * c-> border;
 				nh = wah - 2*c->border - (rows - 1) * th;
 			}
 			else {
 				nh = th - 2 * c->border;
 			}
 			nw = tw - 2 * c->border;
		}
		resize(c, nx, ny, nw, nh, False);
 		ny += nh + 2 * c->border;
	}
}
#endif
#endif

