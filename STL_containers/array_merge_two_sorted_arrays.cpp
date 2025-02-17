#include <algorithm>
#include <iostream>
using namespace std;
// Write a program that merges two arrays that are sorted
void array_merge_two_sorted_arrays(int arr1[], int arr2[], int size1, int size2) {
    int merged_size = size1 + size2;
    int merged_array[merged_size];
    merge(arr1, arr1 + size1, arr2, arr2 + size2, merged_array);
    sort(merged_array, merged_array + merged_size);
    for (const int& number : merged_array) {
        cout << number << ' ';
    } cout << '\n';
}

int main() {
    int arr1[] = {6, 2, 7, 1};
    int arr2[] = {4, 8, 3, 9, 5};
    int size1 = sizeof(arr1) / sizeof(int), size2 = sizeof(arr2) / sizeof(int);
    array_merge_two_sorted_arrays(arr1, arr2, size1, size2);
    return 0;
}
