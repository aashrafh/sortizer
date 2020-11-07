#ifndef HYBRID_SORT_H
#define HYBRID_SORT_H
#include "./Sortizer.hpp"
#include "./MergeSort.hpp"
#include "./InsertionSort.hpp"
#include <random>
class HybridSort: public Sortizer
{
private:
    void insertionSort(vector<long long> &list, int left, int size);
    void merge(vector<long long> &list, int left, int mid, int right);
    void hybridSort(vector<long long> &list, int left, int right);
    void hybridSort2(vector<long long> &list, int left, int right);
    int partition(vector<long long> &list, int left, int right);
    int randomizedPartition(vector<long long> &list, int left, int right);
protected:
    void sortUtil(vector<long long> &list, int left, int size);
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
void HybridSort::sortUtil(vector<long long> &list, int left, int size){
    this->hybridSort(list, left, left+size-1);
}
void HybridSort::hybridSort(vector<long long> &list, int left, int right){
    if(left >= right) return;               // Base case
    if(right-left+1 <= 32){                 // Insertion sort is better for smaller sets of data
        this->insertionSort(list, left, right);
        return;
    }

    int midIdx = left + (right - left) / 2; // This formula is to avoid overflow
    
    this->hybridSort(list, left, midIdx);    // Sort left half
    this->hybridSort(list, midIdx+1, right); // Sort right half

    this->merge(list, left, midIdx, right); // Merge both left and right halfs
}
void HybridSort::insertionSort(vector<long long> &list, int left, int right){
    for(int idx = left+1; idx <= right; idx++){
        long long key = list[idx];
        // Insert list[idx] into the sorted sequence list[0..idx-1]
        int it = idx-1;
        while(it >= 0 && list[it] > key){
            list[it+1] = list[it];
            it--;
        }
        list[it+1] = key;
    }
}
void HybridSort::merge(vector<long long> &list, int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    vector<long long> leftHalf(leftSize+1), rightHalf(rightSize+1);

    for(int idx=0; idx<leftSize; idx++) leftHalf[idx] = list[left+idx];
    for(int idx=0; idx<rightSize; idx++) rightHalf[idx] = list[mid+idx+1];
    // To avoid extra checks in the merge loop
    leftHalf[leftSize] = LLONG_MAX;
    rightHalf[rightSize] = LLONG_MAX;

    int leftIt = 0;
    int rightIt = 0;
    for(int idx=left; idx<=right; idx++){
        if(leftHalf[leftIt] <= rightHalf[rightIt]){ // Less than or equal so it can be stable
            list[idx] = leftHalf[leftIt];
            leftIt++;
        }
        else {
            list[idx] = rightHalf[rightIt];
            rightIt++;
        }
    }
}
#endif