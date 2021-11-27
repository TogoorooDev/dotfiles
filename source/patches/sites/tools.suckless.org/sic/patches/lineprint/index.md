Print the current inserting line
================================
This patch allow to store and reprint the current inserting line. This is done
by appending a suffix character to the input. The line is (obviously) not sent.

In a nutshell:

	:ni\
	:nick baz\
	:nick bazqux
	clamiax : 2015-10-09 18:15 >< NICK (): bazqux

This is useful, for example, when receiving data from the server in the middle
of a sentence you're writing.

Note: the patch also changes the config.def.h file.

Download
--------
* [sic-lineprint-9bb34de.diff](sic-lineprint-9bb34de.diff) (1,3K) (20151009)

Author
------
* Claudio Alessi <smoppy@gmail.com>
