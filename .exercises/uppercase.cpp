#include <cctype>
#include <iostream>
#include <limits>
#include <string>
using namespace std;
// CC 203 - Exercise #1 [#3]
int main() {
    // Declare a character array to store the input
    char input[100];
    // Prompt user to enter a string [store using character array]
    while (true) {
        cout << "Enter a string: ";
        cin.getline(input, 100);

        if (input[0] == '\0') { // ERROR: Blank input
            cout << "[ ERROR | String input cannot be blank ]\n";
        } else break;
    }
    // Convert character to uppercase until null-terminating character
    for (int i = 0; input[i] != '\0'; ++i) {
        input[i] = toupper(input[i]);
    }
    // Output string in uppercase letters
    for (int i = 0; input[i] != '\0'; ++i) {
        cout << input[i];
    } cout << '\n';
    return 0;
}
