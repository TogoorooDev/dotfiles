# $NetBSD: buildlink3.mk,v 1.25 2020/08/17 20:17:29 leot Exp $

BUILDLINK_TREE+=	gdchart

.if !defined(GDCHART_BUILDLINK3_MK)
GDCHART_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gdchart+=	gdchart>=0.11.4nb1
BUILDLINK_ABI_DEPENDS.gdchart+=	gdchart>=0.11.5nb20
BUILDLINK_PKGSRCDIR.gdchart?=	../../graphics/gdchart

.include "../../graphics/gd/buildlink3.mk"
.endif # GDCHART_BUILDLINK3_MK

BUILDLINK_TREE+=	-gdchart
