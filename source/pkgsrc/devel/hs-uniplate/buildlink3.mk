# $NetBSD: buildlink3.mk,v 1.12 2021/05/03 19:01:05 pho Exp $

BUILDLINK_TREE+=	hs-uniplate

.if !defined(HS_UNIPLATE_BUILDLINK3_MK)
HS_UNIPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-uniplate+=	hs-uniplate>=1.6.13
BUILDLINK_ABI_DEPENDS.hs-uniplate+=	hs-uniplate>=1.6.13nb1
BUILDLINK_PKGSRCDIR.hs-uniplate?=	../../devel/hs-uniplate

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.endif	# HS_UNIPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-uniplate
