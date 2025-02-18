#include <algorithm>
#include <iomanip>
#include <iostream>
#include "print_array.h"
using namespace std;
/*
BUBBLE SORT [ Stable | O(n²) ]
* Repeatedly swaps adjacent elements in the wrong order
* Moves largest element to its correct position in each pass
* Use Case: Small datasets, learning purposes
*/
void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {9, 5, 2, 7, 1 , 8, 4, 6, 3};
    int size = sizeof(arr) / sizeof(int);

    cout << setw(10) << "Original: ";
    print_array(arr, size);

    bubble_sort(arr, size);
    cout << '\n';

    cout << setw(10) << "Sorted: ";
    print_array(arr, size);
    return 0;
}