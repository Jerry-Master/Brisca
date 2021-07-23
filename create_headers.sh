#!/usr/bin/bash
export HEADER=lib/all_headers.hh; 
echo "#ifndef __ALL_HEADERS__" > $HEADER; 
echo "#define __ALL_HEADERS__" >> $HEADER; 
for file in lib/*.hh; do 
    if [ "$file" != "lib/all_headers.hh" ]
    then
        echo "#include \"$(echo $file | cut -d'/' -f 2)\"" >> $HEADER; 
    fi
done 
echo "#endif" >> $HEADER; 