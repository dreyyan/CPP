#include <iostream>
using namespace std;

// Write a function that returns the index of the first occurrence of the smallest element in the array
int smallestIndex(int arr[], int size) {
    int smallest_number_index = 0; // Initialize current smallest number index as first index
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[smallest_number_index]) {
            smallest_number_index = i; // Set smallest number's index to the current index
        }
    } return smallest_number_index; // Return index of the first smallest number
}

int main() {
    int test_arr[] = {3, 8, 1, 7, 5, 4, 9, 2, 6}; // Test array
    int size = sizeof(test_arr) / sizeof(int); // Can use test_arr[0] instead of int
    cout << "First smallest number found at index: " << smallestIndex(test_arr, size); // Test function
    return 0;
}
