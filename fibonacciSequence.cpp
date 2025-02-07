#include <iostream>
using namespace std;
// Write a program that displays the sum of fibonacci sequence within n terms
void sum_of_fibonacci_sequence() {
    int num_of_terms, num1 = 1, num2 = 1, sum = 0, total_sum = 0;
    
    while (true) {
        // Prompt User to Enter # of Terms
        cout << "# of Terms: ";
        cin >> num_of_terms;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(100, '\n');
            cerr << "[ ERROR | Invalid Number ]\n";
        } else if (num_of_terms < 2) {
            cerr << "[ ERROR | # of terms must be greater than 2 ]\n";
        } else { break; }
    }

    total_sum = num1 + num2;

    // Solve for Sum of Fibonacci Numbers
    for (size_t i = 2; i < num_of_terms; ++i) {
        sum = num1 + num2;
        total_sum += sum;
        num1 = num2;
        num2 = sum;
    }

    // Display Sum of Fibonacci Numbers
    cout << "Sum = " << total_sum << '\n';
}

int main() {
    sum_of_fibonacci_sequence();
    return 0;
}
