#include <algorithm>
#include <iostream>
using namespace std;

void array_move_zeros_to_end(int arr[], int size) {
    partition(arr, arr + size, [](int x) { return x != 0; });
    // Display array
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    } cout << '\n';
}

int main() {
    int arr[] = {3, 8, 1, 0, 7, 5, 0, 4, 0, 9, 2, 6};
    int size = sizeof(arr) / sizeof(int);
    array_move_zeros_to_end(arr, size);
    return 0;
}
