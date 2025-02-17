#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// partition (sorts the container, wherein elements that satisfy the condition appear first)
void algorithm_partition(vector<int> list) {
  partition(list.begin(), list.end(), [](int x) { return x % 2 != 0; });
	for (const auto& number : list) {
          cout << number << ' ';
	}
}

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
	algorithm_partition(numbers);
    return 0;
}