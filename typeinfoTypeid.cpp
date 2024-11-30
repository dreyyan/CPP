#include <iostream>
using namespace std;

int main() {
    int number = 5;
    float fNumber = 5.5;
    cout << typeid(number).name();
    cout << typeid(fNumber).name();
    return 0;
}