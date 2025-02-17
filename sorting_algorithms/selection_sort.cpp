#include <iostream>
using namespace std;

void selection_sort(int array[], int arraySize) {
    // Declare Variables
    int temp, minIndex;

    // Sort Algorithm
    for (size_t i = 0; i < arraySize - 1; i++) {
        minIndex = i;
        for (size_t j = i + 1; j < arraySize; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }

    // Display Array
    cout << "Selection Sort:" << endl;
    for (size_t i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
}

int main() {
    int arr[] = {3, 8, 1, 7, 5, 4, 9, 2, 6};
    int size = sizeof(arr) / sizeof(int);
    selection_sort(arr, size);
    return 0;
}