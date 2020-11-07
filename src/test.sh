#!/bin/sh
g++ -O2 sort.cpp

if [ ! -d ../sorted ]
then
    mkdir ../sorted
fi
if [ ! -d ../stats ]
then
    mkdir ../stats
fi

for filepath in ../input/*.txt; do
    filename=$(basename $filepath .txt)
    # echo $filepath
    # ./a.out 0 "$filepath" "../sorted/random-$filename-sorted-0.txt" "../stats/random-$filename-stats-0.txt"
    #0 "./input/data1000.txt" "../sorted/random-data1000-sorted-0.txt" "../stats/random-data1000-stats-0.txt"
    # echo "$filename"\
    # echo $filepath
    for ((i=0; i<=3; i++)); do
        ./a.out "$i" "$filepath" "../sorted/random-$filename-sorted-$i.txt" "../stats/random-$filename-stats-$i.txt"
        # echo "../sorted/random-$filename-stats-$i.txt"
    done
done