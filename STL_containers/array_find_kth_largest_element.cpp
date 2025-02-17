#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

void array_find_kth_largest_element(int arr[], int size, int k) {
    nth_element(arr, arr + size - k, arr + size);
    // Display kth largest element
    cout << k << "th largest element: " << arr[size - k] << '\n';
}

int main() {
    int arr[] = {3, 8, 1, 7, 5, 4, 9, 2, 6};
    int size = sizeof(arr) / sizeof(int);
    int k;
    // Prompt user to enter k
    while (true) {
        cout << "kth largest element: ";
        cin >> k;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[ ERROR | Invalid number ]\n";
        } else break;
    }
    array_find_kth_largest_element(arr, size, k);
    return 0;
}
