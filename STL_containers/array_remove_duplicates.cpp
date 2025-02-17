#include <algorithm>
#include <iostream>
using namespace std;
// Write a program that removes duplicate elements from the array
void array_remove_duplicates(int arr[], int size) {
    sort (arr, arr + size); // Sort array
    auto it = unique(arr, arr + size); // Remove adjacent duplicates
    int new_size = distance(arr, it); // Calculate size of unique elements
    int unique_elements[new_size]; // Initialize an array for unique elements with new size
    copy(arr, arr + new_size, unique_elements); // Copy unique elements in array
    // Display array
    for (int i = 0; i < new_size; ++i) {
        cout << unique_elements[i] << ' ';
    } cout << '\n';
}

int main() {
    int arr[] = {1, 1, 2, 3, 4, 4, 4, 5, 6, 7, 8, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    array_remove_duplicates(arr, size);
    return 0;
}
