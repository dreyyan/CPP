#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// sort (ascending order | O(n log n))
void algorithm_sort(vector<int> list) {
    sort(list.begin(), list.end());
    // Display sorted algorithm
    for (const auto& number : list) {
        cout << number << ' ';
    }
}
int main() {
    vector<int> numbers = {8, 3, 10, 7, 2, 9, 5, 1, 4, 6};
    algorithm_sort(numbers);
    return 0;
}
