#include <iostream>
using namespace std;

int main() {
    try { // Try Block: Contains code that might throw an exception
        int numerator, denominator, quotient;

        // Prompt User to Enter Numerator and Denominator for Division
        cout << "Enter Numerator & Denominator:\n";
        cin >> numerator >> denominator;

        if (denominator == 0) {
            // Throw Statement: Raise exception when error occurs, error message[.what()]
            throw runtime_error("Division by 0 is not Allowed");
        }
        quotient = numerator / denominator;
        cout << "Result: " << quotient << '\n';
    } catch (const exception& e) { // Catch Block: Handle thrown exception
        cout << "[ ERROR | " << e.what() << " ]\n";
    }

    /* Benefits of Using exception[BASE] than logic/runtime_error[DERIVED]
    * Specific Error Handling
    * Better Debugging & Error Messages
    */

    /* Exception
     * |_logic_error
     *        |_domain_error | taking sqrt of negative number
     *        |_invalid_argument | non-numeric string to an integer
     *        |_length_error | exceed allowed object size
     *        |_out_of_range | accessing invalid index
     * |_runtime_error
     *        |_range_error | computation resulting in out-of-range value
     *        |_overflow_error | exceeding max value of data type
     *        underflow_error | exceeding min value of data type
     * OTHERS:
     * bad_alloc | fails to allocate memory
     * bad_cast | failed dynamic_cast
     * bad_typeid | typeid used on null pointer
     * bad_function_call | calling empty function
     * bad_weak_ptr | creating shared_ptr from expired weak_ptr
     */
    return 0;
}
