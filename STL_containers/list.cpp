#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> myList = {10, 20, 30, 40, 50};
    list<int> anotherList = {100, 200, 300};

    // Element Access
    cout << "Front element: " << myList.front() << endl;
    cout << "Back element: " << myList.back() << endl;

    // Iterators
    cout << "List elements: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Capacity
    cout << "Is empty? " << (myList.empty() ? "Yes" : "No") << endl;
    cout << "Size: " << myList.size() << endl;

    // Modifiers
    myList.push_front(5);
    myList.push_back(60);
    cout << "After push_front(5) and push_back(60): ";
    for (int n : myList) cout << n << " ";
    cout << endl;

    myList.pop_front();
    myList.pop_back();
    cout << "After pop_front() and pop_back(): ";
    for (int n : myList) cout << n << " ";
    cout << endl;

    myList.insert(next(myList.begin(), 2), 25);
    cout << "After insert(25 at position 2): ";
    for (int n : myList) cout << n << " ";
    cout << endl;

    myList.erase(next(myList.begin(), 2));
    cout << "After erase(position 2): ";
    for (int n : myList) cout << n << " ";
    cout << endl;

    myList.merge(anotherList);
    cout << "After merge(): ";
    for (int n : myList) cout << n << " ";
    cout << endl;

    myList.reverse();
    cout << "After reverse(): ";
    for (int n : myList) cout << n << " ";
    cout << endl;

    myList.sort();
    cout << "After sort(): ";
    for (int n : myList) cout << n << " ";
    cout << endl;

    myList.clear();
    cout << "After clear(), size: " << myList.size() << endl;

    return 0;
}