# $NetBSD: buildlink3.mk,v 1.22 2021/06/16 10:33:51 markd Exp $

BUILDLINK_TREE+=	kconfig

.if !defined(KCONFIG_BUILDLINK3_MK)
KCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kconfig+=	kconfig>=5.18.0
BUILDLINK_ABI_DEPENDS.kconfig?=	kconfig>=5.80.0nb1
BUILDLINK_PKGSRCDIR.kconfig?=	../../devel/kconfig

BUILDLINK_FILES.kconfig+=	libexec/kf5/*

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-kconfig
