#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

inline void bubble_sort(int arr[], int n) {
    // Sort the Array
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

#endif //BUBBLE_SORT_H