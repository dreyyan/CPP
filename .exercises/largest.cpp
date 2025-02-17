#include <iostream>
using namespace std;

// Write a function that returns the index of the last occurrence of the largest element in the array
int lastLargestIndex(int arr[], int size) {
    int largest_number_index = 0; // Initialize current largest number index as first index
    for (int i = 1; i < size; ++i) {
        if (arr[i] >= arr[largest_number_index]) { // Use '>=' operator to return last occurrence
            largest_number_index = i; // Set largest number's index to the current index
        }
    } return largest_number_index; // Return index of the last largest number
}

int main() {
    int test_arr[] = {3, 8, 1, 7, 5, 4, 9, 2, 9}; // Test array
    int size = sizeof(test_arr) / sizeof(int); // Can use test_arr[0] instead of int
    cout << "Last largest number found at index: " << lastLargestIndex(test_arr, size); // Test function
    return 0;
}
