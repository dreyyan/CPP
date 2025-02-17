#include <iostream>
#include <cctype>
using namespace std;
// CC 202 - Exercise 2
int main() {
    char letter;
    int digit, num;

    cout << "Letter-Digit Converter" << '\n';
    cout << "\nPress '#' to stop converting" << '\n'; // Sentinel Variable
    // Prompt User to Input a Letter
    cout << "Enter a letter: ";
    cin >> letter;

    letter = tolower(letter); // Convert to Lowercase

    while (letter != '#') {
        cout << "Letter: " << letter << '\n'; // Display Letter
        num = static_cast<int>(letter) - static_cast<int>('a');

        // Input Handling: Valid Letter
        if (0 <= num && num < 26) {
            // Default: Letters A-R
            digit = (num / 3) + 2;

            // Input Handling: Letters S-V
            if (((num / 3 == 6) || (num / 3 == 7))  && (num % 3 == 0))
                digit = digit - 1;

            // Input Handling: Letters W-Z
            if (digit > 9)
                digit = 9;
            cout << "Telephone Digit: " << digit;
        } else {
            cout << "Error. Invalid Input" << '\n';
        }

        // Prompt Loop
        cout << "\n------------------";
        cout << "\nEnter a letter: ";
        cin >> letter;
        letter = tolower(letter); // Convert to Lowercase
    }

    return 0;
}