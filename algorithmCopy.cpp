#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    vector<int> copiedNumbers(5); // Define size to enable copy method
    copy(numbers.begin(), numbers.end(), copiedNumbers.begin());

    for (int i : copiedNumbers) {
        cout << i << ' ';
    }
    return 0;
}