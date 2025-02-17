#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// find_if (conditional search)
void algorithm_find_if_even(vector<int> list) {
    auto it = find_if(list.begin(), list.end(), [](int x) { return x % 2 == 0; });

    if (it != list.end()) { // Even number exists
        cout << "First Even Number: " << *it << '\n';
    } else { // No even numbers
        cout << "There are no even numbers...\n";
    }
}

int main() {
  vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  algorithm_find_if_even(numbers);
  return 0;
}