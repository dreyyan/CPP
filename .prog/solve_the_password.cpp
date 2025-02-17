#include <iostream>
#include <string>
#include <chrono>
#include <limits>
#include <memory>
#include <random>
#include <vector>
using namespace std;

vector<string> clues; // Store Clues Format

class Password {
public:
    // Attributes
    int difficulty = 1;

    // Function: Clear Console Screen
    void clear_screen() {
        // for Windows
        #ifdef _WIN32
        system("cls");
        // for Linux/Unix/MacOS
        #else
        system("clear");
        #endif
    }

    // Function: Return to Main Menu
    void return_to_menu() {
        char choice;

        // Conditional Break
        while (true) {
            // Prompt User to Return to Menu
            cout << "Return to Menu[y]?: ";
            cin >> ws; // Remove Whitespaces
            cin.get(choice);
            choice = tolower(choice); // Accept Only Lowercase Choice

            // Clearscreen or Display Error
            if (choice == 'y') {
                clear_screen();
                break;
            } else {
                cerr << "| Invalid Input | Please enter a valid choice\n";
            }
        }
    }

    // Function: Start the Game
    void start_game() {
        cout << "starting game...\n";
        int num_of_digits, num_of_clues;

        // Apply RNG
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(48, 57);

        // Settings According to Difficulty
        switch (difficulty) {
            case 1: num_of_digits = 3; break;
            case 2: num_of_digits = 4; break;
            case 3: num_of_digits = 5; break;
        }

        string password;
        int number;

        for (size_t i = 0; i < num_of_digits; i++) {
            password += static_cast<char>(dist(gen));
        }

        cout << " | CRACK THE PASSWORD |\n";
        cout << "------------------------\n";
        cout << password << '\n';
        cout << "------------------------\n";
    }

    // Function: Change Difficulty
    void change_difficulty() {
        cout << "changing difficulty...\n";
        int choice;

        // Conditional Break
        while (true) {
            // Display Difficulty Options
            cout << "| DIFFICULTY |\n";
            cout << "--------------\n";
            cout << "[1] || Easy\n";
            cout << "[2] || Medium\n";
            cout << "[3] || Hard\n";
            cout << "[4] || Exit\n";
            cout << "--------------\n";

            // Prompt to Change Difficulty
            cout << ">> ";
            cin >> choice;

            if (choice == 4) { clear_screen(); display_menu(); } // Back to Menu

            // Set & Display Difficulty
            cout << "Difficulty set to - '";
            if (choice == 1) { difficulty = 1; cout << "Easy\'\n"; break; }
            else if (choice == 2) { difficulty = 2; cout << "Medium\'\n"; break; }
            else if (choice == 3) { difficulty = 3; cout << "Hard\'\n"; break; }
            else { cerr << "| Invalid Input | Please enter a valid difficulty "; }
        }
    }

    // Function: Display Instructions for User
    void display_instructions() {
        cout << "displaying instructions...\n";
        cout << "             | CRACK THE PASSWORD |\n";
        cout << "------------------------------------------------\n";
        cout << "'Crack the Password' is a fun, logical mini-game\n"
                "that tests your critical thinking by \"Cracking\"\n"
                "the password using a set of clues. Enhance your\n"
                "password-cracking with varying difficulties.\n"
                "Good luck and have fun!\n";
        cout << "------------------------------------------------\n";
    }

    // Function: Display Main Menu
    void display_menu() {
        int choice;

        // Conditional Break
        while (true) {
            cout << "displaying menu...\n";
            cout << " | CRACK THE PASSWORD |\n";
            cout << "------------------------\n";
            cout << "[1] || Start\n";
            cout << "[2] || Change Difficulty\n";
            cout << "[3] || Instructions\n";
            cout << "[4] || Exit\n";
            cout << "------------------------\n";

            // Prompt User to Enter Choice
            cout << ">> ";
            cin >> choice;

            clear_screen(); // Clear Console Screen before Function Invocation
            switch (choice) {
                case 1:
                    start_game();
                break;
                case 2:
                    change_difficulty();
                break;
                case 3:
                    display_instructions();
                break;
                case 4:
                    cout << "exiting program...\n";
                exit(0);
                break;
                default:
                    cerr << "| Invalid Input | Please enter a valid choice\n";
                break;
            }
            return_to_menu(); // Prompt User to Return to Main Menu
        }
    }
};

int main() {
    unique_ptr<Password> start_program = make_unique<Password>();
    start_program->display_menu();
    return 0;
}