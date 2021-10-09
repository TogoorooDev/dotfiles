Keycode
=======
With this patch, handling key input is done with keycodes instead of keysyms.
This way, input is keyboard layout independant (adapt config.h to your keyboard
using for example xev).

Download
--------
* [tabbed-keycode-0.6.diff](tabbed-keycode-0.6.diff)
* [tabbed-keycode-20170508-6dc3978.diff](tabbed-keycode-20170508-6dc3978.diff)

Author
------
* Quentin Rameau <quinq@fifth.space>
