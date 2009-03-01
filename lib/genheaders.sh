#!/bin/bash
# A simple script to generate Qt-style header names

find . -name '*.h' | while read header; do
    HEADER_NAME=`echo $header | sed 's|\.h$||'`
    HEADER_BASENAME=`basename $header`
    echo "Generating $HEADER_NAME..."
    echo "#include \"./$HEADER_BASENAME\"" >> $HEADER_NAME
done