# $NetBSD: buildlink3.mk,v 1.56 2021/05/27 17:02:24 nia Exp $

BUILDLINK_TREE+=	boost-libs

.if !defined(BOOST_LIBS_BUILDLINK3_MK)
BOOST_LIBS_BUILDLINK3_MK:=

# Use a dependency pattern that guarantees the proper ABI.
BUILDLINK_API_DEPENDS.boost-libs+=	boost-libs-1.76.*
BUILDLINK_PKGSRCDIR.boost-libs?=	../../devel/boost-libs

.include "../../mk/bsd.fast.prefs.mk"
# Sync with meta-pkgs/boost/Makefile.common
# libstdc++5 is required to build "math" and "nowide".
GCC_REQD+=		5

.include "../../devel/boost-headers/buildlink3.mk"
.endif # BOOST_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-boost-libs
