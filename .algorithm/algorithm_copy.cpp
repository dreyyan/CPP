#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// copy (copies a range of elements from one container to another | O(n))
void algorithm_copy(vector<int>& list_to_copy, vector<int>& copied_list) {
    copy(list_to_copy.begin(), list_to_copy.end(), copied_list.begin());

    for (const auto& number : copied_list) {
      cout << number << ' ';
    }
}

int main() {
    vector<int> list_to_copy = {1, 2, 3, 4, 5};
    vector<int> copied_list(5);
    algorithm_copy(list_to_copy, copied_list);
    return 0;
}