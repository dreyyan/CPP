#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <list>
#include <set>
#include <deque>
using namespace std;

int main() {
    auto roll = []() { return rand() % 6 + 1; };

    // Insert container
    vector<int> container;

    // Add item
    container.push_back(roll());
    const int* address_of_original_item_zero = &(*container.begin());

    chrono::duration<double> duration_insert_time(0);

    do {
        // Get address of first item
        const int* address_of_item_zero = &(*container.begin());

        cout << "Contains " << container.size() << " elements\n";
        cout << "Took " << chrono::duration_cast<chrono::microseconds>(duration_insert_time).count() << "µs\n";

        for (const auto& i: container) {
            const int* address_of_item_x = &i; // Get memory address of current element
            int item_offset = address_of_item_x - address_of_item_zero; // Offset of current element and item
            int item_offset_original = address_of_item_x - address_of_original_item_zero; // Offset of current element and original item
            cout << "Offset [Original]: " << item_offset_original << '\n';
            cout << "Offset [Zero]: " << item_offset << '\n';
            cout << "Content: " << i << '\n';
        }

        auto first_time_period = chrono::high_resolution_clock::now();
        container.push_back(roll());
        auto second_time_period = chrono::high_resolution_clock::now();
        duration_insert_time = (second_time_period - first_time_period);
    } while (getc(stdin));
    return 0;
}
