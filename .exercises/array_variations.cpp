#include <iostream>
#include <limits>
#include <string>
using namespace std;
// CC 203 - Exercise #1 [#2]
int main() {
    int choice, size;

    // a. Declare an array 'heights' of 10 components of type 'double'
    double heights[10] = { 5.2, 6.3, 5.8, 4.9, 5.2, 5.7, 6.7, 7.1, 5.10, 6.0 };
    // b. Declare an array 'weights' of 7 components of type 'int'
    int weights[7] = { 120, 125, 137, 140, 150, 180, 210 };
    // c. Declare an array 'specialSymbols' of type 'char'
    char specialSymbols[] = { '$', '#', '%', '@', '&', '!', '^' };
    // d. Declare an array 'seasons' of 4 components of type 'string'
    string seasons[4] = { "fall", "winter", "spring", "summer" };

    // e. Prompt user to enter which array to view
    while (true) {
        // Display list of choices
        cout << "[ ARRAY VARIATIONS ]\n";
        cout << "1. Heights\n";
        cout << "2. Weights\n";
        cout << "3. Special Symbols\n";
        cout << "4. Seasons\n";

        // Prompt user to enter choice
        cout << "View Array: ";
        cin >> choice;

        if (cin.fail()) { // ERROR: Type mismatch
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "[ ERROR | Invalid choice ]\n";
        } else if (choice < 1 || choice > 4) { // ERROR: Out-of-range choice
            cout << "[ ERROR | Out-of-range choice ]\n";
        } else break;
    }

    // f. Display array of choice
    switch (choice) {
        case 1: { // Display 'heights' array
            cout << "Heights: ";
            size = sizeof(heights) / sizeof(heights[0]);
            for (int i = 0; i < size; ++i) {
                cout << heights[i];
                if (i != size - 1) cout << ", ";
                else cout << ' ';
            }
        } break;
        case 2: { // Display 'weights' array
            cout << "Weights: ";
            size = sizeof(weights) / sizeof(weights[0]);
            for (int i = 0; i < size; ++i) {
                cout << weights[i];
                if (i != size - 1) cout << ", ";
                else cout << ' ';
            }
        } break;
        case 3: { // Display 'specialSymbols' array
            cout << "Special Symbols: ";
            size = sizeof(specialSymbols) / sizeof(specialSymbols[0]);
            for (int i = 0; i < size; ++i) {
                cout << specialSymbols[i];
                if (i != size - 1) cout << ", ";
                else cout << ' ';
            }
        } break;
        case 4: { // Display 'seasons' array
            cout << "Seasons: ";
            size = sizeof(seasons) / sizeof(seasons[0]);
            for (int i = 0; i < size; ++i) {
                cout << seasons[i];
                if (i != size - 1) cout << ", ";
                else cout << ' ';
            }
        } break;
    } cout << '\n';
    return 0;
}