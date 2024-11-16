#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

void studentGrades() {
    string name, evaluation;
    int score;
    double points, total, grade;
    while(true) {
        cin >> name >> points >> total;

        grade = trunc((points / total) * 100);
        if (grade > 90) {
            evaluation = "Excellent";
        } else if (grade >= 80 && grade < 90) {
            evaluation = "Well Done";
        } else if (grade >= 70 && grade < 80) {
            evaluation = "Good";
        } else if (grade >= 60 && grade < 70) {
            evaluation = "Needs Improvement";
        } else {
            evaluation = "Fail";
        }

        cout << name << ' ' << grade << "% " << points / total << ' ' << evaluation << endl;
    }

}