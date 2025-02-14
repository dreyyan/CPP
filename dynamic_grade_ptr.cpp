#include <iostream>
using namespace std;

int main() {
    int size;

    // Prompt user to enter size of array
    cout << "Enter Size: ";
    cin >> size;

    // Dynamically allocate integer array of 'size' elements
    int* ptrArr = new int[size];

    // Prompt user to enter grades
    for (int i = 0; i < size; i++) {
        cout << "\nEnter Grade #" << i + 1 << ": ";
        cin >> ptrArr[i];
    }

    // Display grades
    for (int j = 0; j < size; j++) {
        cout << "\nGrade " << j + 1 << " = " << ptrArr[j];
    }

    delete[] ptrArr; // Free memory
    return 0;
}