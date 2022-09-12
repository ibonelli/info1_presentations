# Originally from https://stackoverflow.com/questions/13433903/convert-all-linux-man-pages-to-text-html-or-markdown

# First we need to install the tool
#sudo apt-get install groff

OUT_DIR=./man2html
mkdir -p $OUT_DIR

# v1
#
#MAN_DIR=/usr/share/man/
#
#for i in `find -name '*.gz'`; do 
#    dname=`dirname $i`
#    mkdir -p $OUT_DIR/$dname
#    zcat $i | groff -mandoc -Thtml > $OUT_DIR/$i.html
#done

#v2

man -k '' | while read sLine; do
    declare sName=$(echo $sLine | cut -d' ' -f1)
    declare sSection=$(echo $sLine | cut -d')' -f1|cut -d'(' -f2)
    mkdir -p ${OUT_DIR}/${sSection}
    echo "converting ${sName}(${sSection}) to ${sName}.${sSection}.html ..."
    man -Thtml ${sSection} ${sName} > $OUT_DIR/${sSection}/${sName}.html
done
