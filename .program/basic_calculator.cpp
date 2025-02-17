#include <iostream>
#include <limits>
#include <memory>
#include <string>
using namespace std;

class Calculator {
    char operation = '+';
    double num1 = 1, num2 = 2;
    double result;
public:
    Calculator() {} // Default Constructor

    // Function: Clear Screen
    void clear_screen() {
        #ifdef _WIN32
        system("cls");
        #else
        system("clear");
        #endif
    }

    void display_result() {
        cout << num1 << ' ' << operation << ' ' << num2 << ' ' << '=' << ' ' << result << '\n';
    }

    // Operation Functions
    void do_addition() {
        cout << "performing addition...\n";
        result = num1 + num2;
        operation = '+';
    }
    void do_subtraction() {
        cout << "performing subtraction...\n";
        result = num1 - num2;
        operation = '-';
    }
    void do_multiplication() {
        cout << "performing multiplication...\n";
        result = num1 * num2;
        operation = '*';
    }
    void do_division() {
        cout << "performing divison...\n";
        result = num1 / num2;
        operation = '/';
    }
    void do_modulus() {
        cout << "performing modulus...\n";
        result = static_cast<int>(num1) % static_cast<int>(num2);
        operation = '%';
    }
    void input_numbers() {
        cout << "inputting numbers...\n";

        // Prompt User to Enter First Number
        do {
            cout << "1st Number: ";
            cin >> num1;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "| Invalid Input | Please enter a valid number\n";
            }
        } while (cin.fail());

        // Prompt User to Enter Second Number
        do {
            cout << "2nd Number: ";
            cin >> num2;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "| Invalid Input | Please enter a valid number\n";
            }
        } while (cin.fail());

        cout << "...number inputted successfully!\n";
    }

    void return_to_menu() {
        while (true) {
            char choice;
            cout << "return to menu[y]?: ";
            cin.ignore();
            cin.get(choice);

            if (choice == 'y') {
                clear_screen();
                break;
            } else {
                cerr << "| Invalid Input | Please enter a valid choice\n";
            }
        }
    }

    // Functions
    void display_menu() {
        int choice;
        while (true) {
            cout << "[ BASIC CALCULATOR ]\n";
            cout << "--------------------\n";
            cout << "[1] || Add\n";
            cout << "[2] || Subtract\n";
            cout << "[3] || Multiply\n";
            cout << "[4] || Divide\n";
            cout << "[5] || Remainder\n";
            cout << "[6] || Input Numbers\n";
            cout << "[7] || Exit\n";
            cout << "--------------------\n";
            // Prompt User to Enter Choice
            cout << ">> ";
            cin >> choice;

            // Invoke Functions According to Choice
            switch (choice) {
                case 1:
                    clear_screen();
                    do_addition();
                    display_result();
                break;
                case 2:
                    clear_screen();
                    do_subtraction();
                    display_result();
                break;
                case 3:
                    clear_screen();
                    do_multiplication();
                    display_result();
                break;
                case 4:
                    clear_screen();
                    do_division();
                    display_result();
                break;
                case 5:
                    clear_screen();
                    do_modulus();
                    display_result();
                break;
                case 6:
                    clear_screen();
                    input_numbers();
                break;
                case 7:
                    cout << "exiting program...\n";
                    exit(0);
                break;
            }
            return_to_menu();
        }
    }
};

int main() {
    unique_ptr<Calculator> start_program = make_unique<Calculator>();
    start_program->display_menu();
    return 0;
}
