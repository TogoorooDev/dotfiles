# $NetBSD: buildlink3.mk,v 1.5 2021/04/21 11:40:23 adam Exp $

BUILDLINK_TREE+=	libgeotiff

.if !defined(LIBGEOTIFF_BUILDLINK3_MK)
LIBGEOTIFF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgeotiff+=	libgeotiff>=1.5.1
BUILDLINK_ABI_DEPENDS.libgeotiff?=	libgeotiff>=1.6.0nb3
BUILDLINK_PKGSRCDIR.libgeotiff?=	../../geography/libgeotiff

.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.endif	# LIBGEOTIFF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgeotiff
