#include <iostream>
#include <string>
using namespace std;
// Write a program that displays the word length using pointer referencing 
void display_word_length(string* stringPtr) {
    // Prompt user to enter word
    cout << "Enter Word: ";
    cin >> *stringPtr;

    size_t string_length = stringPtr->length(); // Get length of string
    cout << "Length: " << string_length; // Display string length
}

int main() {
    string word;
    display_word_length(&word);
    return 0;
}
