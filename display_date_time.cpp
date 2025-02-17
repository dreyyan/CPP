#include <iostream>
#include <ctime>
using namespace std;
// Write a program that displays the date and time
void display_date_time(int mon, int day, int year, int hr, int min, int sec) {
    struct tm datetime;
    time_t timestamp; // Stores time in seconds since "Epoch"

    datetime.tm_year = year - 1900;
    datetime.tm_mon = mon;
    datetime.tm_mday = day;
    datetime.tm_hour = hr;
    datetime.tm_min = min;
    datetime.tm_sec = sec;
    datetime.tm_isdst = -1; // Daylight Saving Time(DST) [1 - Active | 0 - Inactive | -1 Auto ]

    timestamp = mktime(&datetime); // Normalizes tm (Invalid Date, Leap Years, DST)
    cout << ctime(&timestamp); // Convert date into readable format
}

int main() {
    display_date_time(2, 8, 2025, 1, 35, 0);
    return 0;
}
