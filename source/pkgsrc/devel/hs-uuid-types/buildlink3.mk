# $NetBSD: buildlink3.mk,v 1.5 2021/05/03 19:01:05 pho Exp $

BUILDLINK_TREE+=	hs-uuid-types

.if !defined(HS_UUID_TYPES_BUILDLINK3_MK)
HS_UUID_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-uuid-types+=	hs-uuid-types>=1.0.4
BUILDLINK_ABI_DEPENDS.hs-uuid-types+=	hs-uuid-types>=1.0.4nb1
BUILDLINK_PKGSRCDIR.hs-uuid-types?=	../../devel/hs-uuid-types

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.endif	# HS_UUID_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-uuid-types
