// CC 202: Lab Exercise 3
// [#2] Fix the syntax errors found in the program
#include<iostream> // Inserted '#', replaced header file of 'iostream.h' to 'iostream', and removed ;
using namespace std; // Inserted the namespace declaration 'using namespace std' for access to standard library components
int main() { // Removed '0' inside the int main's parameter
    cout << "This is the second exercise of the lab activity. \n"; // Inserted missing '<' for the stream insertion operator
    cout << "There were some syntax errors in it that I fix them. \n"; // Inserted a " to enclose the string literal
    cout << "Syntax errors are due to the violation of the grammar of C++ \n"; // Changed 'count' to 'cout', '>>' to '<<', and inserted ; after the string literal
     return 0; // Inserted '0' and ';' after return to successfully terminate program
    } // No Semicolon