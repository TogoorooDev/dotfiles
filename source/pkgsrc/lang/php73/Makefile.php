# $NetBSD: Makefile.php,v 1.7 2021/01/02 10:04:10 taca Exp $
# used by lang/php73/Makefile
# used by www/ap-php/Makefile
# used by www/php-fpm/Makefile

# segfaults when buidling with many compilers
# https://bugs.php.net/bug.php?id=74527
# https://gcc.gnu.org/bugzilla/show_bug.cgi?id=86236
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ARGS+=	--disable-gcc-global-regs
.endif

# the binary actually needs full dep on PCRE
BUILDLINK_DEPMETHOD.pcre2=	full

USE_LIBTOOL=		YES
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
BUILD_DEFS+=		VARBASE
PLIST_VARS+=		dtrace

.include "../../lang/php73/Makefile.common"

DISTINFO_FILE=	${.CURDIR}/../../lang/php73/distinfo
PATCHDIR=	${.CURDIR}/../../lang/php73/patches

CONFIGURE_ENV+=		EXTENSION_DIR="${PREFIX}/${PHP_EXTENSION_DIR}"

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-config-file-path=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-config-file-scan-dir=${PKG_SYSCONFDIR}/php.d
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

CONFIGURE_ARGS+=	--without-mysqli
CONFIGURE_ARGS+=	--without-iconv
CONFIGURE_ARGS+=	--without-pear
CONFIGURE_ARGS+=	--without-sqlite3
#CONFIGURE_ARGS+=	--without-intl

CONFIGURE_ARGS+=	--disable-posix
CONFIGURE_ARGS+=	--disable-opcache
CONFIGURE_ARGS+=	--disable-pdo
CONFIGURE_ARGS+=	--disable-json

CONFIGURE_ARGS+=	--enable-cgi
CONFIGURE_ARGS+=	--enable-mysqlnd
CONFIGURE_ARGS+=	--enable-xml
CONFIGURE_ARGS+=	--with-libxml-dir=${PREFIX}
.include "../../textproc/libxml2/buildlink3.mk"

CONFIGURE_ARGS+=	--with-pcre-regex=${BUILDLINK_PREFIX.pcre2}
GNU_CONFIGURE_STRICT=	no

.include "options.mk"

DL_AUTO_VARS=		yes
.include "../../mk/dlopen.buildlink3.mk"
