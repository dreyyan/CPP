#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
using namespace std;

struct Product {
    double price;
    int stock_quantity;
};

class Inventory {
    Inventory* ref_inventory; // Self-referential Pointer
    unordered_map<string, Product> inventory; // Stores product name /w product details
    unordered_map<string, int> purchase_list; // Stores product name & quantity to purchase
public:
    Inventory() : ref_inventory(this) {} // Constructor

    void display_format(int length) {
        for (int i = 0; i < length; ++i) {
            cout << '-';
        } cout << '\n';
    }

    void clear_screen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    void return_to_menu() {
        cout << "Press 'Enter' to continue...";
        cin.get(); // Wait for 'Enter' key
        clear_screen();
    }

    void add_product() {
        string product_name;
        double product_price;
        int product_stock_quantity;
        bool existing_product;

        while (true) { // Enter product name
            existing_product = false;
            // Prompt user to enter product name
            cout << "Enter product name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            getline(cin, product_name);

            if (product_name.empty()) { // ERROR: Empty product name
                cout << "[ ERROR | Product name cannot be empty ]\n";
            } else { // If product name inputted is not empty...
                // Check if the product already exists in the inventory
                for (const auto& product : inventory) {
                    if (product_name == product.first) {
                        existing_product = true;
                        break;
                    }
                }

                if (existing_product) { // ERROR: Existing product
                    cout << "[ ERROR | Product already exists ]\n";
                } else {
                    break;
                }
            }
        }

        while (true) { // Enter product price
            // Prompt user to enter product price
            cout << "Enter price: $";
            cin >> product_price;

            // ERROR: Type mismatch
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "[ ERROR | Invalid price ]\n";
            } else if (product_price <= 0) { // ERROR: Negative price
                cout << "[ ERROR | Price cannot be less than or equal to 0 ]\n";
            } else {
                break;
            }
        }

        while (true) { // Enter product stock quantity
            // Prompt user to enter stock quantity
            cout << "Enter stock quantity: ";
            cin >> product_stock_quantity;

            if (cin.fail()) { // ERROR: Type mismatch
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "[ ERROR | Invalid quantity ]\n";
            } else if (product_stock_quantity < 1) { // ERROR: Non-positive number
                cout << "[ ERROR | Quantity cannot be less than 1 ]\n";
            } else {
                break;
            }
        }

