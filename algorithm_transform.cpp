#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// transform (modify each element in the list)
void algorithm_transform(vector<int> list) {
    transform(list.begin(), list.end(), list.begin(), [](int x) { return x + 2; });
    for (const auto& number : list) {
        cout << number << ' ';
    }
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    algorithm_transform(numbers);
    return 0;
}