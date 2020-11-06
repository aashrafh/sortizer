#include <iostream>
#include <string>
#include <fstream>
#include "./Sortizer.hpp"
#include "./SelectionSort.hpp"
#include "./InsertionSort.hpp"
#include "./MergeSort.hpp"

using std::string;
using std::ifstream;
using std::ofstream;

void sort(Sortizer *sortizer,vector<long long> &list){
    double duration = sortizer->sort(list, 0, (int)list.size());
    std::cout<<"Time: "<<duration<<"ms \n";
}

int main(int argc, char **argv){
    string algorithmNumber = argv[1];
    string inputPath = argv[2];
    string outputPath = argv[3];
    string statsPath = argv[4];

    ifstream inputList;
    inputList.open(inputPath, std::ifstream::in);
    long long element;
    vector<long long> list;
    while(inputList >> element){
        list.push_back(element);
    }

    // SelectionSort selectionSort;
    // sort(&selectionSort, list);

    Sortizer *sortizer = new MergeSort();
    sort(sortizer, list);

    ofstream outputFile;
    outputFile.open(outputPath);
    for(int i=0; i<(int)list.size(); i++) outputFile<<list[i]<<"\n";

    inputList.close(); outputFile.close();
    return 0;
}