![surf](surf.svg)

surf is a simple web browser based on WebKit2/GTK+. It is able
to display websites and follow links. It supports the XEmbed protocol
which makes it possible to embed it in another application. Furthermore,
one can point surf to another URI by setting its XProperties.

2009/9/17 Simon Rozet <simon@rozet.name>:
> I though exactly the same before. I always had +20 tabs open in firefox.
> Honestly, I'd never thought I'd enjoy using a browser with no tab support
> until I forced myself to use surf for a week. I am now much less distracted
> and more focused when browsing the web. dwm + surf <3

Getting Started
---------------
Start the browser with

	surf http://your-url

You can navigate by clicking on links on the displayed page. Hit *Ctrl-g* to enter a new URL. For more commands consult

	man surf

Links
-----
* Mailing List: `dev+subscribe@suckless.org` ([Archives](//lists.suckless.org/dev))
* IRC channel: #suckless at irc.oftc.net

Note On Webkit Versions
-----------------------
Compile your own webkit or expect hell. The packaging of webkit is pure
insane.
Surf uses upstream stable webkit2gtk by default, but the previous
version based on webkit1gtk is still available as a branch.

Development
-----------
surf is actively developed. You can [browse](//git.suckless.org/surf) its
source code repository or get a copy with the following command:

	git clone https://git.suckless.org/surf

Download
--------
* [MIT/X Consortium license](//git.suckless.org/surf/plain/LICENSE)
* [surf 2.1](//dl.suckless.org/surf/surf-2.1.tar.gz) (2021-05-08)
* See also [dmenu](//tools.suckless.org/dmenu),
  [tabbed](//tools.suckless.org/tabbed)
