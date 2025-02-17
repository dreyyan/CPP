#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
// CC 202: Lab Exercise 3
// [#1] Write a program that produces an output with the format:
//     My name is Adrian Dominic Tan
//                 Hello
//        Hello            Hello
// Hello           Hello           Hello
//        Hello            Hello
//                 Hello
// Bye
int main() {
  // Declare Variables
  string firstName = "Adrian Dominic";
  string lastName = "Tan";

  // Display Output
  cout << "My name is " << firstName << " " << lastName << endl;
  cout << setw(22) << "Hello\n";
  cout << setw(20) << "Hello\t\tHello\n";
  cout << setw(20) << "Hello\t\tHello\t\tHello\n";
  cout << setw(20) << "Hello\t\tHello\n";
  cout << setw(22) << "Hello\n";
  cout << "Bye";
  return 0;
}