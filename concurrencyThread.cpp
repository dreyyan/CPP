#include <iostream>
#include <thread>
using namespace std;

void printFirst() {
    cout << "This should be printed first." << endl;
}

void printSecond() {
    cout << "This should be printed second." << endl;
}

void printThird() {
    cout << "This should be printed third." << endl;
}

int main() {
    thread t1(printFirst);
    thread t2(printSecond);
    thread t3(printThird);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}