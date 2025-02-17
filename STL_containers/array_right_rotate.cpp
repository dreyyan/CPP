#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;
// Write a program that rotates an array k positions to the right
void array_right_rotate(int arr[], int size, int rotations) {
    rotate(arr, arr + size - rotations, arr + size);
    // Display rotated array
    cout << "Rotated: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    } cout << '\n';
}

int main() {
    int arr[] = {3, 8, 1, 7, 5, 4, 9, 2, 6};
    int size = sizeof(arr) / sizeof(int);
    int rotations;
    // Display current array
    cout << "Current: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ' ';
    } cout << '\n';
    // Prompt user to enter # of rotations
    while (true) {
        cout << "Enter # of rotations: ";
        cin >> rotations;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[ ERROR | Invalid number ]\n";
        } else break;
    }
    array_right_rotate(arr, size, rotations);
    return 0;
}
