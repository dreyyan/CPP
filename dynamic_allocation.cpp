#include <iostream>
#include <memory> // For smart pointers
using namespace std;

int main() {
    // 🔹 1. Dynamically Allocating a Single Integer
    int* singleInt = new int(42);
    cout << "Single Integer: " << *singleInt << endl;
    delete singleInt; // Free memory

    // 🔹 2. Dynamically Allocating an Array
    int size;
    cout << "Enter array size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size!" << endl;
        return 1;  // Exit if size is invalid
    }

    int* arr = new int[size]; // Allocate array dynamically

    // Assign values
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;  // Fill array with multiples of 10
    }

    // Print array values
    cout << "Array values: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Free array memory

    // 🔹 3. Dynamically Allocating a 2D Array
    int rows = 3, cols = 3;
    int** matrix = new int*[rows];  // Allocate array of pointers

    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];  // Allocate each row

    // Assign values
    cout << "2D Array (Matrix):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (i + 1) * (j + 1);  // Fill with multiplication values
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Free 2D array memory
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;

    // 🔹 4. Using Smart Pointers (Best Practice)
    unique_ptr<int> smartPtr = make_unique<int>(100);  // Allocates dynamically
    cout << "Smart Pointer Value: " << *smartPtr << endl;

    return 0; // Memory for smartPtr is automatically freed
}
