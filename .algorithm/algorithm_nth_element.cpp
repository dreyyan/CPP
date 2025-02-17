#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// nth_element (place element at nth position as if it was already sorted | O(n))
void algorithm_nth_element(vector<int> list, int n) {
    nth_element(list.begin(), list.begin() + n, list.end());
    cout << n + 1 << "th smallest element: " << list[n] << '\n';
}

int main() {
    vector<int> numbers = {8, 3, 10, 7, 2, 9, 5, 1, 4, 6};
    algorithm_nth_element(numbers, 6);
    return 0;
}
