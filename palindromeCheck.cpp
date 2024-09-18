#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;
    string reverseWord;

    cout << "Enter word:";
    cin >> word;

    for (int i = word.length() - 1; i >= 0; i--) {
        reverseWord += word[i];
    }

    if (reverseWord == word) {
        cout << word << " is a palindrome.";
    }

    else {
        cout << word << " is not a palindrome.";
    }

    return 0;
}