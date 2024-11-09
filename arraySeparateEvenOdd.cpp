#include <iostream>
using namespace std;

void arraySeparateEvenOdd(int array[], int arraySize) {
    int newArray[arraySize] = {};
    int counter = 0;
    for (size_t i = 0; i < arraySize; i++) {
        if (array[i] % 2 == 0) {
            newArray[counter++] = array[i];
        }
    }

    for (size_t j = 0; j < arraySize; j++) {
            if (array[j] % 2 != 0) {
                newArray[counter++] = array[j];
            }
    }

    for (size_t k = 0; k < arraySize; k++) {
        if (k == arraySize - 1) {
            cout << newArray[k];
        } else {
            cout << newArray[k] << ",";
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    arraySeparateEvenOdd(arr, arrSize);
    return 0;
}