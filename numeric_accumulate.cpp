#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = accumulate(numbers.begin(), numbers.end(), 0); // Starting Value
    cout << "Accumulated Sum: " << sum;
    return 0;
}
