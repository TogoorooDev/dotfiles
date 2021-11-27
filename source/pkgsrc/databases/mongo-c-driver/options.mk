# $NetBSD: options.mk,v 1.2 2019/03/05 14:24:13 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mongo-c-driver
PKG_SUPPORTED_OPTIONS=	sasl ssl
PKG_SUGGESTED_OPTIONS=	ssl

PLIST_VARS+=	ssl

.include "../../mk/bsd.options.mk"

# Enable SASL support
.if !empty(PKG_OPTIONS:Msasl)
.  include "../../security/cyrus-sasl/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_SASL=CYRUS
.else
CMAKE_ARGS+=	-DENABLE_SASL=OFF
.endif

# Enable OpenSSL support
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CMAKE_ARGS+=	-DENABLE_SSL=OPENSSL
PLIST.ssl=	yes
.else
CMAKE_ARGS+=	-DENABLE_SSL=OFF
.endif
