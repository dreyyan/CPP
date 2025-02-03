// 1. Print Today's Date
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    time_t seconds = time(0);
    struct tm datetime = *localtime(&seconds);
    cout << "Date: " << setw(2) << setfill('0') << datetime.tm_mon + 1 << " / " << setw(2) << setfill('0') << datetime.tm_mday << " / " << datetime.tm_year + 1900;
    return 0;
}
