#include <iostream>
#include <vector>
using namespace std;
void display_format(size_t length) {
    for (size_t i = 0; i < length; ++i) {
        cout << '-';
    } cout << '\n';
}

void matrix_addition(int arr[][4], size_t rows, size_t columns) {
    cout << "[ MATRIX: ADDITION ]\n";
    // Display matrices
    for (size_t i = 0; i < rows; ++i) {
        cout << "[ ";
        for (size_t j = 0; j < columns; ++j) {
            cout << arr[i][j] << ' ';
        } if (i == 0) cout << "]\n     +     \n";
        else cout << "]\n     =     \n";
    }
    // Calculate & display sum of matrices
    for (size_t i = 0; i < rows; ++i) {
        cout << "[ ";
        for (size_t j = 0; j < columns; ++j) {
            cout << arr[i][j] + arr[i + 1][j] << ' ';
        } cout << "]";
        break;
    } cout << '\n';
    display_format(23);
}

void matrix_subtraction(int arr[][4], size_t rows, size_t columns) {
    cout << "[ MATRIX: SUBTRACTION ]\n";
    // Display matrices
    for (size_t i = 0; i < rows; ++i) {
        cout << "[ ";
        for (size_t j = 0; j < columns; ++j) {
            cout << arr[i][j] << ' ';
        } if (i == 0) cout << "]\n     -     \n";
        else cout << "]\n     =     \n";
    }
    // Calculate & display sum of matrices
    for (size_t i = 0; i < rows; ++i) {
        cout << "[ ";
        for (size_t j = 0; j < columns; ++j) {
            cout << arr[i][j] - arr[i + 1][j] << ' ';
        } cout << "]";
        break;
    } cout << '\n';
    display_format(26);
}

void matrix_multiplication(int arr[][4], size_t rows, size_t columns) {
    cout << "[ MATRIX: MULTIPLICATION ]\n";
    // Display matrices
    for (size_t i = 0; i < rows; ++i) {
        cout << "[ ";
        for (size_t j = 0; j < columns; ++j) {
            cout << arr[i][j] << ' ';
        } if (i == 0) cout << "]\n     x     \n";
        else cout << "]\n     =     \n";
    }
    // Calculate & display sum of matrices
    for (size_t i = 0; i < rows; ++i) {
        cout << "[ ";
        for (size_t j = 0; j < columns; ++j) {
            cout << arr[i][j] * arr[i + 1][j] << ' ';
        } cout << "]";
        break;
    } cout << '\n';
    display_format(20);
}

void matrix_division(int arr[][4], size_t rows, size_t columns) {
    cout << "[ MATRIX: DIVISION ]\n";
    // Display matrices
    for (size_t i = 0; i < rows; ++i) {
        cout << "[ ";
        for (size_t j = 0; j < columns; ++j) {
            cout << arr[i][j] << ' ';
        } if (i == 0) cout << "]\n     /     \n";
        else cout << "]\n     =     \n";
    }
    // Calculate & display sum of matrices
    for (size_t i = 0; i < rows; ++i) {
        cout << "[ ";
        for (size_t j = 0; j < columns; ++j) {
            cout << arr[i][j] / arr[i + 1][j] << ' ';
        } cout << "]";
        break;
    } cout << '\n';
    display_format(20);
}

int main() {
    const int rows = 2, columns = 4;
    int first_array[rows][columns] = {{1, 4, 2, 6}, {4, 2, 5, 3}};
    matrix_addition(first_array, rows, columns);
    matrix_subtraction(first_array, rows, columns);
    matrix_multiplication(first_array, rows, columns);
    matrix_division(first_array, rows, columns);
    return 0;
}