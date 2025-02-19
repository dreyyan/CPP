#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Menu {
    unordered_map<string, double> menu_items = { // Store menu items /w prices
        {"pizza", 10.99},
        {"burger", 5.49},
        {"pasta", 8.79},
        {"soda", 2.50}
    };
    unordered_map<string, int> orders; // Store ordered item /w quantity
public:
    Menu() {} // Default Constructor

    void display_format(int length) {
        for (int i = 0; i < length; ++i) {
            cout << '-';
        } cout << '\n';
    }

    void display_menu_items() {
        cout << "|   M E N U   |\n";
        display_format(15);
        for (const auto& item : menu_items) { // Display menu items /w price
            cout << setw(6) << fixed << setprecision(2) << item.first << " | $" << item.second << '\n';
        }
    }

    void order_items() {
        string input_order;

        display_format(20);
        cout << "Enter items to order (type 'done' to finish):\n";
        while (true) { // Prompt user to enter order, typing 'done' if finished
            cout << "> ";
            getline(cin, input_order);
            transform(input_order.begin(), input_order.end(), input_order.begin(), ::tolower);

            if (input_order == "done") return; // Stop ordering process if 'done' is entered

            if (menu_items.count(input_order)) { // If menu item exists, add its quantity
                orders[input_order]++;
            } else { // ERROR: Non-existent menu item
                cout << "[ Invalid: Not on the menu ]\n";
            }
        }
    }

    void display_transaction() {
        double total_bill = 0; // Store total bill on checkout
        display_format(20);
        cout << "Your Order:\n";
        for (const auto& ordered_item : orders) { // Display transaction order
            double total_amount = menu_items[ordered_item.first] * ordered_item.second; // Store item cost * quantity
            cout << ordered_item.first << '[' << ordered_item.second << "] - $" << total_amount << '\n'; // Display menu item, quantity, and cost
            total_bill += total_amount; // Continuously add the total amount to total bill
        } display_format(20);
        cout << "Total Bill: $" << total_bill << '\n'; // Display total bill
    }
};
int main() {
    Menu menu;
    menu.display_menu_items(); //  [1] Display menu items
    menu.order_items(); // [2] Prompt user to order items
    menu.display_transaction(); // [3] Display receipt
    getc(stdin);
    return 0;
}
