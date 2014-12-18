#!/bin/zsh
# create a tar archive

# deduce version automatically from the appropriate include file
version=`date "+%Y-%m-%d"`

origdir=`pwd | sed 's/.*\///'`
echo "Will make an archive of $origdir/"
dirhere=FlavKtPlugin
dirtar=FlavKtPlugin-$version
tarname=$dirtar.tgz
tmptarname=tmp-$tarname

# make sure we have Makefile with use CGAL=no

if [[ -e ../$tarname ]]
then
  echo "Tarfile $tarname already exists. Not proceeding."
elif [[ -e /tmp/$dirtar ]]
then
  echo "/tmp/$dirtar already exists, not proceeding"
else
  pushd ..

  echo "Creating tmp-$tarname"
  tar --exclude '.svn*' --exclude '*~' -zchf $tmptarname \
                      $dirhere/**/*.(f90|f|h|hh|alg|c|cc|C|eps|cpp|gp|dat) \
                      $dirhere/**/Makefile \
                      $dirhere/**/(README|AUTHORS|INSTALL|ChangeLog|Doxyfile|NEWS|COPYING|mkmk|configure|Makefile) \
                      $dirhere/tarit.sh \

  fulltarloc=`pwd`
  pushd /tmp
  echo "Unpacking it as /tmp/$dirhere"
  tar zxf $fulltarloc/$tmptarname
  mv -v /tmp/$dirhere /tmp/$dirtar
  echo "Repacking it with directory name $dirtar"
  tar zcvf $fulltarloc/$tarname $dirtar
  echo 
  echo "Removing /tmp/$dirhere"
  rm -rf $dirtar
  popd
  rm -v $tmptarname

  echo ""
    # if it's gavin running this then automatically copy the tarfile
    # to the web-space
  # webdir=~salam/www/repository/software/fastjet/
  # if [[ $USER = salam && -e $webdir ]]
  #     then
  #     echo "Copying .tgz file to web-site"
  #     cp -vp $tarname $webdir
  #     echo "************   Remember to edit web page **********"
  # fi

  popd 
  echo Produced the following tarball:
  ls -l ../$tarname
  echo

  # reminders about what to do for svn
  URL=`svn info | grep URL | sed 's/^.*URL: //'`
  tagURL=`echo $URL | sed "s/trunk.*/tags\/$dirtar/"`
  echo "Remember to tag the version:"
  echo "svn copy  -m 'tagged release of release $version' $URL $tagURL"
  #echo "Copy it to hepforge:"
  #echo "scp -p $fulltarloc/$tarname hepforge:hoppet/public_html/downloads/"
fi

#tar zcf $tarname


