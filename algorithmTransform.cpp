#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    transform(numbers.begin(), numbers.end(), numbers.begin(), [](int x) { return x + 2; });

    for (int i : numbers) {
        cout << i << ' ';
    }
    return 0;
}