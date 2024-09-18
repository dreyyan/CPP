#include <iostream>
using namespace std;


int main() {
    int size;

    cout << "Enter Size of Array: ";
    cin >> size;

    int* integerArray = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "\nEnter Number #" << i + 1 << ": ";
        cin >> integerArray[i];
    }

    cout << "\nNumbers: ";
    for (int i = 0; i < size; i++) {
        cout << integerArray[i] << " ";
    }

    delete[] integerArray;
    return 0;
}

// Write a program that dynamically allocates an array of integers with a user-defined size.
// Then, allow the user to input values into the array and display the sum of the elements.
// Finally, free the allocated memory.
