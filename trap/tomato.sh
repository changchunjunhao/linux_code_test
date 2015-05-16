#!/bin/bash

# this is tomato method

if [ "$#" != "1" ];then
    printf 'the number of param should be 1\n'
    exit 0
fi

if [[ "$1" =~ ^[0-9]*$ ]]; then
    #printf '$1 is num %d\n' $1
    :
else
    printf '%s is not a num\n' $1
    exit 1
fi


function reset()
{
    trap INT
}

function interupt_method()
{
    printf "\ninterupt\n"
    read -p 'enter q to exit tomato method, any other key continue: ' answer
    if [ "$answer" = "q" ]; then
	reset
	printf 'close tomato\n'
	exit 0
    fi
    printf '----------------\ncontinue\n---------------'
}


trap "interupt_method" INT

count=1
while [ $count -lt $1 ]
do
    echo tomato $count
    sleep 1
    count=$((count+1))
done

printf 'done'

exit 0
