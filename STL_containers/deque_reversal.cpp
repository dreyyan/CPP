#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int firstElement, lastElement;
    // Reverse Deque
    reverse(dq.begin(), dq.end());
    // Display Deque
    for (size_t num : dq) {
        cout << num << ' ';
    }
    return 0;
}