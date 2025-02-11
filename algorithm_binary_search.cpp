#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// binary_search (find element in sorted array using divide & conquer | O(log n))
void algorithm_binary_search(vector<int> list, int n) {
    cout << "Number " << n << (binary_search(list.begin(), list.end(), n) ? " found!" : " not found...");
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    algorithm_binary_search(numbers, 5);
    return 0;
}