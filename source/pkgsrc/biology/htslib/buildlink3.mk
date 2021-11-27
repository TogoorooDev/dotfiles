# $NetBSD: buildlink3.mk,v 1.5 2021/03/20 18:17:07 bacon Exp $

BUILDLINK_TREE+=	htslib

.if !defined(HTSLIB_BUILDLINK3_MK)
HTSLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.htslib+=	htslib>=1.10.2
BUILDLINK_ABI_DEPENDS.htslib+=	htslib>=1.10.2
BUILDLINK_PKGSRCDIR.htslib?=	../../biology/htslib

.endif	# HTSLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-htslib
