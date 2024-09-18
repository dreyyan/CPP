#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int rows, columns;
    srand(time(0));

    cout << "Enter # of rows: ";
    cin >> rows;
    cout << "Enter # of columns: ";
    cin >> columns;

    // Dynamically allocate a 2D array
    int** array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[columns];
    }

    // Enter Random Numbers for Array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            array[i][j] = rand() % 100;
    }
}

    // Print Array
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << array[i][j] << "\t";
        }
        cout << "\n";
    }

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        delete[] array[i];  // Free each row
    }
    delete[] array;  // Free the array of row pointers

    return 0;
}
