#include <iostream>
#include <deque>
using namespace std;

void printDeque(const deque<int>& dq) {
    for (int num : dq) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    deque<int> dq = {10, 20, 30, 40, 50};
    
    // 2. Element Access
    cout << "Front: " << dq.front() << "\n";
    cout << "Back: " << dq.back() << "\n";
    cout << "Element at index 2: " << dq.at(2) << "\n";
    cout << "Element at index 3 (operator[]): " << dq[3] << "\n";
    
    // 3. Iterators
    cout << "Elements using begin() and end(): ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    cout << "Elements using rbegin() and rend(): ";
    for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
    
    // 4. Capacity
    cout << "Is empty: " << (dq.empty() ? "Yes" : "No") << "\n";
    cout << "Size: " << dq.size() << "\n";
    cout << "Max Size: " << dq.max_size() << "\n";
    
    // 5. Modifiers
    dq.push_back(60);
    dq.push_front(5);
    cout << "After push_back(60) and push_front(5): ";
    printDeque(dq);
    
    dq.pop_back();
    dq.pop_front();
    cout << "After pop_back() and pop_front(): ";
    printDeque(dq);
    
    dq.insert(dq.begin() + 2, 25);
    cout << "After insert at index 2: ";
    printDeque(dq);
    
    dq.insert(dq.begin(), 2, 99);
    cout << "After inserting 99 twice at the beginning: ";
    printDeque(dq);
    
    dq.erase(dq.begin() + 2);
    cout << "After erase at index 2: ";
    printDeque(dq);
    
    dq.erase(dq.begin(), dq.begin() + 2);
    cout << "After erasing first two elements: ";
    printDeque(dq);
    
    deque<int> dq2 = {1, 2, 3};
    dq.swap(dq2);
    cout << "After swap with dq2: ";
    printDeque(dq);
    
    dq.assign(3, 42);
    cout << "After assign(3, 42): ";
    printDeque(dq);
    
    dq.clear();
    cout << "After clear(): " << (dq.empty() ? "Deque is empty" : "Deque is not empty") << "\n";
    
    return 0;
}