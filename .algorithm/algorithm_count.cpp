#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// count (counts the number of occurences of a specific element in a container)
void algorithm_count(vector<int>& list, int n) {
    int occurences = count(list.begin(), list.end(), n);
    cout << "There are " << occurences << " #" << n << "s in the container.\n";
}

int main() {
    vector<int> numbers = {1, 2, 3, 1, 2, 1, 1, 4, 5, 4, 7};
    algorithm_count(numbers, 1);
    return 0;
}