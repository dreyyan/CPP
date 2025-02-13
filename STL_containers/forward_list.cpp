#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    // Declare and initialize a forward_list
    forward_list<int> numbers = {10, 20, 30, 40, 50};

    // Insert elements at the front
    numbers.push_front(5);
    
    // Display elements
    cout << "Forward List Elements: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Remove front element
    numbers.pop_front();
    cout << "After pop_front(): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Insert after a given position
    auto it = numbers.before_begin(); // Get iterator before the first element
    numbers.insert_after(it, 2); // Insert 2 after it (before_begin)
    
    cout << "After insert_after(): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Remove specific value
    numbers.remove(30);
    cout << "After removing 30: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Reverse the forward_list
    numbers.reverse();
    cout << "After reverse(): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Sort the forward_list
    numbers.sort();
    cout << "After sort(): ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}