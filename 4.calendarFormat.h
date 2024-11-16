#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

void calendarFormat() {
    time_t seconds = time(NULL);
    struct tm datetime = *localtime(&seconds);

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
        if (dateCounter % 7 != 0) {
            cout << setw(2) << dateCounter << " | ";
        } else {
            cout << setw(2) << dateCounter << endl;
        }
        dateCounter++;
    } while (dateCounter != 32);
    cout << endl << "--------------------------------";
}