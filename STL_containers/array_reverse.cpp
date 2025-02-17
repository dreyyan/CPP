#include <algorithm>
#include <iostream>
using namespace std;

void array_reverse(int arr[], int size) {
    reverse(arr, arr + size); // Use algorithm to reverse array
    // Display array
    for (size_t i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    } cout << '\n';
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    array_reverse(arr, size);
    return 0;
}
