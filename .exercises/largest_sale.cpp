#include <iostream>
using namespace std;
// CC 203 Seatwork:
// Declare & initialize an array of 10 sales & determine the largest sale amount from the given sales
void display_largest_sale(const double sales[], int size) {
    double largest_sale = sales[0]; // Initialize variable to the first sale
    // Loop: Determine largest sale by comparison of values
    for (size_t i = 1; i < size; ++i) {
        if (sales[i] > largest_sale) { // If current sale is larger than the current largest sale...
            largest_sale = sales[i]; // New largest sale is the current sale
        }
    }
    // Display largest sale
    cout << "Largest Sale: $" << largest_sale << '\n';
}

int main() {
    double sales[10] = {12.50, 8.35, 19.60, 25.00, 14.00, 39.43, 35.90, 98.23, 66.65, 35.64}; // Initialize array for 10 sales
    int size = sizeof(sales) / sizeof(sales[0]); // Raw Implementation: Determine size of array
    display_largest_sale(sales, size); // Invoke function
    return 0;
}