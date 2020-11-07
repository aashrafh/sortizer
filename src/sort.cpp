#include <iostream>
#include <string>
#include <fstream>
#include "./Sortizer.hpp"
#include "./SelectionSort.hpp"
#include "./InsertionSort.hpp"
#include "./MergeSort.hpp"
#include "./QuickSort.hpp"
#include "./HybridSort.hpp"

using std::stoi;
using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;

enum algo {SELECTION_SORT, INSERTION_SORT, MERGE_SORT, QUICK_SORT, HYBRID_SORT};

// File Handling
bool openFile(string filePath, ifstream &file){
    file.open(filePath);
    return !file.fail();
}
bool openFile(string filePath, ofstream &file){
    file.open(filePath);
    return !file.fail();
}
bool validArgs(int argc, char **argv, algo &algoType, ifstream &inputFile, ofstream &outputFile, ofstream &statsFile){
    // Check the number of the args
    if(argc < 5) return false;

    bool valid = true;

    // Check correct algorithm choice
    int algoNumber = stoi(argv[1]);
    if(algoNumber < 0 || algoNumber > 4) valid = false;
    else algoType = static_cast<algo>(algoNumber);

    // Try to open the files
    if(!openFile(argv[2], inputFile)) valid = false;
    if(!openFile(argv[3], outputFile) || !openFile(argv[4], statsFile)) valid = false;
    return valid;
}
void closeFiles(ifstream &inputFile, ofstream &outputFile, ofstream &statsFile){
    inputFile.close();
    outputFile.close();
    statsFile.close();
}
void write(ofstream &outputFile, vector<long long> &list, ofstream &statsFile, double duration){
    for(auto element : list) outputFile<<element<<"\n";     // Write the sorted list
    statsFile<<duration<<"\n";                              // Write the elapsed time
}

// Choose the algorithm
Sortizer* createSortizer(algo algoType){
    Sortizer *sortizer;
    switch (algoType)
    {
    case SELECTION_SORT:
        sortizer = new SelectionSort();
        break;
    case INSERTION_SORT:
        sortizer = new InsertionSort();
        break;
    case MERGE_SORT:
        sortizer = new MergeSort();
        break;
    case QUICK_SORT:
        sortizer = new QuickSort();
        break;
    case HYBRID_SORT:
        sortizer = new HybridSort();
        break;
    
    default:
        sortizer = new MergeSort();
        break;
    }

    return sortizer;
}

// Sort the data
double sort(Sortizer *sortizer,vector<long long> &list){
    double duration = sortizer->sort(list, 0, (int)list.size());
    return duration;
}

int main(int argc, char **argv){

    ifstream inputFile;
    ofstream outputFile, statsFile;
    algo algoType = MERGE_SORT;     // Default algo
    if(!validArgs(argc, argv, algoType, inputFile, outputFile, statsFile)){
        closeFiles(inputFile, outputFile, statsFile);
        return 0;
    }
    
    long long element;
    vector<long long> list;
    while(inputFile >> element){
        list.push_back(element);
    }

    Sortizer *sortizer = createSortizer(algoType);
    double duration = sort(sortizer, list);         // Sort the data and return the elapsed time
    write(outputFile, list, statsFile, duration);

    closeFiles(inputFile, outputFile, statsFile);
    return 0;
}