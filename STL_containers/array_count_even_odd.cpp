#include <algorithm>
#include <iostream>
using namespace std;

void array_count_even_odd(int arr[], int size) {
    int even_count = 0, odd_count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) ++even_count;
        else ++odd_count;
    }
    // Display even and odd count
    cout << "Even: " << even_count << '\n';
    cout << "Odd: " << odd_count << '\n';
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(int);
    array_count_even_odd(arr, size);
    return 0;
}
