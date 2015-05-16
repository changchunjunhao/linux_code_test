#!/bin/sh

function int_action()
{
    echo we are interupt. haha...
    rm -f *.tmp
}

# trap 'int_action' INT
trap "echo we are interupt.; rm -f *.tmp" INT	       
echo create file Leteno.tmp
date > Leteno.tmp

while [ -f *.tmp ]; do
    echo tmp file exists
    sleep 1
done
echo the tmp files are delete
trap INT
echo we are outside
