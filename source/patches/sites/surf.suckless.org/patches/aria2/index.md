# aria2c

To use aria2 instead of curl as default download manager, just replace
the DOWNLOAD function like this in config.h:

	/* DOWNLOAD(URI, referer) */
	#define DOWNLOAD(d, r) { \
		.v = (char *[]){ "/bin/sh", "-c", \
			"cd ~/Telechargements;"\
			"st -e /bin/sh -c \"aria2c -U '$1'" \
			" --referer '$2' --load-cookies $3 --save-cookies $3 '$0';" \
			" sleep 3;\"", \
			d, useragent, r, cookiefile, NULL \
		} \
	}
