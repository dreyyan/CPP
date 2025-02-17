#include <algorithm>
#include <iostream>
using namespace std;
// Write a program that finds the largest and smallest element in an array
bool array_is_sorted(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    cout << "Array is " << (array_is_sorted(arr, size) ? "" : "not ") << "sorted.\n";
    return 0;
}
