#include <iostream>
using namespace std;
// Write a program that uses pointers to swap the values of two numbers
inline void swap_pointer(int* first_pointer, int* second_pointer) {
    int temp;
    temp = *second_pointer;
    *second_pointer = *first_pointer;
    *first_pointer = temp;

    // Display Swapped Values
    cout << "After Swap |\n";
    cout << "*1 = " << *first_pointer << '\n';
    cout << "*2 = " << *second_pointer << '\n';
}

int main() {
    int num1 = 1, num2 = 2;
    cout << "Before Swap |\n";
    cout << "*1 = " << num1 << '\n';
    cout << "*2 = " << num2 << '\n';
    swap_pointer(&num1, &num2);
    return 0;
}
