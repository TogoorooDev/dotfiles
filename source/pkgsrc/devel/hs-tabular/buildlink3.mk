# $NetBSD: buildlink3.mk,v 1.4 2021/05/04 14:37:33 pho Exp $

BUILDLINK_TREE+=	hs-tabular

.if !defined(HS_TABULAR_BUILDLINK3_MK)
HS_TABULAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-tabular+=	hs-tabular>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-tabular+=	hs-tabular>=0.2.2.8nb1
BUILDLINK_PKGSRCDIR.hs-tabular?=	../../devel/hs-tabular

.include "../../textproc/hs-csv/buildlink3.mk"
.include "../../textproc/hs-html/buildlink3.mk"
.endif	# HS_TABULAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-tabular
