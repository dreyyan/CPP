#include <iostream>
#include <array>
using namespace std;
// Array ()
int main() {
    // Declare and initialize an std::array
    array<int, 5> numbers = {10, 20, 30, 40, 50};

    // Access elements using index
    cout << "First element: " << numbers[0] << endl;
    cout << "Last element: " << numbers[numbers.size() - 1] << endl;

    // Using at() (safe bounds-checked access)
    cout << "Element at index 2: " << numbers.at(2) << endl;

    // Iterate using range-based for loop
    cout << "Array elements: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Check size and if empty
    cout << "Size of array: " << numbers.size() << endl;
    cout << "Is array empty? " << (numbers.empty() ? "Yes" : "No") << endl;

    // Access front and back elements
    cout << "Front element: " << numbers.front() << endl;
    cout << "Back element: " << numbers.back() << endl;

    return 0;
}
