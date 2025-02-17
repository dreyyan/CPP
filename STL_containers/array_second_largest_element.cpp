#include <algorithm>
#include <iostream>
using namespace std;

void array_second_largest_element(int arr[], short size) {
    short second_largest_element;
    sort(arr, arr + size); // Sort array
    second_largest_element = arr[size - 2]; // 2nd largest is the 2nd to the last element
    cout << "2nd Largest Element: " << second_largest_element << '\n';
}

int main() {
    int arr[] = {3, 8, 1, 7, 5, 4, 9, 2, 6};
    short size = sizeof(arr) / sizeof(int);
    array_second_largest_element(arr, size);
    return 0;
}
