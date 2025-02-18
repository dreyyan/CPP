#include <iomanip>
#include <iostream>
#include <vector>
#include "print_array.h"
using namespace std;

/*
MERGE SORT [ Stable | O(n log n) ]
* Divide-and-conquer algorithm
* Recursively splits the array into two halves and merges them back in sorted order
* Use Case: Large datasets, external sorting (when data can't fit in memory)
*/
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];  // Corrected indexing here
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    vector<int> arr = {9, 5, 2, 7, 1 , 8, 4, 6, 3};
    int size = arr.size();

    cout << setw(10) << "Original: ";
    print_array(arr);

    merge_sort(arr, 0, size - 1);
    cout << '\n';

    cout << setw(10) << "Sorted: ";
    print_array(arr);
    return 0;
}
