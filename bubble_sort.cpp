#include <iostream>
#include <vector>
using namespace std;
// Bubble Sort (o(n^2))
void bubble_sort(vector<int>& arr, int n) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n - 1; ++j) {
            if (arr[j] > arr [j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    // Display array
    for (const int& num : arr) {
        cout << num << ' ';
    }
}

int main() {
    vector<int> numbers = {9, 5, 2, 7, 1 , 8, 4, 6, 3};
    size_t size = numbers.size();
    bubble_sort(numbers, size);
    return 0;
}