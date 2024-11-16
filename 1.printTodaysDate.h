// 1. Print Today's Date
#include <iostream>
#include <ctime>
using namespace std;

void printTodaysDate() {
    time_t seconds = time(NULL);
    struct tm datetime = *localtime(&seconds);

    cout << "Date: " << datetime.tm_mon - 1 << "/" << datetime.tm_mday << "/" << datetime.tm_year + 1900;
}