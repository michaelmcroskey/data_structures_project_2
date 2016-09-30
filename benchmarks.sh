#!/bin/bash

for mode in stl qsort merge quick;
do
echo ' '
echo $mode
num=1
    for i in `seq 1 7`;
    do
        num=$(($num * 10))
        echo $num
        ./measure ./lsort -m $mode -n < <(gshuf -i 1-$num -n $num -r)>/dev/null
    done
done
