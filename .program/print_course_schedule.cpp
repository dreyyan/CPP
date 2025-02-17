#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <tuple>
#include <vector>
using namespace std;
// Write a program that inputs a set of courses with their respective schedules[day & time] and displays it
void printCourseSchedule(unordered_map<string, tuple<string, string, string, string>> course_schedule) {
    int number = 1;
    // Display Schedule
    cout << "~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~` COURSE SCHEDULE `~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~\n";
    for (const auto& course : course_schedule) {
        cout << ' ' << number++ << ". " << right << setw(10)  << course.first << " || " << left << setw(33) << get<0>(course.second) << " || " << right << setw(11) << get<1>(course.second) << " | " << get<2>(course.second) << '\n';
    }
    cout << "~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~`~\n";
}

int main() {
    unordered_map<string, tuple<string, string, string, string>> course_schedule = {
        {"CIT 205", make_tuple("Human-Computer Interaction", "Mon / Wed", "7:00 - 9:00 A.M. | 7:00 - 10:00 A.M.", "ICT 301")},
        {"CWTS 102", make_tuple("Civic Welfare Training Service", "Sat", "3:00 - 6:00 P.M. | 3:00 - 6:00 P.M.", "FIELD")},
         {"ENG 110",make_tuple("Purposive Communication", "Mon / Wed", "3:00 - 6:00 P.M. | 3:00 - 6:00 P.M.", "QH 211")},
        {"CIT 201", make_tuple("Discrete Structures I", "Mon / Wed", "3:00 - 6:00 P.M. | 3:00 - 6:00 P.M.", "ICT 104")},
        {"CC 203", make_tuple("Computer Programming II", "Mon / Wed", "3:00 - 6:00 P.M. | 4:00 - 6:00 P.M.", "ICT 307")},
        {"SS 117", make_tuple("Living in the IT Era", "Tue / Thurs", "3:00 - 6:00 P.M. | 3:00 - 6:00 P.M.", "N/A")},
        {"NSCI 110", make_tuple("Science, Technology, and Society", "Tue / Thurs", "3:00 - 6:00 P.M. | 3:00 - 6:00 P.M.", "QH 213")},
        {"PATHFIT 2", make_tuple("Exercise-Based Fitness Activities", "Thurs", "3:00 - 6:00 P.M. | 3:00 - 6:00 P.M.", "N/A")}
    };
    printCourseSchedule(course_schedule);
    return 0;
}
