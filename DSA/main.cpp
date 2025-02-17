#include <iostream>
#include "bubble_sort.h"
using namespace std;

inline void display_sorted_array(int arr[], int n) {
    // Display Sorted Array
    std::cout << " Sorted Array  || ";
    for (size_t i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    } std::cout << '\n';
}

int main() {
    int array[] = {6, 4, 7, 1, 3, 9, 2, 8, 5};
    int n = std::size(array);
    bubble_sort(array, n);
    display_sorted_array(array, n);
    return 0;
}