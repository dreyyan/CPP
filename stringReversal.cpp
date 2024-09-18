#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    cout << "Enter a Word: ";
    cin >> word;

    cout << "\nReverse: ";
    for (int i = word.length() - 1; i >= 0; i--) {
        cout << word[i];
    }

    return 0;
}