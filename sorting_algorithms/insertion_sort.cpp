#include <iomanip>
#include <iostream>
#include "print_array.h"
using namespace std;
/*
INSERTION SORT [ Stable | O(n²) ]
* Builds the sorted list one element at a time
* Inserts each new element into its correct position
* Use Case: Nearly sorted lists, small datasets, adaptive sorting(performs better as data is nearly sorted)
 * Visualization:
 * j i _ _ _
 */
void insertion_sort(int arr[], size_t size) {
    size_t current;

    for (size_t i = 1; i < size; ++i) {
        current = arr[i];
        size_t j = i - 1;

        while (j < size && current < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = current;
    }
}

int main() {
    int arr[] = {9, 5, 2, 7, 1 , 8, 4, 6, 3};
    size_t size = sizeof(arr) / sizeof(int);

    cout << setw(10) << "Original: ";
    print_array(arr, size);

    insertion_sort(arr, size);
    cout << '\n';

    cout << setw(10) << "Sorted: ";
    print_array(arr, size);
    return 0;
}