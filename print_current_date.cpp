#include <ctime>
#include <iostream>
using namespace std;
// Write a program that displays the current date and time
int main() {
    time_t seconds = time(0);
    struct tm datetime = *localtime(&seconds);
    cout << "Date: " << datetime.tm_mon + 1 << " / " << datetime.tm_mday << " / " << datetime.tm_year + 1900;
    return 0;
}
