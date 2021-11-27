# $NetBSD: buildlink3.mk,v 1.1 2021/06/14 16:51:39 gdt Exp $

BUILDLINK_TREE+=	SOPE

.if !defined(SOPE_BUILDLINK3_MK)
SOPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SOPE+=	SOPE>=5.1.1
BUILDLINK_PKGSRCDIR.SOPE?=	../../devel/SOPE5
.endif # SOPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-SOPE