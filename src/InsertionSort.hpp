#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H
#include "./Sortizer.hpp"
class InsertionSort: public Sortizer
{
protected:
    void sortUtil(vector<long long> &list, int start, int size);
public:
    InsertionSort();
};

InsertionSort::InsertionSort()
{
}
/*
Stable: Yes
In place: Yes
Time Complexity: O(n^2)
Space Complexity: O(1)
Adaptive: Yes. O(n) time when nearly sorted
*/
void InsertionSort::sortUtil(vector<long long> &list, int start, int size){
    for(int idx = start+1; idx < size; idx++){
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
#endif