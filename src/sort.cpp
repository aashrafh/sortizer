#include <iostream>
#include <string>
#include <fstream>
#include "./Sortizer.hpp"
#include "./SelectionSort.hpp"
#include "./InsertionSort.hpp"
#include "./MergeSort.hpp"
#include "./QuickSort.hpp"

using std::stoi;
using std::string;
using std::ifstream;
using std::ofstream;

bool openFile(string filePath, ifstream &file){
    file.open(filePath);
    return !file.fail();
}
bool openFile(string filePath, ofstream &file){
    file.open(filePath);
    return !file.fail();
}
bool validArgs(int argc, char **argv, int &algoNumber, ifstream &inputFile, ofstream &outputFile, ofstream &statsFile){
    // Check the number of the args
    if(argc < 5) return false;

    bool valid = true;

    // Check correct algorithm choice
    algoNumber = stoi(argv[1]);
    if(algoNumber < 0 || algoNumber > 4) valid = false;

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
void sort(Sortizer *sortizer,vector<long long> &list){
    double duration = sortizer->sort(list, 0, (int)list.size());
    std::cout<<"Time: "<<duration<<"ms \n";
}

int main(int argc, char **argv){

    ifstream inputFile;
    ofstream outputFile, statsFile;
    int algoNumber;
    if(!validArgs(argc, argv, algoNumber, inputFile, outputFile, statsFile)){
        closeFiles(inputFile, outputFile, statsFile);
        return 0;
    }
    
    long long element;
    vector<long long> list;
    while(inputFile >> element){
        list.push_back(element);
    }

    // SelectionSort selectionSort;
    // sort(&selectionSort, list);

    Sortizer *sortizer = new QuickSort();
    sort(sortizer, list);

    closeFiles(inputFile, outputFile, statsFile);
    return 0;
}