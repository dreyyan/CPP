#include <iostream>
using namespace std;

int main() {
    int withdrawalAmount;
    int accountBalance = 5000;

    cout << "Current Balance: " << accountBalance;
    cout << "\nEnter Withdrawal Amount: ";
    cin >> withdrawalAmount;

    try {
        if (withdrawalAmount < 20) {
            throw "The minimum withdrawal amount is $20";
        }

        else if (withdrawalAmount > 500) {
            throw "The maximum withdrawal amount is $500";
        }

        else if (withdrawalAmount > accountBalance) {
            throw accountBalance;
        }
        
        // Executes if No Exceptions
        accountBalance -= withdrawalAmount;
        cout << "Transaction Successful!\nCurrent Balance: $" << accountBalance;
    }
        
    catch (const char* msg) {
        cout << "Error: " << msg << endl;
    } catch (int currentBalance) {
        cout << "Error: Insufficient funds. Your balance is $" << currentBalance << "." << endl;
    }
    return 0;
}
