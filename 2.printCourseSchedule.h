// 2. Print Course Schedule
#include <iostream>
#include <iomanip>
using namespace std;

void printCourseSchedule() {
    string day = "Monday";
    int hour1 = 9, hour2 = 11, hour3 = 2;
    string course1 = "Computer Science 101", course2 = "Physics 201", course3 = "Dance 153";

    cout << day << setw(4) << hour1 << ":00 " << course1;
    cout << day << setw(4) << hour2 << ":00 " << course1;
    cout << day << setw(4) << hour3 << ":00 " << course1;
}