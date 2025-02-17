#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);

    cout << "Top priority element: " << pq.top() << endl; // 30
    pq.pop();
    cout << "New top: " << pq.top() << endl; // 20
    return 0;
}
