#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main() {
    array<string, 3> words = {"ocean", "river", "sea"};
    auto it = find(words.begin(), words.end(), "sea");
    if (it != words.end()) {
        cout << "Element '" << *it << "' found!";
    } else {
        cout << "Element not found.";
    }
    return 0;
}