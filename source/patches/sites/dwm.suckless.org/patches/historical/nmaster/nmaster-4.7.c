#if 0

TITLE
-----
 descrp:  ntile/tilecols layouts with clientspertag for dwm-4.7
 author:  pancake <youterm.com>
 update:  2007-12-01


CONFIGURATION
-------------
 You should modify your config.h to include "nmaster.c" AFTER setting
 the NMASTER, NCOLS, NROWS, BORDERPX, and RESIZEHINTS macro definitions
 and BEFORE the layouts definition.

 A sample configuration with ntile will be:

   #define NMASTER 1
   #define NCOLS 1
   #define NROWS 1
   #define CPTH 32
   #include "nmaster-4.7.c"
   
   Layout layouts[] = {
        { "-|=" , ntile },
        // ...
   };

   // keys
    { MODKEY|ShiftMask , XK_j    , setnmaster , "+1" } , \
    { MODKEY|ShiftMask , XK_k    , setnmaster , "-1" } , \
    { MODKEY , XK_q , clientspertag ,"^1" } , \
    { MODKEY , XK_w , clientspertag , "2" } , \
    { MODKEY , XK_e , clientspertag , "3" } , \
    { MODKEY           , XK_n , setcpth , "+32" } , \
    { MODKEY|ShiftMask , XK_n , setcpth , "-32" } , \


 clientspertag:

  both of them features the new cpt patch (clients per tag) which enables
  to define the maximum number of clients you want to focus, the rest are
  stacked at the bottom of the screen. This area has CPTH height and this
  value can be changed on the fly using the setcpth function.

  +------+----+
  |      |    |   Valid values are:
  |      |----|    -1  -  show all clients
  |      |    |     0  -  show all clients in the bottom stack area
  +---+--^+---+    >0  -  show N clients
  +---+---+---+

    #define CPTH 32   // num of pixels of the height of the stacked cpt area
 
    { MODKEY , XK_q , clientspertag ,"^1" } , \
    { MODKEY , XK_w , clientspertag , "2" } , \
    { MODKEY , XK_e , clientspertag , "3" } , \
    { MODKEY , XK_r , clientspertag , "4" } , \
    { MODKEY , XK_t , clientspertag , "5" } , \
 
    { MODKEY           , XK_n , setcpth , "+32" } , \
    { MODKEY|ShiftMask , XK_n , setcpth , "-32" } , \


 This source adds two new layouts:

 ntile:

  +-----+--+     
  |_____|--|     
  |     |--|     
  +-----+--+

    #define NMASTER 1

    { "-|="            , ntile } , \

    { MODKEY|ShiftMask , XK_j    , setnmaster , "+1" } , \
    { MODKEY|ShiftMask , XK_k    , setnmaster , "-1" } , \


 tilecols:

  +--+--+--+     
  |__|  |__|     
  |  |  |  |     
  +--+--+--+     

    #define NCOLS 2
    #define NROWS 1

    { "E|]"            , tilecols } , \

    { MODKEY|ShiftMask , XK_j , setnrows , "+1" } , \
    { MODKEY|ShiftMask , XK_k , setnrows , "-1" } , \
    { MODKEY|ShiftMask , XK_h , setncols , "+1" } , \
    { MODKEY|ShiftMask , XK_l , setncols , "-1" } ,

#endif


/* height for bottom stacked clients */
#ifndef CPTH
#define CPTH 32
#endif
/* initial value for clients per tag */
#ifndef CPT
#define CPT -1
#endif

void
maxzoom(const char *arg) {
	if (sel->isfloating)
		togglemax(NULL);
	else
		zoom(NULL);
}

int cpt = CPT;
int Cpth = CPTH;

void
clientspertag(const char *arg) {
	if (*arg=='+' || *arg=='-') {
		cpt += atoi(arg);
        } else if (arg[0]=='^') {
                if (cpt==-1) cpt = atoi(arg+1);
                else cpt = -1;
        } else cpt = atoi(arg);
        arrange();
}

void
setcpth(const char *arg) {
	int i;

	if(!arg)
		Cpth = CPTH;
	else {
		Cpth += atoi(arg);
		if (Cpth-CPTH<=0)
			Cpth = CPTH;
		if (Cpth+CPTH>=wah)
			Cpth = wah - CPTH;
	}
	if(sel)
		arrange();
}

