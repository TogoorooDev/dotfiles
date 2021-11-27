# $NetBSD: buildlink3.mk,v 1.11 2021/07/01 06:13:45 nia Exp $

BUILDLINK_TREE+=	py-numpy

.if !defined(PY_NUMPY_BUILDLINK3_MK)
PY_NUMPY_BUILDLINK3_MK:=

PYTHON_VERSIONS_INCOMPATIBLE+=		36

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-numpy+=	${PYPKGPREFIX}-numpy>=1.0
.if ${_PYTHON_VERSION} == 27
BUILDLINK_ABI_DEPENDS.py-numpy?=	${PYPKGPREFIX}-numpy>=1.16.6nb3
BUILDLINK_PKGSRCDIR.py-numpy?=		../../math/py-numpy16
.else
BUILDLINK_ABI_DEPENDS.py-numpy?=	${PYPKGPREFIX}-numpy>=1.20.3nb1
BUILDLINK_PKGSRCDIR.py-numpy?=		../../math/py-numpy
.endif

.include "../../mk/bsd.fast.prefs.mk"

.include "../../math/py-numpy/Makefile.make_env"

# Mimick the choice from Makefile. Or better store/load build choice?
BLAS_ACCEPTED=		${_BLAS_TYPES} accelerate.framework
BLAS_C_INTERFACE=	yes
CPPFLAGS+=		${BLAS_INCLUDES}
.include "../../mk/blas.buildlink3.mk"

.endif # PY_NUMPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-numpy
