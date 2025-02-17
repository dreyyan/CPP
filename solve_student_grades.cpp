#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
using namespace std;
// Write a program that solves the student's grade based on chosen grading system [ % / A-F / GPA / GWA ]
void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void display_format(size_t length) {
    for (size_t i = 0; i < length; ++i) {
        cout << '-';
    } cout << '\n';
}

// Used Enum for Readability and Type Safety
enum class Grading_System { PERCENTAGE = 1, LETTER, GPA, GWA };

void calculate_grades(unsigned int& subject_count, int choice) {
    switch (static_cast<Grading_System>(choice)) {
        case Grading_System::PERCENTAGE: {
            cout << "| PERCENTAGE-BASED GRADING |\n";
            display_format(28);
            double grade, shifted = 0;
            int total_grade = 0;

            // Prompt User to Enter Grades
            for (size_t i = 0; i < subject_count; ++i) {
                while (true) {
                    cout << i + 1 << " | Grade: ";
                    cin >> grade;

                    // ERROR: Negative Number or Greater than 100
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cerr << "[ ERROR | Grade must be a non-negative number no more than 100 ]\n";
                    }

                    shifted = grade * 10; // Shift 1 Decimal Place
                    // If remainder of grade shifted 1 decimal place is not 0, it has more than 1 decimal place
                    if (fmod(shifted, 1) != 0) {
                        cout << "[ ERROR | Grade must be at most 1 decimal place ]\n";
                    } else { // Round Up or Down Grade
                        grade = round(grade);
                        // Add Grade to Total
                        total_grade += grade;
                        break;
                    }
                }
            }

            // Get Average of Accumulative Grade
            total_grade /= subject_count;

            clear_screen();
            // Display Grade
            cout << "[ Total Grade ]: " << total_grade << '\n';
            cout << "[ Evaluation ]: ";
            // Display Evaluation
            if (total_grade >= 90 && total_grade <= 100) { // Grade: 90 - 100
                cout << "A\nExcellent work! You have demonstrated outstanding performance." ;
            } else if (total_grade >= 80 && total_grade < 90) { // Grade: 80 - 89
                cout << "B\nGreat job! You have a strong understanding of the material.";
            } else if (total_grade >= 70 && total_grade < 80) { // Grade: 70 - 79
                cout << "C\nGood effort! There's room for improvement, but you're on the right track.";
            } else if (total_grade >= 60 && total_grade < 70) { // Grade: 60 - 69
                cout << "D\nYou passed, but consider reviewing the material for better understanding.";
                // Grade: < 60
            } else { cout << "F\nUnfortunately, you did not pass. Don't give up! Study harder and try again."; }
            cout << '\n';
            break;
        }

        case Grading_System::LETTER: {
            cout << "| LETTER-BASED GRADING |\n";
            display_format(28);
            int GPA, total_GPA = 0;
            char grade_letter;
            string evaluation_message;

            // Prompt User to Enter Grades
            for (size_t i = 0; i < subject_count; ++i) {
                while (true) {
                    cout << i + 1 << " | GPA: ";
                    cin >> GPA;

                    // ERROR: Out-of-Range GPA
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cerr << "[ ERROR | Grade must be an integer ]\n";
                    } else if (GPA > 4 || GPA < 0) {
                        cout << "[ ERROR | GPA must be between 0.0 - 4.0 ]\n";
                    } else break;
                }
                // Add GPA to total GPA
                total_GPA += GPA;
            }

            // Get Average of Accumulative Grade
            total_GPA /= subject_count;

            clear_screen();

            // Evaluate Letter Grade
            if (total_GPA == 4) { // Grade: A
                grade_letter = 'A';
                evaluation_message = "Excellent work! You have demonstrated outstanding performance.";
            }
            else if (total_GPA == 3) { // Grade: B
                grade_letter = 'B';
                evaluation_message = "Great job! You have a strong understanding of the material.";
            }
            else if (total_GPA == 2) { // Grade: C
                grade_letter = 'C';
                evaluation_message = "Good effort! There's room for improvement, but you're on the right track.";
            }
            else if (total_GPA == 1) { // Grade: D
                grade_letter = 'D';
                evaluation_message = "You passed, but consider reviewing the material for better understanding.";
            }
            else { // Grade: F
                grade_letter = 'F';
                evaluation_message = "Unfortunately, you did not pass. Don't give up! Study harder and try again.";
            }

            // Display Grade
            cout << "[ Grade ]: " << total_GPA << '\n';
            cout << "[ Evaluation ]: ";
            // Display Evaluation
            cout << grade_letter << '\n' << evaluation_message << '\n';
            break;
        }

        case Grading_System::GPA: {
            cout << "| GPA |\n";
            display_format(28);
            int GPA, total_GPA = 0;

            // Prompt User to Enter Grades
            for (size_t i = 0; i < subject_count; ++i) {
                while (true) {
                    cout << i + 1 << " | GPA: ";
                    cin >> GPA;

                    // ERROR: Non-Integer
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cerr << "[ ERROR | Grade must be an integer ]\n";
                    } else if (GPA > 4 || GPA < 0) { // ERROR: Out-of-Range GPA
                        cout << "[ ERROR | GPA must be between 0.0 - 4.0 ]\n";
                    } else break;
                }
                // Add GPA to total GPA
                total_GPA += GPA;
            }

            // Get Average of Accumulative Grade
            total_GPA /= subject_count;

            clear_screen();
            // Display Grade
            cout << "[ Grade ]: " << total_GPA << ".0\n";
            cout << "[ Evaluation ]: ";

            // Display Evaluation
            if (total_GPA == 4) { // Grade: A
                cout << "A\nExcellent work! You have demonstrated outstanding performance." ;
            } else if (total_GPA == 3) { // Grade: B
                cout << "B\nGreat job! You have a strong understanding of the material.";
            } else if (total_GPA == 2) { // Grade: C
                cout << "C\nGood effort! There's room for improvement, but you're on the right track.";
            } else if (total_GPA == 1) { // Grade: D
                cout << "D\nYou passed, but consider reviewing the material for better understanding.";
            // Grade: F
            } else { cout << "F\nUnfortunately, you did not pass. Don't give up! Study harder and try again."; }
            cout << '\n';
            break;
        }

        case Grading_System::GWA: {
            cout << "| GWA |\n";
            display_format(28);
            int GWA, total_GWA = 0;

            // Prompt User to Enter Grades
            for (size_t i = 0; i < subject_count; ++i) {
                while (true) {
                    cout << i + 1 << " | GWA: ";
                    cin >> GWA;

                    // ERROR: Non-Integer
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cerr << "[ ERROR | Grade must be an integer ]\n";
                    } else if (GWA > 5 || GWA < 0) { // Out-of-Range GWA
                        cout << "[ ERROR | GWA must be between 0.0 - 5.0 ]\n";
                    } else break;
                }
                // Add GWA to total GWA
                total_GWA += GWA;
            }

            // Get Average of Accumulative Grade
            total_GWA /= subject_count;

            clear_screen();
            // Display Grade
            cout << "[ Grade ]: " << total_GWA << ".0\n";
            cout << "[ Evaluation ]: ";

            // Display Evaluation
            if (total_GWA == 1) { // Grade: A
                cout << "A\nExcellent work! You have demonstrated outstanding performance." ;
            } else if (total_GWA == 2) { // Grade: B
                cout << "B\nGreat job! You have a strong understanding of the material.";
            } else if (total_GWA == 3) { // Grade: C
                cout << "C\nGood effort! There's room for improvement, but you're on the right track.";
            } else if (total_GWA == 4) { // Grade: D
                cout << "D\nYou passed, but consider reviewing the material for better understanding.";
                // Grade: F
            } else { cout << "F\nUnfortunately, you did not pass. Don't give up! Study harder and try again."; }
            cout << '\n';
            break;
        }
    }
}

