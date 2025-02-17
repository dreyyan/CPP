#include <numeric>
#include <iostream>
using namespace std;

void array_sum_of_elements(int arr[], size_t size) {
    cout << "Sum: " << accumulate(arr, arr + size, 0);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t size = sizeof(arr) / sizeof(int);
    array_sum_of_elements(arr, size);
    return 0;
}
