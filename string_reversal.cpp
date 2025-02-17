#include <iostream>
#include <limits>
#include <string>
using namespace std;

void display_word_reverse(const string& word) {
    cout << "Reverse: ";
    for (int i = word.length() - 1; i >= 0; i--) {
        cout << word[i];
    }
}

int main() {
    string word;
    while (true) {
        // Prompt user to enter a word
        cout << "Enter a Word: ";
        getline(cin, word);

        // ERROR: Empty word
        if (word.empty()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "[ ERROR | Word cannot be empty ]\n";
        } else break;
    }
    display_word_reverse(word);
    return 0;
}
