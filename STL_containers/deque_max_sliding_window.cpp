#include <deque>
#include <iostream>
#include <numeric>
using namespace std;
// Write a program that calculates & displays the sum of 3 consecutive elements
int main() {
    deque<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deque<int> sum;

    for (size_t i = 0; i < numbers.size() - 2; ++i) {
        sum.push_back(accumulate(numbers.begin() + i, numbers.begin() + i + 3, 0));
    } // Store sum of 3 consecutive numbers
    
    for (const int& num : sum) {
        cout << num << ' ';
    }
    return 0;
}