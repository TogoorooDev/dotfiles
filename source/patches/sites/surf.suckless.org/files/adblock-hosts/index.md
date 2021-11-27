Adblocking using /etc/hosts
===========================

Adblocking is a non-trivial task, but there are trivial solutions.

host-gen
--------

Install hosts-gen from <http://git.r-36.net/hosts-gen/>

	% git clone http://git.r-36.net/hosts-gen
	% cd hosts-gen
	% sudo make install

Make sure all your custom configuration from your current /etc/hosts is
preserved in a file in /etc/hosts.d. The files have to begin with a
number, a minus and then the name.

Install the gethostszero script.

	# In the above directory.
	% sudo cp examples/gethostszero /bin
	% sudo chmod 775 /bin/gethostszero
	% sudo /bin/gethostszero
	% sudo hosts-gen 

Now the /etc/hosts with the zero hosts is ready and will be used in any
further started application.

The gethostszero file can of course be reused to more easier create the
/etc/hosts file. A cronjob can be used to update the file and run hosts-gen
again.


* Author : Christoph Lohmann < 20h (at) r-36 (dot) net >


zerohosts
---------

The following script gather well-known and trusted lists from various
places : [adaway](https://adaway.org/hosts.txt), 
[someonewhocares](https://someonewhocares.org/hosts/zero/hosts),
[pgl.yoyo](https://pgl.yoyo.org/adservers/serverlist.php?hostformat=hosts&showintro=0&mimetype=plaintext)...

They are written in `/etc/hosts` file to disable DNS resolution.

Get the script from here :
[zerohosts](https://dev.si3t.sh/OpenBSD-stuff/zerohosts).

Include your own `/etc/hosts` rules by including a file as an argument

	zerohosts /etc/myhosts.txt

Run the script each time you want to update the lists using a cronjob, or
`/etc/rc.local` : 

	/usr/local/sbin/zerohosts &


* Main page : <https://si3t.ch/Logiciel-libre/Code/zerohosts.html>
* Author : < prx (at) si3t (dot) ch > 
  (feel free to suggest improvements)


firejail
--------

If you don't want to use your /etc/hosts file, you can use firejail:
    
    firejail --noprofile --hosts-file="~/adblockhosts" surf "example.com"
