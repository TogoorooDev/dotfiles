# $NetBSD: buildlink3.mk,v 1.4 2021/05/03 19:01:05 pho Exp $

BUILDLINK_TREE+=	hs-unliftio-core

.if !defined(HS_UNLIFTIO_CORE_BUILDLINK3_MK)
HS_UNLIFTIO_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unliftio-core+=	hs-unliftio-core>=0.2.0.1
BUILDLINK_ABI_DEPENDS.hs-unliftio-core+=	hs-unliftio-core>=0.2.0.1nb1
BUILDLINK_PKGSRCDIR.hs-unliftio-core?=		../../devel/hs-unliftio-core
.endif	# HS_UNLIFTIO_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unliftio-core
