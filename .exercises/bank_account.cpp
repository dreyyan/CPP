#include <iostream>
#include <string>
using namespace std;
// CC 203: Lab Exercise #2
// [#2] Bank account class
class BankAccount {
    /* ATTRIBUTES */
    string accountNumber;
    double balance;
public:
    /* CONSTRUCTOR */
    BankAccount() {} // Default Constructor
    /* METHODS */
    // Add amount to balance
    void deposit(double amount) {
        balance += amount;
        cout << "$" << amount << " deposited successfully! [Balance: $" << balance << "]\n";
    }

    // Deduct amount from balance
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "[ ERROR | Amount exceeds remaining balance ]\n";
        } else {
            balance -= amount;
            cout << "$" << amount << " withdrawn successfully! [Balance: $" << balance << "]\n";
        }
    }

    // Get current balance
    void getBalance() {
        cout << "Current Balance: $" << balance << '\n';
    }
};

int main() {
    BankAccount account; // Instantiate 'BankAccount' object
    // Perform deposit
    account.deposit(500.50);
    // Perform withdrawal
    account.withdraw(250.75);
    // Display final balance
    account.getBalance();
    return 0;
}