#ifdef NMASTER
int nmaster = NMASTER;

void
ntile(void) {
	unsigned int i, n, t, nx, ny, nw, nh, mw, mh, th;
	int cptn = 0, cpth = 0;
	Client *c;

	domwfact = dozoom = True;

	for(n = 0, c = nexttiled(clients); c; c = nexttiled(c->next)) {
		//if (cpt!=-1 && n>=cpt && sel == c) { n=cpt; zoom(NULL); break; }
		n++;
	}
	t = n;
	if (cpt!=-1&&n>cpt) {
		n    = cpt;
		cpth = Cpth;
		wah -= cpth;
	}
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
			nw = waw/(t-n) - c->border*2;
			nx = (nw+c->border*2)*cptn;
			cptn++;
			ny = wah + way;
			nh = cpth-(c->border*2);
			if (nh<c->border) nh = cpth;
			resize(c, nx, ny, nw, nh, RESIZEHINTS);
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
		resize(c, nx, ny, nw, nh, RESIZEHINTS);
		if(n > nmaster && th != wah)
			ny += nh + 2 * c->border;
	}
	wah += cpth;
}

void
setnmaster(const char *arg) {
	int i;

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
	unsigned int i, n, nx, ny, nw, nh, mw, mh, tw, th, tw1, cols, rows, rows1, t;
	int cpth = 0, cptn = 0;
	Client *c;

	domwfact = dozoom = True;

	for(n = 0, c = nexttiled(clients); c; c = nexttiled(c->next)) {
	//	if (cpt!=-1 && n>=cpt && sel == c) { n=cpt; zoom(NULL); break; }
		n++;
	}

 	/* calculate correct number of rows */
 	if(ncols > 0 && n - nmaster > nrows * ncols)
 		rows = (n - nmaster) / ncols + ((n - nmaster) % ncols ? 1 : 0);
	else
 		rows = nrows;

	t = n;
	if (cpt!=-1&&n>cpt) {
		n    = cpt;
		cpth = Cpth;
		wah -= cpth;
	}

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
#if 0
		if (cpt!=-1 && i>=cpt) {
			ban(c);
			continue;
		}
#endif
		if (cpt!=-1 && i>=cpt) {
			nw = waw/(t-n) - c->border*2;
			nx = (nw+c->border*2)*cptn;
			cptn++;
			ny = wah + way;
			nh = cpth-(c->border*2);
			if (nh<c->border) nh = cpth;
			resize(c, nx, ny, nw, nh, RESIZEHINTS);
			continue;
		}
		c->ismax = False;
		if(i < nmaster) { /* master column */
			ny = way + i * mh;
			nw = mw - 2 * c->border;
 			nh = mh - 2 * c->border;
 			if(i == 0)
 				nh += wah - mh * (n < nmaster ? n : nmaster);
			nh = mh;
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
		resize(c, nx, ny, nw, nh, RESIZEHINTS);
 		ny += nh + 2 * c->border;
	}
	wah += cpth;
}
#endif
#endif

/* EXPERIMENTAL:
 *
 *    Work in progress stuff
 */
#ifdef EXPERIMENTAL
void
swapclients(Client *c1, Client *c2)
{
	Client *tmp;

	if (c2 == NULL) {
		c1->prev->next = NULL;
		c1->next = clients;
		clients = c1;
		return;
	}

	tmp = c1->next;
	c1->next = c2->next;
	c2->next = (tmp == c2 ? c1 : tmp);

	tmp = c2->prev;
	c2->prev = c1->prev;
	c1->prev = (tmp == c1 ? c2 : tmp );

	if(c1->next)
		c1->next->prev = c1;

	if(c1->prev)
		c1->prev->next = c1;

	if(c2->next)
		c2->next->prev = c2;

	if(c2->prev)
		c2->prev->next = c2;

	//if(clients == c1)
	//	clients = c2;
}

void
swap(const char *arg) {
	int i;

	if(sel) {
		if (*arg=='+')
			swapclients(sel, sel->next);
		else
		if (*arg=='-')
			swapclients(sel, sel->prev);
		arrange();
	}
}
#endif

#ifdef EXPERIMENTAL
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
	nmaster -= inc;
}
#endif
