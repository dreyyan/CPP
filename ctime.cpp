#include <iostream>
#include <ctime>
using namespace std;

int main() {
    struct tm datetime;
    time_t timestamp;

    datetime.tm_year = 2024 - 1900;
    datetime.tm_mon = 12 - 4;
    datetime.tm_mday = 18;
    datetime.tm_hour = 5;
    datetime.tm_min = 53;
    datetime.tm_sec = 0;

    datetime.tm_isdst = -1;

    timestamp = mktime(&datetime);
    cout << ctime(&timestamp);
    return 0;
}