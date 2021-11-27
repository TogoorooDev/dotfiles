# $NetBSD: options.mk,v 1.2 2021/01/19 12:45:56 nia Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.openmw
PKG_SUPPORTED_OPTIONS=		qt5
PKG_SUGGESTED_OPTIONS=		qt5

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gui

.if !empty(PKG_OPTIONS:Mqt5)
PLIST.gui=	yes
CMAKE_ARGS+=	-DDESIRED_QT_VERSION=5
CONF_FILES+=	${EGDIR}/openmw-cs.cfg ${PKG_SYSCONFDIR}/openmw-cs.cfg
.include "../../x11/qt5-qtbase/buildlink3.mk"
.else
CMAKE_ARGS+=	-DBUILD_LAUNCHER=OFF
CMAKE_ARGS+=	-DBUILD_OPENCS=OFF
CMAKE_ARGS+=	-DBUILD_WIZARD=OFF
.endif
