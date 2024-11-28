#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    partition(numbers.begin(), numbers.end(), [](int x) { return x % 2 != 0; });

    // Numbers that satisfy the condition appear first in the vector
    for (int i : numbers) {
        cout << i << ' ';
    }
    return 0;
}