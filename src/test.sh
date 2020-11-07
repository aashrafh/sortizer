#!/bin/sh
g++ -O2 sort.cpp

if [ -d ../random ]
then
    rm -r ../random
fi
if [ -d ../sorted ]
then
    rm -r ../sorted
fi
mkdir ../random ../sorted
mkdir ../random/input ../random/output ../random/stats
mkdir ../sorted/input ../sorted/output ../sorted/stats

for i in 100 1000 5000 10000 50000 75000 100000 500000; do
    python generate.py "$i" "../random/input/data$i.txt"
done


for filepath in ../random/input/*.txt; do
    filename=$(basename $filepath .txt)
    for ((i=0; i<=3; i++)); do
        ./a.out "$i" "$filepath" "../random/output/random-$filename-sorted-$i.txt" "../random/stats/random-$filename-stats-$i.txt"
    done
    cp ../random/output/random-$filename-sorted-1.txt ../sorted/input/
done

for filepath in ../sorted/input/*.txt; do
    filename=$(basename $filepath .txt)
    for ((i=0; i<=3; i++)); do
        ./a.out "$i" "$filepath" "../sorted/output/random-$filename-sorted-$i.txt" "../sorted/stats/random-$filename-stats-$i.txt"
    done
done