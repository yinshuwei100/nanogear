#!/bin/bash
# A simple script to generate Qt-style header names
# NOTE: It will generate Qt-style headers only for documented classes!
#   (documented classes must have the \class doxygen attribute set)

find . -name '*.h' | while read header; do
    HEADER_BASENAME=$(basename $header)
    HEADER_BASEDIR=$(dirname $header)
    HEADER_NAME=$(cat $header | perl -ne 'print "$1\n" if $_ =~ m/\\class\s+(.*)$/')
    
    if [ "$HEADER_NAME" != "" ]; then
        echo "Generating $HEADER_NAME..."
        echo "#include \"$HEADER_BASENAME\"" > $HEADER_BASEDIR/$HEADER_NAME
    fi
done