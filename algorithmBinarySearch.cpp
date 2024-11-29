#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << (binary_search(numbers.begin(), numbers.end(), 1) ? "Found!" : "Not Found.");
    return 0;
}