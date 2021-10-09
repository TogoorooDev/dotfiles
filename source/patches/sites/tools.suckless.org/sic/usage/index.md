Usage
=====

Since sic uses stdin and stdout as its user interfaces, it is easy to combine
it with other tools if you need more features.

See also the sic(1) man page.


History
-------

If you want to store what is being said, you can use the tee(1) command with
sic:

	$ sic | tee -a sic_history


Highlighting
------------
If you want to receive an alert in case someone mention your username, you can
use awk(1):

	$ sic | awk '/username/ {printf "\a"}1'

Using a tool like awk(1) would allow you to be highlighted on specific channels
for example. You can of course combine it with the tee(1) command above:

	$ sic | tee -a sic_history | awk '/username/ {printf "\a"}1'
