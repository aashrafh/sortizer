#ifndef SORTIZER_H
#define SORTIZER_H
#include <iostream>
#include <vector>
#include <chrono>

using std::vector;
using namespace std::chrono;

// Algorithm base class
class Sortizer
{
private:
    virtual void sortUtil(vector<long long int> &list) = 0;
public:
    Sortizer();
    milliseconds sort(vector<long long int> &list);
};

Sortizer::Sortizer()
{
}
milliseconds Sortizer::sort(vector<long long int> &list){
    // Start the timer
    auto startingTimepoint = high_resolution_clock::now();
    // Call the required sorting algorithm
    this->sortUtil(list);
    // Endpoint of the timer
    auto endingTimepoint = high_resolution_clock::now();
    // Calculate the duration elapsed in ms
    auto duration = duration_cast<milliseconds>(endingTimepoint - startingTimepoint);
    
    return duration;
}
#endif