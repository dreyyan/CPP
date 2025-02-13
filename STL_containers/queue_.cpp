#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.front() << ", Back: " << q.back() << endl; // 1, 3
    q.pop(); // Remove front element
    cout << "New front: " << q.front() << endl; // 2
    return 0;
}