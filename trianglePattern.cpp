#include <iostream>
using namespace std;

int main() {
    int columns, rows = 0;

    cout << "Enter # of Columns: ";
    cin >> columns;

    for (int i = 0; i < columns; i++) {

        for (int j = 0; j <= i; j++) {
                cout << "*";
        }
        cout << "\n";
    }

    return 0;
}