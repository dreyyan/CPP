#include <iostream>
#include <array>
using namespace std;

int arrayCount(int element) {
    int count = 0;
    int array[] = {1, 2, 3, 1, 2, 1, 1, 4, 5, 4, 7};
    for (size_t i : array) {
        if (element == i) {
            count++;
        }
    }
    return count;
}

int main() {
    cout << "Count: " << arrayCount(1);
    return 0;
}