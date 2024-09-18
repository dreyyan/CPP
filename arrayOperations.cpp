#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int array[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int temp = 0;
    int sum = 0;
    int average = 0;

    // Min & Max of Elements
    cout << "Minimum Element: " << *min_element(array, array + size) << "\n";
    cout << "Maximum Element: " << *max_element(array, array + size) << "\n";

    // Bubble Sort: Ascending Order
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Print Sorted Array
    cout << "Sorted Array:\n";

    for (int k = 0; k < size; k++) {
        cout << array[k] << " ";
    }

    // Sum of Array
    for (int l = 0; l < size; l++) {
        sum += array[l];
    }

    // Average of Array
    average = sum / size;

    // Print Results
    cout << "\nSum of Array: " << sum;
    cout << "\nAverage: " << average << "\n";

    cout << "Reverse Array: ";

    // Reverse of Array
    for (int m = size - 1; m >= 0; m--) {
        cout << array[m] << " ";
    }

    return 0;
}