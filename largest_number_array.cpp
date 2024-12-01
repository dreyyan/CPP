#include <iostream>
using namespace std;

int main() {
    int numberArray[] = {1, 7, 5, 3, 2, 4, 8, 9, 6};
    int size = sizeof(numberArray) / sizeof(numberArray[0]);
    int highestNumber;

    for (int i = 0; i < size; i++) {
        if (numberArray[i] > numberArray[i + 1]) {
            highestNumber = numberArray[i];
        }
    }

    cout << "Highest Number: " << highestNumber;

    return 0;
}
