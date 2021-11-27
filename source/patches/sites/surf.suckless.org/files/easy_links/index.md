# Link hinting
## Description
This script allows a user to follow link by pressing Alt+number of the
link. Numbers are never over 5, to ease finger access.  
Deploy it into ~/.surf/script.js

*Needs some work on the script to permi buttons and textinput
following...*

## Usage
Press `Alt`, then the number of the link, and finally `f`to follow the
link, only with left hand.

## Author
Christian hahn <ch radamanthys de>

[dev mailing list](//lists.suckless.org/dev/1009/5996.html)


## Code


	// easy links for surf
	// christian hahn <ch radamanthys de>, sep 2010

	testcomplete = function() {
		if(document.readyState=="complete") {
			run(); return;
		}
		window.setTimeout("testcomplete()",200);
	}
	testcomplete();

	run=function() {
		// config , any css
		var modkey      = 18;  //ctrl=17, alt=18
		var cancelkey   = 67;  // c
		var newwinkey   = 84;  // t
		var openkey     = 70;  // f
		var label_style = {"color":"black","fontSize":"10px","backgroundColor":"#27FF27","fontWeight":"normal","margin":"0px","padding":"0px","position":"absolute","zIndex":99};
		var hl_style    = {"backgroundColor":"#E3FF38","fontSize":"15px"};
		var nr_base     = 5;   // >=10 : normal integer,

		// globals
		var ankers     = document.getElementsByTagName("a");
		var labels     = new Object();
		var ui_visible = false;
		var input      = "";

		// functions
		hl=function(t) {
			for(var id in labels) {
				if (t && id.match("^"+t)==t)
					for(var s in hl_style)
						labels[id].rep.style[s]=hl_style[s];
				else
					for(var s in label_style)
						labels[id].rep.style[s]=label_style[s];
			}
		}
		open_link=function(id, new_win) {
			try {
				var a = labels[input].a;
				if(a && !new_win) window.location.href=a.href;
				if(a && new_win)  window.open(a.href,a.href);
			} catch (e) {}
		}
		set_ui=function(s) {
			var pos = "static";
			ui_visible = true;
			if(s == "hidden") {
				ui_visible = false;
				pos = "absolute";
				input="";
			}
			for(var id in labels) {
				labels[id].rep.style.visibility=s;
				labels[id].rep.style.position=pos;
			}
		}
		base=function(n, b) { 
			if(b>=10) return n.toString();
			var res = new Array();
			while(n) {
				res.push( (n%b +1).toString() )
				n=parseInt(n/b);
			}
			return res.reverse().join("");
		}

		// main
		// create labels
		for (var i=0; i<ankers.length; i++) {
			var a = ankers[i];
			if (!a.href) continue;
			var b = base(i+1,nr_base);
			var d = document.createElement("span");
			d.style.visibility="hidden";
			d.innerHTML=b;
			for(var s in label_style)
				d.style[s]=label_style[s];
			labels[b]={"a":a, "rep":d};
			a.parentNode.insertBefore(d, a.nextSibling);
		}

		// set key handler   
		window.onkeydown=function(e) {
			if (e.keyCode == modkey) {
				set_ui("visible");
			}
		}
		window.onkeyup=function(e) {
			if (e.keyCode == modkey ) {
				open_link(input);
				set_ui("hidden");
				hl(input);
			} else if (ui_visible) {
				if(e.keyCode == newwinkey) {
					open_link(input, true);
					set_ui("hidden");
				} else if(e.keyCode == cancelkey)
					input="";
				else if(e.keyCode == openkey) {
					open_link(input);
					set_ui("hidden");
				} else
					input += String.fromCharCode(e.keyCode);
				hl(input);
			}
		}
	}


