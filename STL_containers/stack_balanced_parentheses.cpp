#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Write a program that uses stack to check if string has balanced brackets
bool stack_is_balanced_parentheses(string& input_brackets) {

}

int main() {
    string brackets;
    // Prompt user to enter a string of brackets
    while (true) {
        cout << "Input brackets: ";
        getline(cin, brackets);

        if (brackets.empty()) {
            cin.clear();
            cout << "[ ERROR | Word cannot be empty ]\n";
        } else break;
    }

    // Display result
    cout << (stack_is_balanced_parentheses(brackets) ? "Balanced" : "Not Balanced");
    return 0;
}
