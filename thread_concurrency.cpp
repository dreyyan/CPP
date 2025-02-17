#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib> // For rand()

using namespace std;

void prepareOrder(int orderID) {
    int prepTime = rand() % 5 + 2; // Random prep time between 2-6 seconds
    cout << "* Order " << orderID << " is being prepared. (Time: " << prepTime << " sec)\n";
    this_thread::sleep_for(chrono::seconds(prepTime)); // Simulate preparation time
    cout << "/ Order " << orderID << " is ready!\n";
}

int main() {
    int orderCount = 1;
    char choice;

    cout << "| Welcome to FastFood Express! |\n";
    while (true) {
        cout << "Press 'o' to place an order or 'q' to quit: ";
        cin >> choice;

        if (choice == 'q') {
            cout << "* Closing the restaurant. No more orders!\n";
            break;
        } else if (choice == 'o') {
            cout << "* Order " << orderCount << " received!\n";
            thread t(prepareOrder, orderCount); // Start new thread
            t.detach(); // Run independently
            orderCount++;
        } else {
            cout << "X Invalid input! Try again.\n";
        }
    }

    cout << "* Waiting for remaining orders to be processed...\n";
    this_thread::sleep_for(chrono::seconds(10)); // Simulate time for background threads to complete
    cout << "* Restaurant closed!\n";

    return 0;
}
