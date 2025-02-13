#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;
// Set
int main() {
    ///////////////////////////////  SET  ///////////////////////////////
    // Declare and initialize a set (only stores unique values)
    set<int> uniqueNumbers = {10, 20, 30, 40, 50, 10, 20};

    cout << "Set Elements (Only Unique Values): ";
    for (int num : uniqueNumbers) {
        cout << num << " ";
    }
    cout << endl;

    // Insert a new element
    uniqueNumbers.insert(25);
    cout << "After inserting 25: ";
    for (int num : uniqueNumbers) {
        cout << num << " ";
    }
    cout << endl;

    // Check if an element exists
    if (uniqueNumbers.find(20) != uniqueNumbers.end()) {
        cout << "20 exists in the set.\n";
    } else {
        cout << "20 does not exist in the set.\n";
    }

    // Erase an element
    uniqueNumbers.erase(30);
    cout << "After erasing 30: ";
    for (int num : uniqueNumbers) {
        cout << num << " ";
    }
    cout << endl;
    ///////////////////////////////  MULTISET  ///////////////////////////////
    // Declare and initialize a multiset (allows duplicates)
    multiset<int> duplicateNumbers = {10, 20, 30, 40, 50, 10, 20};

    cout << "\nMultiset Elements (Allows Duplicates): ";
    for (int num : duplicateNumbers) {
        cout << num << " ";
    }
    cout << endl;

    // Insert duplicate values
    duplicateNumbers.insert(20);
    duplicateNumbers.insert(40);

    cout << "After inserting 20 and 40 again: ";
    for (int num : duplicateNumbers) {
        cout << num << " ";
    }
    cout << endl;

    // Erase all occurrences of a specific value
    duplicateNumbers.erase(20);
    cout << "After erasing all 20s: ";
    for (int num : duplicateNumbers) {
        cout << num << " ";
    }
    cout << endl;
    ///////////////////////////////  UNORDERED_SET  ///////////////////////////////
    unordered_set<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6}; // Unique values only

    numbers.insert(7);  // Insert element
    numbers.insert(3);  // Duplicate, will not be inserted

    cout << "Unordered Set Elements: ";
    for (int num : numbers) {
        cout << num << " ";  // Order is arbitrary
    }
    cout << endl;
    return 0;
}