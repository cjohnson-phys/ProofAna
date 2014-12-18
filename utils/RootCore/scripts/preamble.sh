test "x$ROOTCOREDIR" = "x" && echo "ROOTCOREDIR not set, please source setup.[c]sh" && exit 1
test "x$ROOTCOREBIN" = "x" && echo "ROOTCOREBIN not set, please source setup.[c]sh" && exit 1

pkgfile=$ROOTCOREBIN/packages

script=`basename $1`
if test \! -f "$pkgfile"
then
    if test "$script" != "find_packages.sh" -a "$script" != "checkout.sh" -a "$script" != "checkout_pkg.sh" -a "$script" != "update.sh" -a "$script" != "manage_all.sh" -a "$script" != "manage_pkg.sh"
    then
	echo "did not find package list, please run"
	echo "  rc find_packages"
	echo "at the base of your source directory"
	exit 100
    fi
fi
