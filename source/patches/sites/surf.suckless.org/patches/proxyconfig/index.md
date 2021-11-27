proxyconfig
===========

Description
-----------

This patch allows you to specify proxy settings in your config.h file.

It contains an enum which wraps the three proxy modes supported by Webkit:

* CustomProxy allows you to specify a custom proxy URL and list of hosts to ignore.
* SystemProxy uses your system proxy settings (which on *nix is your http_proxy environment variable).
* NoProxy ensures that a proxy is never used.

To use this patch, first set your ProxyMode Parameter to the desired value.
If you're using CustomProxy, you then need to set your ProxyUrl Parameter to the URL of your proxy, for example, "http://localhost:8080", or "socks://localhost:9050".
You may also optionally set your ProxyIgnoreHosts to specify a list of URLs which will not have their connections proxied. Please note that the SystemProxy mode will not respect your ProxyIgnoreHosts list -- my testing indicates that Webkit doesn't support this.

The default value is SystemProxy, which preserves the default behavior of vanilla surf out of the box.

Download
--------

* [surf-proxyconfig-20210503-7dcce9e.diff](surf-proxyconfig-20210503-7dcce9e.diff)
