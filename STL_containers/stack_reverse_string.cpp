#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Write a program that uses stack to reverse a string input
void stack_reverse_string(string& word) {
    stack<char> reversed_word;
    // Push letters to the stack
    for (const char& letter : word) {
        reversed_word.push(letter);
    }
    // Display reversed letters from stack
    cout << "Output: ";
    while (!reversed_word.empty()) {
        cout << reversed_word.top(); // Access top character
        reversed_word.pop(); // Remove top character
    }
}

int main() {
    string word;
    // Prompt user to enter a string
    while (true) {
        cout << "Input a word: ";
        getline(cin, word);

        if (word.empty()) {
            cin.clear();
            cout << "[ ERROR | Word cannot be empty ]\n";
        } else break;
    }

    stack_reverse_string(word);
    return 0;
}
