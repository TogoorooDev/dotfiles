Middle click links
==================

Description
-----------

This script must be deployed into the ~/.surf/user.js and one will be able to open link 
in a new window with middleclick or with control click.

	(function() {
		window.addEventListener("click", function(e) {
			if (
			      e.button == 1 // for middle click
			      //|| e.ctrlKey   // for ctrl + click
			   ) {
				var new_uri = e.srcElement.href;
				if (new_uri) {
					e.stopPropagation();
					e.preventDefault();
					window.open(new_uri);
				}
			}
		}, false);
	})();

Author
------

* Original author n30n , actual revision chm.duquesne.

The last version of this script is
[here](http://www.uzbl.org/wiki/middle_click_links)
under a [CC Attribution-Noncommercial-Share Alike 3.0 Unported license](http://creativecommons.org/licenses/by-nc-sa/3.0/).
