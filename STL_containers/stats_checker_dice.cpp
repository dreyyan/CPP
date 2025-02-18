#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <list>
#include <set>
#include <deque>
using namespace std;

int main() {
    auto roll = []() { return rand() % 6 + 1; }; // Roll a dice

    // Insert container
    vector<int> container;
    // Add item
    container.push_back(roll());
    // Get address of original item
    const int* address_of_original_item_zero = container.data();
    //
    chrono::duration<double> duration_insert_time(0);

    do {
        // Get address of first item
        const int* address_of_item_zero = &(*container.begin());

        // Display element count and time used
        cout << "Count: " << container.size() << " element/s\t";
        cout << "Time: " << chrono::duration_cast<chrono::microseconds>(duration_insert_time).count() << "ms\n";

        for (const auto& i: container) {
            const int* address_of_item_x = &i; // Get memory address of current element
            int item_offset = address_of_item_x - address_of_item_zero; // Offset of current element and item
            int item_offset_original = address_of_item_x - address_of_original_item_zero; // Offset of current element and original item
            // Display original & zero offset, and value
            cout << "Offset [Original]: " << item_offset_original << '\t';
            cout << "Offset [Zero]: " << item_offset << '\t';
            cout << "Value: " << i << '\n';
        }
        auto first_time_period = chrono::high_resolution_clock::now();
        container.push_back(roll());
        auto second_time_period = chrono::high_resolution_clock::now();
        duration_insert_time = (second_time_period - first_time_period);
    } while (getc(stdin));
    return 0;
}
