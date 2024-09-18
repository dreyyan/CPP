#include <iostream>
using namespace std;

int main() {
    int array[] = {1, 6, 4, 2, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int temp;

    // Bubble Sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Sorted Array
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    cout << "\n2nd Highest Element: " << array[1];

    return 0;
}