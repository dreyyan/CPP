#ifndef PRINT_ARRAY_H
#define PRINT_ARRAY_H
#include <iostream>
#include <vector>
using namespace std;
void print_array(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    }
}

void print_array(const vector<int>& arr) {
    for (const int& i : arr) {
        cout << i << ' ';
    }
}

void print_array_radix(const vector<int>& arr) {
    for (const int& i : arr) {
        cout << setw(3) << i << ' ';
    }
}
#endif //PRINT_ARRAY_H
