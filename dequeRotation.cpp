#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 5, lastElement;
    
    for (size_t i = 0; i < n; i++) {
        lastElement = dq.back();
        dq.push_front(lastElement);
        dq.pop_back();
    }
    
    for (int num : dq) {
        cout << num << ' ';
    }
    return 0;
}