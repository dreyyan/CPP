#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// find (linear search)
void algorithm_find(vector<int> list, int n) {
    auto it = find(list.begin(), list.end(), n);

    if (it != list.end()) { // Number exists
        cout << "Number '" << n << "' found at index " << distance(list.begin(), it) << '\n';
    } else { // Number does not exist
        cout << "Number '" << n << "' does not exist...\n";
    }
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    algorithm_find(numbers, 3);
    return 0;
}