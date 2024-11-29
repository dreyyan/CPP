#include <iostream>
#include <ctime>
#include <unistd.h> // Sleep
using namespace std;

int main() {
    time_t start, end;
    time(&start);
    cout << "Processing, please wait...\n";
    sleep(3);
    time(&end);

    double elapsed_time = difftime(end, start);
    cout << "Elapsed Time: " << elapsed_time;
    return 0;
}