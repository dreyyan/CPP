#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// partial_sort (sorts first middle - begin elements | O(n log K))
void algorithm_partial_sort(vector<int> list, int n) {
    partial_sort(list.begin(), list.begin() + n, list.end());

    for (const auto& number : list) {
        cout << number << ' ';
    }
}

int main() {
    vector<int> numbers = {8, 3, 10, 7, 2, 9, 5, 1, 4, 6};
    algorithm_partial_sort(numbers, 3);
    return 0;
}
