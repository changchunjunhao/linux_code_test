#!/bin/bash

for sh_file in $(ls *.sh)
do 
    if [ $sh_file = $0 ];then
	echo the current file $0 is obmit
	continue
    fi
    echo $sh_file
    cat $sh_file
done

exit 0
