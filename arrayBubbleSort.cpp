#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {
    int temp;
    // Print Current Array
    cout << "Current Array:\n";
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }

    // Bubble Sort
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            while (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Print New Array
    cout << "\nNew Array:\n";
    for (size_t i = 0; i < size; i++) {
        cout << arr[i] << ' ';
    }
}

int main() {
    int array[] = {2, 8, 9, 3, 7, 1, 4, 5, 6};
    int arraySize = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, arraySize);
    return 0;
}