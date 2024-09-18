// Redundant Code, Wrong Loop Ranges, Need Fix
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int size = 2;
    int num;
    int temp;
    vector<int> numbers = {};

    // Enter array values
    for (int i = 0; i < size; i++) {
        cout << "Enter #" << i + 1 << ": ";
        cin >> num;
        numbers.push_back(num);
    }

    // Sort Array
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // Display Sorted Array
    cout << "Numbers: ";
    for (int j = 0; j < size; j++) {
        cout << numbers[j] << " ";
    }

    // GCD
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            for (int k = numbers[0]; k > 1; k--) {
                if (numbers[i] % k == 0 && numbers[j] % k == 0 && numbers[i] != numbers[j]) {
                    cout << "\nThe GCD of " << numbers[i] << " and " << numbers[j] << " is " << k << ".";
                    return 0;
                }
            }
        }
    }

    return 0;
}