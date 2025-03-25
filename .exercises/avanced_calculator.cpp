#include <iostream>
#include <limits>
#include <string>
using namespace std;
// CC 203: Lab Exercise #2
// [#3] Calculator class
class Calculator {
public:
    /* CONSTRUCTOR */
    Calculator() {} // Default Constructor
    /* UTILS */
    static void clear_screen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    /* METHODS */
    static inline void add(double x, double y) {
        cout << x << " + " << y << " = " << (x + y) << '\n';
    }
    static inline void subtract(double x, double y) {
        cout << x << " - " << y << " = " << (x - y) << '\n';
    }
    static inline void multiply(double x, double y) {
        cout << x << " x " << y << " = " << (x * y) << '\n';
    }
    static inline void divide(double x, double y) {
        cout << x << " / " << y << " = " << (x / y) << '\n';
    }



    // Prompts user for input, perform calculation, and display result
    static void execute() {
        int choice;
        while (true) {
            cout << "Enter choice: ";
            cin >> choice;

            if (cin.fail()) { // ERROR: Type mismatch
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[ ERROR | Invalid number ]\n";
            } else if (choice < 1 || choice > 4) { // ERROR: Out-of-range choice
                cout << "[ ERROR | Out-of-range choice ]\n";
            } else break;
        }

        clear_screen();

        double num1, num2;
        // Prompt user to enter two numbers
        while (true) {
            cout << "Enter 1st number: ";
            cin >> num1;

            if (cin.fail()) { // ERROR: Type mismatch
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[ ERROR | Invalid first number ]\n";
            } else break;
        }

        while (true) {
            cout << "Enter 2nd number: ";
            cin >> num2;

            if (cin.fail()) { // ERROR: Type mismatch
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[ ERROR | Invalid second number ]\n";
            } else break;
        }

        clear_screen();

        switch (choice) {
            case 1:
                add(num1, num2); break;
            case 2:
                subtract(num1, num2); break;
            case 3:
                multiply(num1, num2); break;
            case 4:
                divide(num1, num2); break;
        }

        char choice1;
        // Suggest to the user to perform calculation again or exit the program
        while (true) {
            cout << "Would you like to perform another calculation[y/n]?\n";
            cout << " >> ";
            cin.ignore();
            cin.get(choice1);

            if (choice1 != 'y' && choice1 != 'n') {
                cout << "[ ERROR | Invalid choice ]\n";
            } else break;
        }

        if (choice1 == 'y') {
            clear_screen();
            menu();
        } else if (choice1 == 'n') {
            cout << "exiting program...\n";
            exit(0);
        }
    }

    // Display available operations & inline functions
    static void menu() {
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        execute();
    }
};

int main() {
    Calculator calculator; // Instantiate 'Calculator' object
    Calculator::menu(); // Call menu
    return 0;
}