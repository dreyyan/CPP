#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    int integer = 5;
    float float_number = 5.5;
    double double_number = 20.55;
    char letter = 'A';
    bool is_true = true;

    cout << "int: " << typeid(integer).name() << '\n';
    cout << "float: " << typeid(float_number).name() << '\n';
    cout << "double: " << typeid(double_number).name() << '\n';
    cout << "char: " << typeid(letter).name() << '\n';
    cout << "bool: " << typeid(is_true).name() << '\n';
    return 0;
}