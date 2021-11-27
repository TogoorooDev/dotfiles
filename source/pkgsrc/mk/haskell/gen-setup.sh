# $NetBSD: gen-setup.sh,v 1.1 2021/05/01 15:06:26 pho Exp $
#
# Generate the standard Setup.hs script for a given Cabal package.
#
: ${AWK=awk}

# Usage: $0 BUILD-TYPE
case "$1" in
    simple)
        echo 'import Distribution.Simple'
        echo 'main = defaultMain'
        ;;
    configure)
        echo 'import Distribution.Simple'
        echo 'main = defaultMainWithHooks autoconfUserHooks'
        ;;
    make)
        echo 'import Distribution.Make'
        echo 'main = defaultMain'
        ;;
    *)
        echo >&2 "Unknown Build-Type: $1"
        exit 1
esac
