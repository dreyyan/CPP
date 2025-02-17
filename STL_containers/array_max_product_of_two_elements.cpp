#include <algorithm>
#include <iostream>
using namespace std;

void array_max_product_of_two_elements(int arr[], int size) {
    int product = 0, max_product = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] * arr[j] > max_product) {
                max_product = arr[i] * arr[j];
            }
        }
    }
    // Display max product
    cout << "Max Product: " << max_product << '\n';
}

int main() {
    int arr[] = {3, 8, 1, 7, 5, 4, 9, 2, 6};
    int size = sizeof(arr) / sizeof(int);
    array_max_product_of_two_elements(arr, size);
    return 0;
}