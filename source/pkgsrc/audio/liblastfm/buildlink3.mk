# $NetBSD: buildlink3.mk,v 1.31 2021/04/29 23:30:13 thor Exp $

BUILDLINK_TREE+=	liblastfm

.if !defined(LIBLASTFM_BUILDLINK3_MK)
LIBLASTFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblastfm+=	liblastfm>=0.3.0
BUILDLINK_ABI_DEPENDS.liblastfm+=	liblastfm>=0.3.3nb28
BUILDLINK_PKGSRCDIR.liblastfm?=		../../audio/liblastfm

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.endif	# LIBLASTFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblastfm
