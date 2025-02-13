#include <iostream>
#include <algorithm>
using namespace std;

void algorithm_min_max_element(int list[], size_t size) {
    // Display minimum & maximum element
    // End iterator is one past the last element of the array[list + size]
    cout << "Minimum Element: " << *min_element(list, list + size) << "\n";
    cout << "Maximum Element: " << *max_element(list, list + size) << "\n";
}

int main() {
    int array[] = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    size_t size = sizeof(array) / sizeof(array[0]);
    algorithm_min_max_element(array, size);
    return 0;
}