        // Add product to inventory records
        inventory[product_name] = {product_price, product_stock_quantity};
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Fix
        cout << "Product '" << product_name << "' added successfully!\n";
    }

    void update_stock() {
        string product_name;
        bool existing_product;
        int choice, amount;

        // Display list of products
        cout << "Product List:\n";
        for (const auto& product : inventory) {
            cout << "* " << product.first << " | $" << product.second.price << '\n';
        } display_format(20);

        while (true) {
            existing_product = false;
            // Prompt user to enter product name to update stock
            cout << "Update stock for: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, product_name);

            if (product_name.empty()) { // ERROR: Empty input
                cout << "[ ERROR | Product name must not be empty ]\n";
            }

            // Check if product name exists in the list
            for (const auto& product : inventory) {
                if (product_name == product.first) {
                    existing_product = true;
                    break;
                }
            }

            if (!existing_product) { // ERROR: Non-existing product
                cout << "[ ERROR | Product does not exist ]\n";
            } else break;
        }

        // Display current stock of product
        cout << product_name << "\nCurrent Stock: " << inventory[product_name].stock_quantity << '\n';
        // Prompt user to add or subtract stocks
        while (true) {
            cout << "1. Restock\n2. Deduct Stock\n> ";
            cin >> choice;

            if(cin.fail()) { // ERROR: Type mismatch
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[ ERROR | Invalid choice ]\n";
            } else if (choice != 1 && choice != 2) { // ERROR: Out-of-bounds choice
                cout << "[ ERROR | Invalid choice ]\n";
            } else break;
        }

        while (true) {
            // Prompt user to enter # of stocks to update
            cout << "Enter amount: ";
            cin >> amount;

            if (cin.fail()) { // ERROR: Type mismatch
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[ ERROR | Invalid amount ]\n";
            } else if (amount < 1) { // ERROR: Non-positive amount
                cout << "[ ERROR | Amount must be greater than 0 ]\n";
            } else break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Fix
        // Update stocks
        if (choice == 1) { // Restock
            inventory[product_name].stock_quantity += amount;
        } else { // Deduct stock
            inventory[product_name].stock_quantity -= amount;
        }

        // Display results
        cout << "Product stock of '" << product_name << "' successfully updated!\n";
        // Display updated stock of product
        cout << product_name << "\nUpdated Stock: " << inventory[product_name].stock_quantity << '\n';
    }

    void remove_product() {
        string product_name;
        bool product_exists;

        // Display list of products
        cout << "Product List:\n";
        for (const auto& product : inventory) {
            cout << "* " << product.first << '\n';
        } display_format(20);

        // Prompt user to enter product to remove
        while (true) {
            product_exists = false;
            // Prompt user to enter product name to remove
            cout << "Product Name: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, product_name);

            if (product_name.empty()) { // ERROR: Empty input
                cout << "[ ERROR | Product name cannot be empty ]\n";
            }

            // Check if product name exist in the list
            for (const auto& product : inventory) {
                if (product_name == product.first) {
                    product_exists = true;
                    break;
                }
            }

            if (!product_exists) { // ERROR: Non-existing product
                cout << "[ ERROR | Product does not exist ]\n";
            } else break;
        }

        // If product exists, remove the product
        inventory.erase(product_name);
        cout << "Product '" << product_name << "' removed from inventory\n";
    }

    void purchase_product() {
        string product_name;
        bool product_exists;

        // Display list of products
        cout << "Product List:\n";
        for (const auto& product : inventory) {
            cout << "* " << product.first << " | $" << product.second.price << '\n';
        } display_format(20);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Fix

        while (true) {
            product_exists = false;
            // Prompt user to enter product/s to purchase
            cout << "Enter product to purchase[type 'done' to finish]:\n> ";
            getline(cin, product_name);

            // If input is 'done', stop asking user for input
            if (product_name == "done") break;
            else if (product_name.empty()) { // ERROR: Empty input
                cout << "[ ERROR | Product name cannot be empty ]\n";
            }

            // Check if product name exists in the list
            for (const auto& product : inventory) {
                if (product_name == product.first) {
                    product_exists = true;
                    break;
                }
            }

            if (!product_exists) { // ERROR: Non-existing product
                cout << "[ ERROR | Product does not exist ]\n";
            } else {
                purchase_list[product_name]++; // Increment quantity of product in purchase list
                inventory[product_name].stock_quantity--; // Decrement quantity of stocks in inventory
            }
        }

        double total_bill; // Stores total bill after transaction
        // Display purchase list
        cout << "Purchase List:\n";
        for (const auto& item : purchase_list) {
            double total_amount = inventory[item.first].price * item.second; // Price * Quantity
            cout << item.first << '[' << item.second << "] - $" << total_amount << '\n';
            total_bill += total_amount;
        } display_format(20);
        cout << "Total Bill: $" << total_bill << '\n'; // Display total bill
    }

    void display_inventory() {
        cout << "Current Inventory:\n";
        display_format(33);
        cout << setw(10) << "Product" << setw(13) << "Price($)" << setw(10) << "Stock" << '\n';
        display_format(33);
        for (const auto& item : inventory) {
            cout << setw(10) << item.first << setw(9) << '$' << setw(4) << item.second.price << setw(10) << item.second.stock_quantity << '\n';
        }
        display_format(33);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void display_inventory_menu() {
        int choice;
        while (true) {
            while (true) {
                cout << "Welcome to the Inventory Management System!\n\n";
                cout << "1. Add Product\n";
                cout << "2. Update Stock\n";
                cout << "3. Remove Product\n";
                cout << "4. Purchase Product\n";
                cout << "5. Display Inventory\n";
                cout << "6. Exit\n\n";

                cout << "Enter your choice: ";
                cin >> choice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cerr << "[ ERROR | Invalid choice ]\n";
                } else break;
            } clear_screen();

            switch (choice) {
                case 1:
                    add_product();
                break;
                case 2:
                    update_stock();
                break;
                case 3:
                    remove_product();
                break;
                case 4:
                    purchase_product();
                break;
                case 5:
                    display_inventory();
                break;
                case 6:
                    cout << "exiting program...\n";
                exit(0);
                break;
            } return_to_menu();
        }
    }
};
int main() {
    Inventory inventory;
    inventory.display_inventory_menu();
    return 0;
}
