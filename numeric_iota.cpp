#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers(10); // Define size
    iota(numbers.begin(), numbers.end(), 10); // Fill size with incremented values

    for (int i : numbers) {
        cout << i << ' ';
    }
    return 0;
}
