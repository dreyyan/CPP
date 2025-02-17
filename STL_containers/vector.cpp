#include <iostream>
#include <vector>
using namespace std;
// Vector ()
int main() {
    vector<int> vec = {1, 2, 3, 4, 5};

    // Element Access
    cout << "First element: " << vec.front() << endl;
    cout << "Last element: " << vec.back() << endl;
    cout << "Element at index 2: " << vec.at(2) << endl;
    cout << "Element using operator[]: " << vec[3] << endl;

    // Iterators
    cout << "Vector elements: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Capacity
    cout << "Is empty: " << vec.empty() << endl;
    cout << "Size: " << vec.size() << endl;
    cout << "Max size: " << vec.max_size() << endl;
    vec.shrink_to_fit();
    cout << "Shrink to fit done." << endl;

    // Modifiers
    vec.push_back(6);
    vec.push_back(7);
    vec.pop_back();
    vec.insert(vec.begin() + 1, 10);
    vec.erase(vec.begin() + 3);
    vec.clear();

    cout << "Vector size after modifications: " << vec.size() << endl;

    return 0;
}