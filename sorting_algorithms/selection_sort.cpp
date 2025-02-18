#include <algorithm>
#include <iomanip>
#include <iostream>
#include "print_array.h"
using namespace std;
/*
SELECTION SORT [Not Stable | O(n²)]
* Finds the smallest element and swaps it with the first unsorted element
* Repeats until the array is fully sorted
* Use Case: When swaps are expensive(takes too much time), small datasets, when memory writes are costly
*/
void selection_sort(int arr[], size_t size) {
    size_t min_index;

    for (size_t i = 0; i < size - 1; ++i) {
        min_index = i;
        for (size_t j = i + 1; j < size; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

int main() {
    int arr[] = {9, 5, 2, 7, 1 , 8, 4, 6, 3};
    size_t size = sizeof(arr) / sizeof(int);

    cout << setw(10) << "Original: ";
    print_array(arr, size);

    selection_sort(arr, size);
    cout << '\n';

    cout << setw(10) << "Sorted: ";
    print_array(arr, size);
    return 0;
}