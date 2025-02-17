#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10); // Push elements
    s.push(20);
    s.push(30);
    
    cout << "Top element: " << s.top() << endl; // 30
    s.pop(); // Remove top element
    cout << "New top element: " << s.top() << endl; // 20
    return 0;
}
