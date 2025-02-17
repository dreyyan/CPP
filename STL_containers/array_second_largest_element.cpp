#include <algorithm>
#include <iostream>
using namespace std;
// Write a program that returns the 2nd largest element in the array
void array_second_largest_element(int arr[], int size) {
    short second_largest_element;
    sort(arr, arr + size); // Sort array
    second_largest_element = arr[size - 2]; // 2nd largest is the 2nd to the last element
    cout << "2nd Largest Element: " << second_largest_element << '\n';
}

int main() {
    int arr[] = {3, 8, 1, 7, 5, 4, 9, 2, 6};
    int size = sizeof(arr) / sizeof(int);
    array_second_largest_element(arr, size);
    return 0;
}
