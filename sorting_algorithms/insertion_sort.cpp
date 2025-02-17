#include <iostream>
using namespace std;

void insertion_sort(int array[], int arraySize) {
    // Declare Variables
    int current;

    // Sort Algorithm
    for (size_t i = 1; i < arraySize; i++) {
        int current = array[i];
        int j = i - 1;

        while (j > -1 && current < array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }

    // Display Array
    cout << "Insertion Sort:" << endl;
    for (size_t i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
}

int main() {
    int arr[] = {9, 5, 2, 7, 1 , 8, 4, 6, 3};
    int size = sizeof(arr) / sizeof(int);
    insertion_sort(arr, size);
    return 0;
}