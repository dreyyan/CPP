#include <iostream>
#include <vector>
using namespace std;
// Write a program that determines the missing number from a given sequence
int find_missing_number(vector<int>& list) {
    int counter = 1;
    for (size_t i = 0; i < list.size(); ++i) {
        if (counter != list[i]) {
            return counter;
        } ++counter;
    }
    return 0;
}

int main() {
    vector<int> numbers = {1, 2, 3, 5, 6, 7, 8, 9, 10};
    int missing_number = find_missing_number(numbers);
    if (missing_number) {
        cout << "The missing number is: " << missing_number << '\n';
    } else cout << "There are no missing numbers...\n";
    return 0;
}