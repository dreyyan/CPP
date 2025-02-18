#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include "print_array.h"
using namespace std;
/*
RADIX SORT [ Stable | O(nk) ]
* Sorts numbers by processing individual digits (or characters for strings)
* Uses a stable sorting algorithm (like Counting Sort) as a subroutine to sort digits
* Works from the least significant digit (LSD) or most significant digit (MSD)
* Use Case: Large datasets of integers or strings (e.g., sorting zip codes, integer IDs)
*/
void count_sort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);  // Output array
    int count[10] = {0};    // Count array for digits (0-9)

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] contains sorted numbers
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radix_sort(vector<int>& arr) {
    // Find the maximum number to determine the number of digits
    int max_val = *max_element(arr.begin(), arr.end());

    // Apply counting sort for every digit. Note that the exp is 10^i where i is the current digit
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        count_sort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << setw(10) << "Original: ";
    print_array_radix(arr);

    radix_sort(arr);
    cout << '\n';

    cout << setw(10) << "Sorted: ";
    print_array_radix(arr);
    return 0;
}