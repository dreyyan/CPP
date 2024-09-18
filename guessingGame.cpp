#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int num;
    int guess;

    // RNG
    srand(time(NULL));
    num = rand() % 100;

    cout << "1 - 100";
    cout << "\nGuess the number: ";
    cin >> guess;

    // Loop
    while (num != guess) {
        if (num > guess) {
            cout << "Higher\n";
            cout << "Guess the number: ";
            cin >> guess;
        }

        else if (num < guess) {
            cout << "Lower\n";
            cout << "Guess the number: ";
            cin >> guess;
        }
    }

    // Win Display
    cout << "\nYou guessed it! The number was " << num;

        return 0;
}
