#include <iostream>
using namespace std;

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return i + 1;
}

void quick_sort(int array[], int low, int high) {
    if (low < high) {
        int mid = partition(array, low, high);
        quick_sort(array, low, mid - 1);
        quick_sort(array, mid + 1, high);
    }
}