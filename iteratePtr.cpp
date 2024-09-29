#include <iostream>
using namespace std;

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);
    int* ptr = nullptr;

    for (int i = 0; i < size; i++) {
        ptr = &array[i];
        cout << *ptr << " ";
    }

    return 0;
}