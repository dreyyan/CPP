#include <numeric>
#include <iostream>
using namespace std;
// Write a program that returns the sum of elements in the array
void array_sum_of_elements(int arr[], int size) {
    cout << "Sum: " << accumulate(arr, arr + size, 0);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    array_sum_of_elements(arr, size);
    return 0;
}
