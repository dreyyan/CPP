#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    dq.push_back(dq.back() + 1); // Enqueue
    dq.pop_front(); // Dequeue
    
    for (int num : dq) {
        cout << num << ' ';
    }
    return 0;
}