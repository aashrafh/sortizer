#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "./Sortizer.hpp"
#include <random>

class QuickSort: public Sortizer
{
private:
    void quickSort(vector<long long> &list, int start, int end);
    int partition(vector<long long> &list, int start, int end);
    int randomizedPartition(vector<long long> &list, int start, int end);
protected:
    void sortUtil(vector<long long> &list, int start, int size);
public:
    QuickSort();
    ~QuickSort();
};

QuickSort::QuickSort()
{
}
QuickSort::~QuickSort()
{
}
/*
Stable: No
In place: Yes
Time Complexity: O(n^2), but typically O(nlogn)
Space Complexity: O(logn) for stack calls
Adaptive: No
*/
void QuickSort::sortUtil(vector<long long> &list, int start, int size){
    return this->quickSort(list, start, start+size-1);
}
int QuickSort::partition(vector<long long> &list, int start, int end){
    long long pivot = list[end];

    int minIdx = start - 1;
    for(int idx = start; idx <= end-1; idx++){
        if(list[idx] <= pivot){
            minIdx++;
            swap(list[idx], list[minIdx]);
        }
    }
    swap(list[end], list[minIdx+1]);
    return minIdx+1;
}
int QuickSort::randomizedPartition(vector<long long> &list, int start, int end){
    std::random_device randomDevice;                            // Used to seed the inititial value, C++11
    std::default_random_engine generator(randomDevice());       // Generate random number
    std::uniform_int_distribution<int> distribution(start, end);// Produces random integer values, uniformly distributed on the closed interval [start, end]

    int randomIdx = distribution(generator);                    // Get random index to be used as the pivot index
    swap(list[randomIdx], list[end]);                           // Put the pivot in the end of the list

    return this->partition(list, start, end);
}
void QuickSort::quickSort(vector<long long> &list, int start, int end){
    if(start >= end) return;
    int pivot = this->randomizedPartition(list, start, end);
    this->quickSort(list, start, pivot-1);
    this->quickSort(list, pivot+1, end);
}
#endif