#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// unique(unique elements appear last in the container)
void algorithm_unique(vector<int>& list) {
    auto it = unique(list.begin(), list.end()); // Moves duplicate elements to the back of the container
    list.erase(it, list.end()); // Erases elements from pointer(start of duplicate elements) to the end of the container

    for (const auto& number : list) {
        cout << number << ' ';
    }
}

int main() {
    vector<int> numbers = {1, 1, 1, 2, 2, 3, 4, 4, 5};
    algorithm_unique(numbers);
    return 0;
}