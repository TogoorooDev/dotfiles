# $NetBSD: buildlink3.mk,v 1.46 2021/04/09 05:12:58 adam Exp $

BUILDLINK_TREE+=	gegl

.if !defined(GEGL_BUILDLINK3_MK)
GEGL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gegl+=	gegl>=0.3.0
BUILDLINK_ABI_DEPENDS.gegl+=	gegl>=0.4.26nb1
BUILDLINK_PKGSRCDIR.gegl?=	../../graphics/gegl

.include "../../graphics/babl/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.endif # GEGL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gegl
