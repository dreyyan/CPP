#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// fill (sets all elements in the container to the specified value)
void algorithm_fill(vector<int>& list, int n) {
    fill(list.begin(), list.end(), n);
    for (const auto& number : list) {
        cout << number << ' ';
    }
}

int main() {
    vector<int> numbers = {1, 2, 3, 1, 2, 1, 1, 4, 5, 4, 7};
    algorithm_fill(numbers, 5);
    return 0;
}