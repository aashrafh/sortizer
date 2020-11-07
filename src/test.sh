#!/bin/sh
g++ -O2 sort.cpp

if [ ! -d ../input ]
then
    mkdir ../input
fi
if [ ! -d ../sorted ]
then
    mkdir ../sorted
fi
if [ ! -d ../stats ]
then
    mkdir ../stats
fi

for i in 100 1000 5000 10000 50000 75000 100000 500000; do
    python generate.py "$i" "../input/data$i.txt"
done


for filepath in ../input/*.txt; do
    filename=$(basename $filepath .txt)
    for ((i=0; i<=3; i++)); do
        ./a.out "$i" "$filepath" "../sorted/random-$filename-sorted-$i.txt" "../stats/random-$filename-stats-$i.txt"
    done
done