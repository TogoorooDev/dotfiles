# transfer

These two patches, transfer and transferall, let you transfer clients
between the master and stack while automatically adjusting nmaster.
These are two independent patches which can be used separately.

The transfer patch adds a function that lets you transfer the currently
focused client between the master and the stack boundry and auto
increments or decrements nmaster accordingly. For example, if you're
focused on a stack client, using the transfer function moves the client
to the master area and increments nmaster by 1. Conversely if you're
focused on a master client and call transfer, the client is moved to
the stack and nmaster is decremented by 1.

The transferall patch adds a function that lets you transfer all
clients in the master into the stack and stack clients into the master;
effectively swapping the master and the stack. The new nmaster is adjusted
to be the old number of clients in the stack.

## Download
* [dwm-transfer-6.2.diff](dwm-transfer-6.2.diff) (09/26/2020)
* [dwm-transferall-6.2.diff](dwm-transferall-6.2.diff) (02/01/2020)

## Author
- Miles Alan (m@milesalan.com)
