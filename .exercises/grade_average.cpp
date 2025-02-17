#include <iostream>
using namespace std;
// CC 202: Lab Exercise 2
// [#5] Write a program that prompts the user to input 5 grades, calculates, and displays the user's total grade average
int main() {
    // Declare variables
    float grade1, grade2, grade3, grade4, grade5;
    float studentGrades[5] = {grade1, grade2, grade3, grade4, grade5}; // Used an Array to Enter Grade Values /w Set Size
    float sumGrade, averageGrade;
    float size = 5;

    // Takes input from user
    // Uses for loop to declare variable i /w a value of 0, and will run as long as i < 5, and increments the variable by 1 every time the program runs
    // The 'i' value is used to iterate over the array of studentGrades and calculate their sum
    for (int i = 0; i < 5; i++) {
        cout << "Enter Grade #" << i + 1 << ": ";
        cin >> studentGrades[i];
        sumGrade += studentGrades[i]; // '+=' shortcut is used instead of 'sumGrade = sumGrade + studentGrades[i];'
    }

    // Algorithm to calculate for the average grade
    averageGrade = sumGrade / size;

    // Display Results
    cout << "Total Average: " << averageGrade;

    return 0;
    }
