#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    string accountID;
    string accountName;
    double balance;
    vector<string> transactionHistory;

public:
    BankAccount(string accountID, string accountName, double balance)
        : accountID(accountID), accountName(accountName), balance(balance) {
        cout << "Account created successfully!";
        cout << "\nAccount Name: " << accountName;
        cout << "\nAccountID: " << accountID;
        cout << "\nCurrent Balance: $" << balance;
        printFormat();
    }

    void withdraw(double amount) {
        if (balance >= amount && amount > 0) {
            balance -= amount;
            cout << "\nSuccessfully Withdrawn $" << amount;
            printBalance();
            printFormat();
            transactionHistory.push_back("\nWithdrew $" + to_string(amount));
        }
        else {
            cout << "\nInvalid amount. Please try again.";
        }

    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "\nSuccessfully Deposited $" << amount;
            printBalance();
            printFormat();
            transactionHistory.push_back("Deposited $" + to_string(amount));
        }
        else {
            cout << "\nInvalid amount. Please try again.";
        }

    }

    void printBalance() const {
        cout << "\nCurrent Balance: $" << balance;
    }

    void printFormat() const {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~";
    }

    void printTransactionHistory() const {
        cout << "\n| Transaction History |";

        for (string transaction : transactionHistory) {
            cout << transaction << "\n";
        }

        printBalance();
    }

};

int main() {
    BankAccount account = {"B150RS29", "Adrian Dominic Tan", 500.50};
    account.withdraw(250.10);
    account.deposit(1000.20);
    account.printTransactionHistory();
    return 0;
}