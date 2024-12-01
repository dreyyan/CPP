#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter a value: ";
    cin >> a;
    cout << "\nEnter b value: ";
    cin >> b;

    auto add = [a, b]() -> int {
        int sum = a + b;
        cout << "Sum = ";
        return sum;
    };

    cout << add();
    return 0;
}
