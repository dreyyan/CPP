#include <iostream>
#include <string>
using namespace std;

void inputOutputLength(string* stringPtr) {
    cout << "\nEnter Word: ";
    cin >> *stringPtr;

    int stringLength = stringPtr->length();
    cout << "Length: " << stringLength;
}

int main() {
    string word;
    inputOutputLength(&word);

    return 0;
}