void solve_student_grades() {
    int num, choice;
    unsigned int subject_count;

    // Prompt User to Enter # of Subjects
    while (true) {
        cout << "# of Subjects: ";
        cin >> subject_count;

        // ERROR: Non-Positive Integer
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "[ ERROR | Invalid Number ]\n";
        } else { break; }
    }

    // Prompt User to Enter Chosen Grading System
    while (true) {
        num = 0;
        cout << setw(14) << ' ' << "[ Grading Systems ]\n";
        display_format(50);
        cout << '[' << ++num << "] | Percentage-Based (0 - 100%)\n";
        cout << '[' << ++num << "] | Letter-Based (A - F)\n";
        cout << '[' << ++num << "] | GPA (Grade Point Average || 0.0 - 4.0)\n";
        cout << '[' << ++num << "] | GWA (General Weighted Average || 5.0 - 1.0)\n";
        display_format(50);
        cout << ">> ";
        cin >> choice;

        // ERROR: Invalid Input
        if(cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clear_screen();
            cerr << "[ ERROR | Invalid Input ]\n";
        }

        if (choice >= 1 && choice <= num) break;
        else cerr << "[ ERROR | Out-of-Range Input ]\n";
    }

    clear_screen();
    calculate_grades(subject_count, choice);
}

int main() {
    solve_student_grades();
    return 0;
}
