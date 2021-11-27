/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nogroup";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#005577",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* length of entires in scom  */s
static const int entrylen = 1;

static const secretpass scom[entrylen] = {
/*	 Password				command */
	{ "shutdown",           "doas poweroff" },};
