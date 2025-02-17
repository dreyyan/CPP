#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// reverse (sort in descending order | O(n))
void algorithm_reverse(vector<int> list) {
    reverse(list.begin(), list.end());

    for (const auto& number : list) {
      cout << number << ' ';
    }
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
	algorithm_reverse(numbers);
    return 0;
}