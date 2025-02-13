#include <iomanip>
#include <iostream>
using namespace std;

void arrayRotation(int rotations) {
    int array[] = {1, 2, 3, 1, 2, 1, 1, 4, 5, 4, 7};
    int arraySize = sizeof(array) / sizeof(array[0]);
    int temp = 0;
    cout << setw(9) << "Rotate: " << rotations << '\n';
    // Display current array
    cout << setw(9) << "Current: ";
    for (size_t i = 0; i < arraySize; i++) {
        if (i == arraySize - 1) {
            cout << array[i];
            break;
        }
        cout << array[i] << ", ";
    } cout << '\n';
    // Rotate array
    for (size_t i = 0; i < rotations; i++) {
            temp = array[0];
            for (size_t i = 0; i < arraySize - 1; i++) {
                array[i] = array[i + 1];
            }
            array[arraySize - 1] = temp;
    }
    // Display new array
    cout << setw(9) << "New: ";
    for (size_t i = 0; i < arraySize; i++) {
        if (i == arraySize - 1) {
            cout << array[i];
            break;
        }
        cout << array[i] << ", ";
    }
}

int main() {
    arrayRotation(5);
    return 0;
}