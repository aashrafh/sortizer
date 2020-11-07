#ifndef QUICK_SORT_H
#define QUICK_SORT_H
#include "./Sortizer.hpp"
#include <random>

class QuickSort: public Sortizer
{
private:
    void quickSort(vector<long long> &list, int left, int right);
    int partition(vector<long long> &list, int left, int right);
    int randomizedPartition(vector<long long> &list, int left, int right);
protected:
    void sortUtil(vector<long long> &list, int left, int size);
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
void QuickSort::sortUtil(vector<long long> &list, int left, int size){
    return this->quickSort(list, left, left+size-1);
}
int QuickSort::partition(vector<long long> &list, int left, int right){
    long long pivot = list[right];

    int minIdx = left - 1;
    for(int idx = left; idx <= right-1; idx++){
        if(list[idx] <= pivot){
            minIdx++;
            swap(list[idx], list[minIdx]);
        }
    }
    swap(list[right], list[minIdx+1]);
    return minIdx+1;
}
int QuickSort::randomizedPartition(vector<long long> &list, int left, int right){
    std::random_device randomDevice;                            // Used to seed the inititial value, C++11
    std::default_random_engine generator(randomDevice());       // Generate random number
    std::uniform_int_distribution<int> distribution(left, right);// Produces random integer values, uniformly distributed on the closed interval [left, right]

    int randomIdx = distribution(generator);                    // Get random index to be used as the pivot index
    swap(list[randomIdx], list[right]);                           // Put the pivot in the right of the list

    return this->partition(list, left, right);
}
void QuickSort::quickSort(vector<long long> &list, int left, int right){
    if(left >= right) return;
    int pivot = this->randomizedPartition(list, left, right);
    this->quickSort(list, left, pivot-1);
    this->quickSort(list, pivot+1, right);
}
#endif