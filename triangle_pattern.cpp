#include <iostream>
using namespace std;

int main() {
    // Prompt User to Enter # of Columns
    int num_of_columns;
    while (true) {
        cout << "Enter # of Columns: ";
        cin >> num_of_columns;

        // Error Message
        if (num_of_columns < 1) {
            cerr << "[ Invalid Input | Number of columns must be at least 1 ]\n";
        } else { break; }
    }

    // Display Triangle
    for (size_t i = 1; i <= num_of_columns; ++i) {
        for (size_t j = 0; j < i; ++j) {
            cout << '*';
        } cout << '\n';
    }

    return 0;
}
