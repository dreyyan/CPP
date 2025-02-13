#include <iostream>
using namespace std;

void bubble_sort(int array[], int arraySize) {
    // Declare Variables
    int temp;

    // Sort Algorithm
    for (size_t i = 0; i < arraySize - 1; i++) {
        for (size_t j = 0; j < arraySize - i - 1; j++) {
            while (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Display Array
    cout << "Bubble Sort:" << endl;
    for (size_t i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
}