#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
// Write a program that finds the largest and smallest element in an array
void array_find_smallest_largest_element(const int arr[], int size) {
    int smallest_element, largest_element;
    // Use algorithm to find the smallest and largest element
    smallest_element = *min_element(arr, arr + size);
    largest_element = *max_element(arr, arr + size);
    // Display smallest and largest element
    cout << "Smallest: " << smallest_element << '\n';
    cout << "Largest: " << largest_element << '\n';
}

int main() {
    int arr[] = {6, 2, 7, 1, 4, 8, 3, 9, 5};
    int size = sizeof(arr) / sizeof(int);
    array_find_smallest_largest_element(arr, size);
    return 0;
}
