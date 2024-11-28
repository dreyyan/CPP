#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 2, 3, 4, 4, 5, 5};
    auto it = unique(numbers.begin(), numbers.end()); // Rearranges the elements so that unique elements appear last in the container
    numbers.erase(it, numbers.end()); // Erases elements from range 'it' to the end of the container
    
    for (int i : numbers) {
        cout << i << ' ';
    }
    return 0;
}