ipc
====

Description
-----------
dwm-ipc is a patch for dwm that implements inter-process communication through
a UNIX socket. This allows you to query the window manager for information,
listen for events such as tag changes or layout changes, as well as send
commands to control the window manager from other programs/scripts.

The project is being managed and developed on this GitHub
[repo](https://github.com/mihirlad55/dwm-ipc). If you discover any bugs, feel
free to create an issue there.


Requirements
------------
In order to build dwm you need the Xlib header files. The patch
additionally requires [yajl](https://github.com/lloyd/yajl) which is a tiny C
JSON library.


Applying the Patch
------------------
The patch is best applied after all of your other patches due to the number of
additions to dwm.c. The patch was designed with compatability in mind, so there
are minimal deletions.


Patch Compatability
-------------------
At the moment, the patch will only work on systems that implement epoll and is
not completely portable. Portability will be improved in the future.


Supported IPC Messages
----------------------
At the moment the IPC patch supports the following message requests:
* Run user-defined command (similar to key bindings)

* Get information about available layouts

* Get information about the tags available

* Get the properties of all of the monitors

* Get the properties of a specific dwm client

* Subscribe to tag change, client focus change, layout change events, monitor
  focus change events, focused title change events, and focused state change
  events.

For more info on the IPC protocol implementation, visit the
[wiki](https://github.com/mihirlad55/dwm-ipc/wiki/).


dwm-msg
-------
`dwm-msg` is a cli program included in the patch which supports all of the IPC
message types listed above. The program can be used to run commands, query dwm
for information, and listen for events. This program is particularly useful for
creating custom shell scripts to control dwm.


Download
--------
* IPC Patch v1.5.7:
  [dwm-ipc-20201106-f04cac6.diff](dwm-ipc-20201106-f04cac6.diff)
* IPC Patch v1.5.6 to v1.5.7 Update:
  [dwm-ipc-v1.5.6-to-v1.5.7.diff](dwm-ipc-v1.5.6-to-v1.5.7.diff)

The latest releases of the patch will always be available first on the project
[Releases](https://github.com/mihirlad55/dwm-ipc/releases) page. There are also
"update" patches to update from previous versions of the patch.


Related Projects
----------------
* [dwmipcpp](https://github.com/mihirlad55/dwmipcpp) is a C++ client library
  for interacting with an IPC-patched dwm

* [polybar-dwm-module](https://github.com/mihirlad55/polybar-dwm-module)
  requires this patch


Authors
-------
* Mihir Lad - <mihirlad55 at gmail>
