#include <iostream>
using namespace std;

int arrayMissingNumber(int arr[], int arrSize) {
    int counter = 1;
    for (size_t i = 0; i < arrSize; i++) {
        if (arr[i] == counter) {
            counter++;
            continue;
        } else {
            return counter;
        }
    }

    return -1;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arraySize = sizeof(array) / sizeof(array[0]);
    cout << arrayMissingNumber(array, arraySize);
    return 0;
}