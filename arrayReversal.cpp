#include <iostream>
using namespace std;

int main() {
    int array[] = {2, 4, 6, 8, 10};
    int size = sizeof(array) / sizeof(array[0]);
    
    for (int i = size - 1; i >= 0; i--) {
        cout << array[i] << " ";
    }
    return 0;
}