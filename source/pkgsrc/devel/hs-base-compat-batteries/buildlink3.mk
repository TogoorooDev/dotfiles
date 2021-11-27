# $NetBSD: buildlink3.mk,v 1.3 2021/05/03 19:00:55 pho Exp $

BUILDLINK_TREE+=	hs-base-compat-batteries

.if !defined(HS_BASE_COMPAT_BATTERIES_BUILDLINK3_MK)
HS_BASE_COMPAT_BATTERIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-base-compat-batteries+=	hs-base-compat-batteries>=0.11.2
BUILDLINK_ABI_DEPENDS.hs-base-compat-batteries+=	hs-base-compat-batteries>=0.11.2nb1
BUILDLINK_PKGSRCDIR.hs-base-compat-batteries?=		../../devel/hs-base-compat-batteries

.include "../../devel/hs-base-compat/buildlink3.mk"
.endif	# HS_BASE_COMPAT_BATTERIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-base-compat-batteries
