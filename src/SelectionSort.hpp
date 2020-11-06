#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H
#include "./Sortizer.hpp"
class SelectionSort: public Sortizer
{
protected:
    void sortUtil(vector<long long> &list, int size);
public:
    SelectionSort();
};

SelectionSort::SelectionSort()
{
}
/*
Stable: No
In place: Yes
Time Complexity: O(n^2)
Space Complexity: O(1)
Adaptive: No but it has the property of minimizing the number of swaps to O(n) swaps
*/
void SelectionSort::sortUtil(vector<long long> &list, int size){
    for(int idx = 0; idx < size - 1; idx++){
        int minElmIdx = idx, // Guess that the current element is the minimum one
        it = idx+1;          // Start iterating over the rest elements in the list and
        while(it < size){    // Get the minimum one
            if(list[it] < list[minElmIdx]){
                minElmIdx = it;
            }
            it++;
        }
        swap(list[idx], list[minElmIdx]); // Put the current minimum element in the correct position
    }    
}
#endif