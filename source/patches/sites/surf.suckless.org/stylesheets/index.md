Site-Specific Stylesheets
=========================

Please add stylesheets you would like the world to use for making the web more
useful (or fix its bugs). See the wiki section on how to do this.

Howto
-----
Surf has the feature to apply site-specific stylesheets for websites. This is
controlled by changing the `styles` array in your config.h

	/* styles */
	static SiteStyle styles [] = {
		/* regexp               file in $styledir */
		...
	};

Now add a new entry:

		{ ".*www.wikipedia.org.*", "wikipedia.css" };

Then create the styles directory:

	% mkdir -p $HOME/.surf/styles

And add a `wikipedia.css` file there containing:

	* {
		font-weight: bold;
	}

Now use your favourite method to recompile and run surf. You will notice
that on `wikipedia.org` all text is now in bold.

