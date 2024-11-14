// Exercise 8
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // RNG Seed
    int randomNumber = rand() % 100 + 1; // Generate Random Number
    int guess, attempts = 0;

    cout << "| GUESS THE NUMBER |" << endl;
    cout << "Guess the number from 1-100 (5 Attempts)" << endl;

    while (true) {
        cout << "\n>> ";
        cin >> guess;

        if (guess > randomNumber) {
            cout << "Too high!" << endl;
        } else if (guess < randomNumber) {
            cout << "Too low!" << endl;
        } else {
            cout << "You guessed it, the number was... " << guess << "!" << endl;
            break;
        }
        attempts++;
        if (attempts == 5) {
            cout << "You ran out of attempts! The number was..." << randomNumber << ". Better luck next time!" << endl;
            break;
        } else {
            cout << 5 - attempts << " attempt/s left...";
        }
    }

    return 0;
}