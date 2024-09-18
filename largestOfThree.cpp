#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3;
    int greaterNumber = 0;

    cout << "Enter 3 numbers: ";
    cin >> num1 >> num2 >> num3;

    int numbers[] = {num1, num2, num3};

    for (int i = 0; i < 3; i++) {
        if (numbers[i] > greaterNumber) {
            greaterNumber = numbers[i];
        }
    }

    cout << "Highest Number: " << greaterNumber;
    return 0;
}