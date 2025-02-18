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
void selection_sort(int array[], int arraySize) {
    // Declare Variables
    int temp, minIndex;

    // Sort Algorithm
    for (size_t i = 0; i < arraySize - 1; i++) {
        minIndex = i;
        for (size_t j = i + 1; j < arraySize; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

int main() {
    int arr[] = {9, 5, 2, 7, 1 , 8, 4, 6, 3};
    int size = sizeof(arr) / sizeof(int);

    cout << setw(10) << "Original: ";
    print_array(arr, size);

    selection_sort(arr, size);
    cout << '\n';

    cout << setw(10) << "Sorted: ";
    print_array(arr, size);
    return 0;
}