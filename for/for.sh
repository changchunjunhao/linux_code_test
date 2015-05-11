#!/bin/sh

for foo in "bar fud 43"
do 
    echo $foo
done
exit 0

#"bar fud 43" will be regarded as one string
