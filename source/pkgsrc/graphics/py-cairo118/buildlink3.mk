# $NetBSD: buildlink3.mk,v 1.1 2020/09/03 15:44:06 wiz Exp $

BUILDLINK_TREE+=	py-cairo

.if !defined(PY_CAIRO_BUILDLINK3_MK)
PY_CAIRO_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-cairo+=	${PYPKGPREFIX}-cairo>=1.10.0
BUILDLINK_ABI_DEPENDS.py-cairo?=	${PYPKGPREFIX}-cairo>=1.18.2nb1
BUILDLINK_PKGSRCDIR.py-cairo?=		../../graphics/py-cairo

.include "../../graphics/cairo/buildlink3.mk"
.endif	# PY_CAIRO_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-cairo
