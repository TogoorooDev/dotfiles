RSS/Atom feed detection
=======================

Description
-----------

This script looks for links to RSS or Atom feeds in the current web page. If it
finds feeds, it places an icon in the corner of the page which toggles showing
a list of the feeds.

To install, put the code in `~/.surf/script.js`

Author
------

Charles E. Lehner <https://celehner.com/>

Code
----

	(function () {
		var urls = {}
		var feeds = [].slice.call(document.querySelectorAll(
			"link[href][rel~=alternate][type$=xml]," +
			"   a[href][rel~=alternate][type$=xml]"))
			.map(function (el) {
				return {
					href: el.href,
					title: el.title || document.title,
					type: /atom/i.test(el.type) ? 'Atom' : 'RSS'
				};
			}).filter(function (feed) {
				if (urls[feed.href]) return false
				return urls[feed.href] = true
			});
		if (!feeds.length) return;

		var container = document.createElement('div');
		container.style.position = 'fixed';
		container.style.bottom = 0;
		container.style.right = 0;
		container.style.zIndex = 10000;
		document.body.appendChild(container);

		var feedList = document.createElement('div');
		feedList.style.display = 'none';
		feedList.style.backgroundColor = '#ddd';
		feedList.style.border = '1px solid #bbb';
		feedList.style.borderStyle = 'solid solid none';
		feedList.style.padding = '2px 4px';
		container.appendChild(feedList);

		feeds.forEach(function (feed) {
			var a = document.createElement('a');
			a.href = feed.href;
			a.style.display = 'block';
			a.style.color = 'blue';
			var title = feed.title;
			if (title.indexOf(feed.type) == -1)
				title += ' (' + feed.type + ')';
			a.appendChild(document.createTextNode(title));
			feedList.appendChild(a);
		});

		var toggleLink = document.createElement('a');
		toggleLink.href = '';
		toggleLink.style.display = 'inline-block';
		toggleLink.style.paddingRight = '3px';
		toggleLink.style.verticalAlign = 'bottom';
		toggleLink.addEventListener("click", toggleFeedList, true);
		container.appendChild(toggleLink);

		var img = new Image();
		img.style.padding = '4px';
		img.style.verticalAlign = 'bottom';
		img.src = 'data:image/gif;base64,' +
			'R0lGODlhDAAMAPUzAPJoJvJqKvNtLfNuL/NvMfNwMvNyNPNzNvN0OPN1OfN3O/R4' +
			'PfR5P/R6QPR7QvR+RvR/R/SASfSBS/SDTPWETvWFUPWGUvWJVfWLWfWMWvWNXPaW' +
			'aPaYbPaabfebb/eccfeedPehePemf/ingPiphPiqhviui/ivjfiwjviykPm6nPm+' +
			'ofzh1P3k2f3n3P7u5/7v6P738/749f///wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA' +
			'AAAAAAAAAAAAAAAAACH5BAEAADQALAAAAAAMAAwAAAZ6QFqB4YBAJBLKZCEsbCDE' +
			'I2WqQCBms9fqkqRIJg7EZ+WawTxeSAS6AklIMhknwjA6sC/SR/aSKBwSEBcpLzMk' +
			'IjMoBwwTECEoGTAvDi8uBAhKMokmMxwqMwIIFhQsMRoZMyeIFgILFoEMCAcEAgEA' +
			'BDQKRhAOsbICNEEAOw==';
		toggleLink.appendChild(img);

		if (feeds.length > 1) {
			toggleLink.appendChild(document.createTextNode(feeds.length));
		}

		function toggleFeedList(e) {
			e.preventDefault();
			feedList.style.display = (feedList.style.display == 'none') ?
				'inline-block' : 'none';
		}
	})();
