#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {2, 4, 6, 7, 8, 10};

    auto it = find_if(numbers.begin(), numbers.end(), [](int num) { return num % 2 != 0; });

    if (it != numbers.end()) {
        cout << "1st Odd Number: " << *it;
    } else {
        cout << "No Odd Numbers Found";
    }
    return 0;
}