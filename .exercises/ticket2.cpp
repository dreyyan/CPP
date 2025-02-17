#include<iostream>
using namespace std;
// CC 202: Lab Exercise 3
// [#6] Write a modified 'ticket.cpp' program that prompts the user for his/her age and displays the ticket cost according to age
int main()
{
    // Declare Variables
    int age, ticket;

    // Prompt User for Age as Input
        cout << "Please enter the age: \n";
        cin >> age;

    // Algorithm for Determining Ticket Price According to Age
    // Used OR(||) Operator for the Age Ranges and Logical Operators <= & >=
    if(age <= 8 || age >= 65) {
        ticket = 6;
    }
    else {
        ticket = 12;
    }

    // Display Results
    cout << "Your ticket costs: $" << ticket << endl;
    return 0;
}