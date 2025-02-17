#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
// Write a program that displays a process delay and outputs the elapsed time in seconds
void timer(int seconds) {
    // Start Timer
    auto start_time = chrono::high_resolution_clock::now();

    // Display Output /w Delay
    cout << "loading...\n";
    this_thread::sleep_for(chrono::seconds(seconds));

    // End Timer
    auto end_time = chrono::high_resolution_clock::now();

    // Calculate Elapsed Time
    auto elapsed_time = chrono::duration_cast<chrono::seconds>(end_time - start_time).count();

    // Display Elapsed Time
    cout << "Elapsed Time: " << elapsed_time;
}

int main() {
    timer(3);
    return 0;
}
