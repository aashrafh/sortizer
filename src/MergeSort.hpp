#ifndef MERGE_SORT_H
#define MERGE
#include "./Sortizer.hpp"
#include <climits>

using std::numeric_limits;

class MergeSort: public Sortizer
{
private:
    void merge(vector<long long> &list, int left, int mid, int right);
    void mergeSort(vector<long long> &list, int left, int right);
protected:
    void sortUtil(vector<long long> &list, int start, int size);
public:
    MergeSort();
};

MergeSort::MergeSort()
{
}
/*
Stable: Yes
In place: No
Time Complexity: O(nlogn)
Space Complexity: O(n)
Adaptive: No
Important Note: For small n, Insertion sort is better while Merge sort is better for large n
*/
void MergeSort::sortUtil(vector<long long> &list, int start, int size){
    this->mergeSort(list, start, start+size-1);
}
void MergeSort::mergeSort(vector<long long> &list, int left, int right){
    if(left >= right) return; // Base case

    int midIdx = left + (right - left) / 2; // This formula is to avoid overflow
    
    this->mergeSort(list, left, midIdx);    // Sort left half
    this->mergeSort(list, midIdx+1, right); // Sort right half

    this->merge(list, left, midIdx, right); // Merge both left and right halfs
}
void MergeSort::merge(vector<long long> &list, int left, int mid, int right){
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