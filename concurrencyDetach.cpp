#include <iostream>
#include <thread>
using namespace std;

void printBackground() {
    cout << "This will run in the background." << endl;
}

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
    thread t1(printBackground);
    thread t2(printFirst);
    thread t3(printSecond);
    thread t4(printThird);

    t1.detach();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}