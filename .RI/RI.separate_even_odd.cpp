#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// Write a program that separates even and odd numbers
void separate_even_odd(vector<int> numbers) {
    vector<int> even, odd;
    for (const int& number : numbers) {
        if (number % 2 == 0) {
            even.push_back(number);
        } else {
            odd.push_back(number);
        }
    }
    // Display even numbers
    cout << "Even Numbers: ";
    for (const int& number : even) {
        cout << number << ' ';
    } cout << '\n';
    // Display odd numbers
    cout << "Odd Numbers: ";
    for (const int& number : odd) {
        cout << number << ' ';
    } cout << '\n';
    int num;
    cin >> num;
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    separate_even_odd(numbers);
    return 0;
}