#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <unordered_map>
using namespace std;

struct Book {
    unique_ptr<string> author;
    int publication_year;
};

class Library {
    unordered_map<string, Book> book_list; // Stores books in library
    // Get current year
    time_t seconds = time(0);
    struct tm datetime = *localtime(&seconds);
    int current_year = datetime.tm_year + 1900;
public:
    Library() {} // Constructor
    void display_format(int length) {
        for (int i = 0; i < length; ++i) {
            cout << '-';
        } cout << '\n';
    }

    void clear_screen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear")
        #endif
    }

    void return_to_menu() {
        cout << "Press enter to continue...";
        cin.get();
        clear_screen();
    }

    void add_book() {
        string book_title, book_author;
        int book_publication_year;
        bool book_exists;

        while (true) {
            // Prompt user to enter book title to add
            book_exists = false;
            cout << "Enter book title: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, book_title);

            if (book_title.empty()) { // ERROR: Empty book title
                cout << "[ ERROR | Book title cannot be empty ]\n";
            }
            // Check if book with the specified book title already exists in the library
            for (const auto& book : book_list) {
                if (book_title == book.first) {
                    book_exists = true;
                    break;
                }
            }

            if (book_exists) { // ERROR: Existing book
                cout << "[ ERROR | Book already exists ]\n";
            } else break;
        }

        while (true) {
            // Prompt user to enter author
            cout << "Enter book author: ";
            getline(cin, book_author);

            if (book_author.empty()) { // ERROR: Empty author
                cout << "[ ERROR | Book title cannot be empty ]\n";
            } else break;
        }

        while (true) {
            // Prompt user to enter publication year
            cout << "Enter book publication year: ";
            cin >> book_publication_year;

            if (cin.fail()) { // ERROR: Type mismatch
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[ ERROR | Invalid publication year ]\n";
            } else if (current_year < book_publication_year) { // ERROR: Future publication year
                cout << "[ ERROR | Publication year cannot be greater than current year (" << current_year << ") ]\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
        }

        // Add book to book list
        book_list[book_title] = {make_unique<string>(book_author), book_publication_year};
    }

    void remove_book() {
        string book_title;
        bool book_exists;

        while (true) {
            clear_screen();
            // Display book list
            cout << "[ Book List ]\n";
            display_format(55);
            cout << "Title" << setw(24) << "Author" << setw(26) << "Publication Year" << '\n';
            display_format(55);
            for (const auto& book : book_list) {
                cout << book.first << setw(12) << *book.second.author << setw(10) << book.second.publication_year << '\n';
            } display_format(55);

            // Prompt user to enter book title to remove
            book_exists = false;
            cout << "Enter book title: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, book_title);

            if (book_title.empty()) { // ERROR: Empty book title
                cout << "[ ERROR | Book title cannot be empty ]\n";
            }

            auto it = book_list.find(book_title);
            if (it != book_list.end()) {
                book_list.erase(it); // Erase book from book list
                cout << "Book '" << book_title << "' removed from the library.\n";
                break;
            } else {
                cout << "[ ERROR | Book does not exist in the library ]\n";
            }
        }
    }

    void display_books() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Fix
        // Display book list
        cout << "[ Book List ]\n";
        display_format(55);
        cout << "Title" << setw(24) << "Author" << setw(26) << "Publication Year" << '\n';
        display_format(55);
        for (const auto& book : book_list) {
            cout << book.first << setw(12) << *book.second.author << setw(10) << book.second.publication_year << '\n';
        } display_format(55);
    }

    void display_library_menu() {
        int choice;
        while (true) {
            while (true) {
                cout << "[ Library Management System ]\n";
                display_format(29);
                cout << "1. Add Book\n2. Remove Book\n3. Display Books\n4. Exit\n";
                display_format(29);
                cout << "Enter your choice: ";

                cin >> choice;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "[ ERROR | Invalid choice ]\n";
                } else if (choice < 1 && choice > 4) {
                    cout << "[ ERROR | Invalid choice ]\n";
                } else break;
            }

            clear_screen();

            switch (choice) {
                case 1:
                    add_book();
                    break;
                case 2:
                    remove_book();
                    break;
                case 3:
                    display_books();
                    break;
                case 4:
                    cout << "exiting program...\n";
                exit(0);
                    break;
            } return_to_menu();
        }
    }
};
int main() {
    Library lib;
    lib.display_library_menu();
    return 0;
}