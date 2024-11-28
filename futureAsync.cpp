#include <iostream>
#include <future>
using namespace std;

int main() {
    auto result = async(launch::async, [] { return 5; });
    cout << result.get(); // Print future object
    return 0;
}