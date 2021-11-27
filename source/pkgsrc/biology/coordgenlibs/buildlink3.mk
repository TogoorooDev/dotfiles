# $NetBSD: buildlink3.mk,v 1.3 2021/04/21 13:24:06 adam Exp $

BUILDLINK_TREE+=	coordgenlibs

.if !defined(COORDGENLIBS_BUILDLINK3_MK)
COORDGENLIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.coordgenlibs+=	coordgenlibs>=1.4.2
BUILDLINK_ABI_DEPENDS.coordgenlibs?=	coordgenlibs>=1.4.2nb2
BUILDLINK_PKGSRCDIR.coordgenlibs?=	../../biology/coordgenlibs

.include "../../biology/maeparser/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.endif	# COORDGENLIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-coordgenlibs
