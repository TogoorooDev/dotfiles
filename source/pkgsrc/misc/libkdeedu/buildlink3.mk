# $NetBSD: buildlink3.mk,v 1.47 2021/04/21 13:24:12 adam Exp $

BUILDLINK_TREE+=	libkdeedu

.if !defined(LIBKDEEDU_BUILDLINK3_MK)
LIBKDEEDU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdeedu+=	libkdeedu>=4.8.0
BUILDLINK_ABI_DEPENDS.libkdeedu?=	libkdeedu>=4.14.3nb27
BUILDLINK_PKGSRCDIR.libkdeedu?=		../../misc/libkdeedu

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBKDEEDU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdeedu
