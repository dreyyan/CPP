#include <iostream>
#include <future>
#include <chrono>
#include <thread>
using namespace std;

// Function to compute the square of a number
int computeSquare(int x) {
    cout << "* Computing square of " << x << "...\n";
    return x * x;
}

int main() {
    // Launch computeSquare(5) asynchronously
    future<int> result = async(launch::async, computeSquare, 5);
    cout << "* Doing other work while square is being computed...\n";

    // Retrieve the result (this blocks until the computation is done)
    int square = result.get();

    cout << "/ The square of 5 is: " << square << '\n';

    return 0;
}
