#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
// Write a program that displays the current date and the current month's calendar with the current date checked out
void calendarFormat() {
    time_t seconds = time(NULL);
    struct tm datetime = *localtime(&seconds);

    // Display Current Date
    cout << "--------------------------------\n";
    cout << "Date | " << setw(2) << setfill('0') << datetime.tm_mon + 1 << " / " << setw(2) << setfill('0') << datetime.tm_mday << " / " << datetime.tm_year + 1900 << '\n';
    cout << setfill(' '); // Reset Fill
    int current_day = datetime.tm_mday;

    // Display Entire Calendar
    cout << "------------";
    switch(datetime.tm_mon + 1) {
        case 1:
            cout << "JANUARY";
            break;
        case 2:
            cout << "FEBRUARY";
            break;
        case 3:
            cout << "MARCH";
            break;
        case 4:
            cout << "APRIL";
            break;
        case 5:
            cout << "MAY";
            break;
        case 6:
            cout << "JUNE";
            break;
        case 7:
            cout << "JULY";
            break;
        case 8:
            cout << "AUGUST";
            break;
        case 9:
            cout << "SEPTEMBER";
            break;
        case 10:
            cout << "OCTOBER";
            break;
        case 11:
            cout << "NOVEMBER";
            break;
        case 12:
            cout << "DECEMBER";
            break;
    }
    cout << "------------" << endl;

    int dateCounter = 1;
    do {
        // If Current Date
        //if (dateCounter == current_day + 1)
        if (dateCounter == current_day) {
            cout << "/" << '\n';
            dateCounter++;
            continue;
        } 
        if (dateCounter % 7 != 0) { // Display Dates Except Saturday
            cout << setw(2) << dateCounter << " | ";
        } else { // Display Date for Saturday
            cout << setw(2) << dateCounter << endl;
        }
        dateCounter++;
    } while (dateCounter != 32);
    cout << endl << "--------------------------------";
}

int main() {
    calendarFormat();
    return 0;
}
