#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// Write a program that uses [ algorithm | find_if ] to check if a number exists within a given set of container
template <typename T>
void number_exists(const T& container, int number) {
    auto it = find_if(container.begin(), container.end(), [&number](int i) { return i == number; });

    if (it != container.end()) {
        cout << "Number '" << number << "' exists!\n";
    } else { cout << "Number '" << number << "' not found...\n"; }
}

int main() {
    vector<int> number_list = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    number_exists(number_list, 5);
    return 0;
}
