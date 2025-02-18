#include <iomanip>
#include <iostream>
#include "print_array.h"
using namespace std;
/*
QUICK SORT [ Not Stable | O(n²) ]
* Divide-and-conquer algorithm
* Partitions the array around a pivot and recursively sorts the sub-arrays
* Use Case: Large datasets, general-purpose sorting, real-world application
*/
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void quick_sort(int array[], int low, int high) {
    if (low < high) {
        int mid = partition(array, low, high);
        quick_sort(array, low, mid - 1);
        quick_sort(array, mid + 1, high);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as pivot
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);  // Return the pivot index
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition index
        quick_sort(arr, low, pi - 1);  // Recursively sort the left sub-array
        quick_sort(arr, pi + 1, high);  // Recursively sort the right sub-array
    }
}

int main() {
    vector<int> arr = {9, 5, 2, 7, 1 , 8, 4, 6, 3};
    int size = arr.size();

    cout << setw(10) << "Original: ";
    print_array(arr);

    quick_sort(arr, 0, size - 1);
    cout << '\n';

    cout << setw(10) << "Sorted: ";
    print_array(arr);
    return 0;
}
