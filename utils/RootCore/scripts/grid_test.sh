#!/bin/bash

set -e
set -u

test \! -z "${ROOTCOREDIR:+x}" && source $ROOTCOREDIR/scripts/unsetup.sh

cmd_submit=grid_submit.sh
cmd_compile=grid_compile.sh
cmd_run=grid_run.sh
noclean=0
while true
do
    if test "$1" == "--nobuild"
    then
	cmd_submit=grid_submit_nobuild.sh
	cmd_compile=""
	cmd_run=grid_run_nobuild.sh
	shift
    elif test "$1" == "--nocompile"
    then
	cmd_submit=grid_submit_nobuild.sh
	cmd_compile=grid_compile_nobuild.sh
	cmd_run=grid_run_nobuild.sh
	shift
    elif test "$1" == "--noclean"
    then
	noclean=1
	shift
    else
	break
    fi
done

test \! -f "$1/scripts/setup.sh" && echo rootcore not found at $1 && exit 1
test -z "${2:+x}" && echo no space to run specified && exit 3

dir_submit="$2/grid_submit"
dir_compile="$2/grid_compile"
dir_run="$2/grid_run"
for dir in "$dir_submit" "$dir_compile" "$dir_run"
do
    test -e $dir && echo please remove $dir && echo \ \ rm -rf $dir && exit 4
done

if test \! -z "${3:+x}"
then
    script_dir=`dirname $3`
    script_dir=`(cd $script_dir && pwd)`
    script_file=$script_dir/`basename $3`
else
    script_file="rc test_ut"
fi

echo running test submission
(source $1/scripts/setup.sh && \
    "$ROOTCOREDIR/scripts/"$cmd_submit "$dir_submit")

mv "$dir_submit" "$dir_compile"

echo running test compile
if test \! -z "${cmd_compile:+x}"
then
    (source "$dir_compile/RootCore/scripts/"$cmd_compile "$dir_compile")
fi

mv "$dir_compile" "$dir_run"

echo running test run
(source "$dir_run/RootCore/scripts/"$cmd_run "$dir_run" && \
    rm -f $ROOTCOREBIN/load_packages_success && \
    $script_file && \
    root -l -b -q $ROOTCOREDIR/scripts/load_packages.C && \
    test -f $ROOTCOREBIN/load_packages_success && \
    test -f $ROOTCOREBIN/bin/rc)

if test $noclean -eq 0
then
    rm -rf "$dir_run"
fi

echo it appears this RootCore installation is grid compatible
