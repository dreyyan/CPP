#include <iostream>
#include <string>
// Class implementing a bank account
class BankAccount {
public:
	// Constructor
	BankAccount(const int cAccountNumber, double cBalance, std::string cAccountHolderName)
		: accountNumber(cAccountNumber), balance(cBalance), accountHolderName(cAccountHolderName) {}

	// Function to deposit money
	void Deposit() {
		double addMoney;
		
		std::cout << "| Deposit |\n";
		std::cout << "Current Balance: " << balance << "\n";
		std::cout << "Enter deposit amount: ";
		std::cin >> addMoney;
		
		if (addMoney > 0) {
		balance += addMoney;
				std::cout << "Transaction Successful. \n";
		std::cout << "New Balance: " << balance << "\n";
		}
		
		else {
		std::cout << "Transaction Failed - Enter a valid amount." << "\n";
		}
	}
	
	// Function to withdraw money
		void Withdraw() {
		double subtractMoney;
		
		std::cout << "| Withdraw |\n";
		std::cout << "Current Balance: " << balance << "\n";
		std::cout << "Enter withdrawal amount: ";
		std::cin >> subtractMoney;
		
		if (subtractMoney > 0 && subtractMoney < balance) {
		balance -= subtractMoney;
				std::cout << "Transaction Successful. \n";
		std::cout << "New Balance: " << balance << "\n";
		}
		
		else {
		std::cout << "Transaction Failed - Enter a valid amount.";
		}
	}
	
	// Function to display account details
	void displayAccountDetails() {
		std::cout << "Account Details | \n";
		std::cout << "Account Name: " << accountHolderName << "\n";
		std::cout << "Account Number: " << accountNumber << "\n";
		std::cout << "Balance: " << balance << "\n";
	}
	
private:
	const int accountNumber;
	double balance;
	const std::string accountHolderName;
};


int main() {
	BankAccount account1(1175910, 0, "Khryss Nicole Bermejo");
	
	account1.displayAccountDetails();
	account1.Deposit();
	account1.Withdraw();

	return 0;
}
