#ifndef HYBRID_SORT_H
#define HYBRID_SORT_H
#include "./Sortizer.hpp"
#include "./MergeSort.hpp"
#include "./InsertionSort.hpp"
class HybridSort: public InsertionSort, public MergeSort
{
private:
    void hybridSort(vector<long long> &list, int left, int right);
protected:
    void sortUtil(vector<long long> &list, int start, int size);
public:
    HybridSort();
    ~HybridSort();
};

HybridSort::HybridSort()
{
}
HybridSort::~HybridSort()
{
}
void HybridSort::sortUtil(vector<long long> &list, int start, int size){
    this->hybridSort(list, start, start+size-1);
}
void HybridSort::hybridSort(vector<long long> &list, int left, int right){
    if(left >= right) return;               // Base case

    int midIdx = left + (right - left) / 2; // This formula is to avoid overflow
    
    this->hybridSort(list, left, midIdx);    // Sort left half
    this->hybridSort(list, midIdx+1, right); // Sort right half

    this->merge(list, left, midIdx, right); // Merge both left and right halfs
}
#endif