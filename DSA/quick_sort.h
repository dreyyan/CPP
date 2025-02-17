#ifndef QUICK_SORT_H
#define QUICK_SORT_H

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Set Pivot
    int i = low - 1; // Set to Out-of-Bounds

    // Sort the Array
    for (size_t j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

inline void quick_sort( int arr[], int low, int high) {
    // Sort the Array
    if (low < high) {
        int mid = partition(arr, low, high);
        quick_sort(arr, low, mid - 1);
        quick_sort(arr, mid + 1, high);
    }
}
#endif //QUICK_SORT_H
