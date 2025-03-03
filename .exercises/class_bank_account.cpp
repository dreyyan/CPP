#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <thread>
#include <string>
using namespace std;
// CC 203 - Exercise #1 [#7]
class bankAccount {
    /* PRIVATE ATTRIBUTES */
    string account_name, account_type;
    double account_balance, account_interest_rate;
public:
    static int account_number;
    int number; // Store unique account number;

    /* CONSTRUCTORS */
    bankAccount(string name, string type, double balance, double interest_rate)
        : account_name(name), account_type(type), account_balance(balance), account_interest_rate(interest_rate)
    { number = account_number++; } // Parameterized Constructor
    bankAccount() : account_name("N/A"), account_type("N/A"), account_balance(0.0), account_interest_rate(0.0)
    { number = account_number++; } // Default Constructor

    /* UTILS */
    void display_format(size_t length) {
        for (size_t i = 0; i < length; ++i) {
            cout << '-';
        }
        cout << '\n';
    } void clear_screen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    } static void delay(int ms) {
        this_thread::sleep_for(chrono::milliseconds(ms));
    }

    /* METHODS */
    void deposit(double amount) {
        if (amount <= 0) { // Invalid amount
            cout << "!| DEPOSIT ERROR | Amount must be greater than 0 ]\n";
            return;
        } else {
            account_balance += amount; // Add deposited amount to the account balance
            cout << "* Account #" << number << " >> Deposit: $" << setw(9) << amount << " [Balance: $" << account_balance << "]\n";
        }
    }

    void withdraw(double amount) {
        if (account_balance < amount) { // ERROR: Insufficient balance
            cout << "!| WITHDRAWAL ERROR | Insufficient balance: $" << account_balance << " ]\n";
            return;
        } else {
            account_balance -= amount; // Minus withdrawn amount from the account balance
            cout << "* Account #" << number << " >> Withdraw: $" << setw(8) << amount << " [Balance: $" << account_balance << "]\n";
        }
    }

    void add_simple_interest(int years) {
        double simple_interest = account_balance * (account_interest_rate * 0.01) * years; // Calculate for simple interest
        account_balance += simple_interest; // Add simple interest to the accoutn balance
        cout << "* Account #" << number << " >> S.I.[" << years << "yr/s.]: $" << setw(7) << simple_interest << " [Balance: $" << account_balance << "]\n";
    }

    void add_compound_interest(int years) {
        int times_per_year = 1;
        double rate = account_interest_rate / 100.0;
        double compound_amount = account_balance * pow(1 + (rate / times_per_year), times_per_year * years);
        double compound_interest = compound_amount - account_balance;
        account_balance = compound_amount;
        cout << "* Account #" << number << " >> C.I.[" << years << "yr/s.]: $" << setw(7) << compound_interest << " [Balance: $" << account_balance << "]\n";
    }


    void display_account_details() {
        cout << setw(8) << ' ' << "Account #" << number << '\n';
        display_format(30);
        cout << setw(15) << "Account Name: " << account_name << '\n';
        cout << setw(15) << "Account Type: " << account_type  << '\n';
        cout << setw(15) << "Balance: " << '$' << account_balance << '\n';
        cout << setw(15) << "Interest Rate: " << account_interest_rate << "%\n";
        display_format(30);
    }
};

int bankAccount::account_number = 100;

int main() {
    bankAccount customers[10]; // Declare a 'bankAccount' array to process up to 10 customers

    // Setup RNG
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 9); // Random index
    uniform_int_distribution<int> type_dist(0, 1); // Random index for account type
    uniform_int_distribution<int> year_dist(0, 4); // Random index for years(S.I.)

    // Array of values for randomization
    string first_name[10] = {
        "John", "Edward", "Alice", "Michael", "Sophia",
        "Daniel", "Olivia", "James", "Emma", "William"};
    string last_name[10] = {
        "Smith", "Johnson", "Brown", "Williams", "Jones",
        "Miller", "Davis", "Garcia", "Wilson", "Anderson"};
    string type[2] = {"Checking", "Savings"};
    double balance[10] = {0.00, 100.00, 300.00, 500.00, 1000.00, 1500.00, 2000.00, 2500.00, 5000.00, 10000.00};
    double interest_rate[10] = {0.50, 1.00, 1.50, 2.00, 2.50, 3.00, 5.00, 6.50, 7.50, 10.00};
    double random_amount[10] = {0.00, 5.00, 10.50, 25.00, 50.50, 75.50, 100.00, 1250.00, 2500.00, 5000.00};
    int years[5] = {1, 2, 3, 5, 8};

    cout << fixed << setprecision(2); // Set values format
    cout << "[ * | BANK MANAGEMENT SYSTEM | * ]\n";

    /* HOW TO USE CLASS: */
    // [1] Creating 'customer' objects
    for (int i = 0; i < 10; ++i) {
        customers[i] = bankAccount(
            first_name[dist(gen)] + ' ' + last_name[dist(gen)],
            type[type_dist(gen)], balance[dist(gen)], interest_rate[dist(gen)]
            );
    }

    // [2] Depositing a specified amount to the account balance
    cout << "[ DEPOSIT SIMULATION(5) ]\n";
    for (int i = 0; i < 5; ++i) {
        customers[i].deposit(random_amount[dist(gen)]);
        bankAccount::delay(500);
    } cout << '\n';

    // [3] Withdrawing a specified amount from the account balance
    cout << "[ WITHDRAWAL SIMULATION(5) ]\n";
    for (int i = 5; i < 10; ++i) {
        customers[i].withdraw(random_amount[dist(gen)]);
        bankAccount::delay(500);
    } cout << '\n';

    // [4] Add simple interest according to specified years
    cout << "[ SIMPLE INTEREST SIMULATION(5) ]\n";
    for (int i = 0; i < 5; ++i) {
        customers[i].add_simple_interest(years[year_dist(gen)]);
        bankAccount::delay(500);
    } cout << '\n';

    // [5] Add compound interest according to specified years
    cout << "[ COMPOUND INTEREST SIMULATION(5) ]\n";
    for (int i = 5; i < 10; ++i) {
        customers[i].add_compound_interest(years[year_dist(gen)]);
        bankAccount::delay(500);
    } cout << '\n';

    // [6] Display account details of all customers
    cout << "[ DISPLAY ACCOUNT DETAILS SIMULATION(10) ]\n";
    for (int i = 0; i < 10; ++i) {
        customers[i].display_account_details();
        bankAccount::delay(500);
    }

    cout << "Press 'Enter' to continue...";
    cin.get();
    return 0;
}
