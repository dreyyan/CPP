#include <iostream>
using namespace std;
// Write a Program that uses a lambda function to add two numbers
int main() {
    int num1 = 1, num2 = 2;
    auto add = [num1, num2] () -> int {
        // Can Explicitly Specify Return Type | Ex.: (int)num1 + num2;
        return num1 + num2;
    };

    cout << num1 << " + " << num2 << " = " << add();
    return 0;
}

/* Syntax
 * auto lambda_name = [ capture list ] (parameters) -> return_type { function_body }; */
