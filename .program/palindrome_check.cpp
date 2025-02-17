#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
// Write a program that inputs a word and checks if it is a palindrome or not
bool is_palindrome(string word) {
    string reversed_word = word;
    reverse(reversed_word.begin(), reversed_word.end());
    // Check if word and reversed word are equal
    if (word == reversed_word) return true; else return false;
}

int main() {
    string word;
    // Prompt user to enter a word
    cout << "Enter a word: ";
    getline(cin, word);
    cout << word << " is " << (is_palindrome(word) ? "" : "not ") << "a palindrome.";
    return 0;
}
