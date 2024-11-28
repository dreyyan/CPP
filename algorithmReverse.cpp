#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    reverse(numbers.begin(), numbers.end());

    for (int i : numbers) {
        cout << i << ' ';
    }
    return 0;
}