#!/usr/bin/env bash

./$1 < $2 > output
H1=`md5sum output`
H2=`md5sum $3`
if !(cmp -s "output" $3)
then 
    echo "Failed!"
    echo "Input: "
    cat input
    echo "Expected Output: "
    cat $3
    echo "Received Output: "
    cat output
    exit
fi
echo "Passed!"
