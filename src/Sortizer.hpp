#ifndef SORTIZER_H
#define SORTIZER_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <ratio>

using std::vector;
using std::swap;
using namespace std::chrono;

// Algorithm base class
class Sortizer
{
protected:
    virtual void sortUtil(vector<long long> &list, int size) = 0;
public:
    Sortizer();
    double sort(vector<long long> &list);
};

Sortizer::Sortizer()
{
}
double Sortizer::sort(vector<long long> &list){
    // Start the timer
    auto startingTimepoint = high_resolution_clock::now();
    // Call the required sorting algorithm
    this->sortUtil(list, (int)list.size());
    // Endpoint of the timer
    auto endingTimepoint = high_resolution_clock::now();
    // Calculate the duration elapsed in ms
    duration<double, std::milli> elapsedTime = endingTimepoint - startingTimepoint;
    
    return elapsedTime.count();
}
#endif