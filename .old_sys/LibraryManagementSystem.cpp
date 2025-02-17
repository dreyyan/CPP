// Library Management System - LibraryItem, Book, Magazine, DVD
#include <iostream>
#include <string>
using namespace std;

// Base Class: Library Item
class LibraryItem {
public:
    LibraryItem(string title, int itemID) : title(title), itemID(itemID) {}

    void displayInfo() const {
        cout << "Title: " << title;
        cout << "\nitemID: " << itemID << "\n";
    }

private:
    string title;
    int itemID;
};

// Derived Class: Book
class Book : public LibraryItem {
public:
    Book(string title, int itemID, string author, int numberOfPages)
    : LibraryItem(title, itemID), author(author), numberOfPages(numberOfPages) {}

    void displayInfo() const {
        LibraryItem::displayInfo();
        cout << "\nAuthor: " << author;
        cout << "\nNumber of Pages: " << numberOfPages << "\n";
    }

private:
    string author;
    int numberOfPages;
};

// Derived Class: Magazine
class Magazine : public LibraryItem {
public:
    Magazine(string title, int itemID, int issueNumber, string publicationMonth)
    : LibraryItem(title, itemID), issueNumber(issueNumber), publicationMonth(publicationMonth) {}

    void displayInfo() const {
        LibraryItem::displayInfo();
        cout << "\nIssue Number: " << issueNumber;
        cout << "\nMonth Published: " << publicationMonth << "\n";
    }

private:
    int issueNumber;
    string publicationMonth;
};

// Derived Class: DVD
class DVD : public LibraryItem {
public:
    DVD(string title, int itemID, int duration, string genre)
    : LibraryItem(title, itemID), duration(duration), genre(genre) {}

    void displayInfo() const {
        LibraryItem::displayInfo();
        cout << "\nDuration(min.): " << duration;
        cout << "\nGenre: " << genre << "\n";
    }

private:
    int duration;
    string genre;
};

void displayCommands(const LibraryItem& item, const Book& book, const Magazine& magazine, const DVD& dvd) {
    int choice;

    cout << "1 - Display Library Item\n";
    cout << "2 - Display Book\n";
    cout << "3 - Display Magazine\n";
    cout << "4 - Display DVD\n";
    cout << "5 - Exit\n";
    cout << ">>>  ";
    cin >> choice;

    switch(choice) {
        case 1:
            item.displayInfo();
            displayCommands(item, book, magazine, dvd);
        break;
        case 2:
            book.displayInfo();
            displayCommands(item, book, magazine, dvd);
        break;
        case 3:
            magazine.displayInfo();
            displayCommands(item, book, magazine, dvd);
        break;
        case 4:
            dvd.displayInfo();
            displayCommands(item, book, magazine, dvd);
        break;
        case 5:
            cout << "Exit successful.";
        return;
        default:
            cout << "Invalid Input.";
    }
}

// Main Function
int main() {
    cout << "| Library Management System |\n";

    LibraryItem item = {"Unknown", 1};
    Book book = {"Chess Book", 2, "Hans Niemann", 451};
    Magazine magazine = {"New York Styles", 3, 1042, "July 2024"};
    DVD dvd = {"Fantastic Beasts", 4, 32, "Sci-Fi"};

    displayCommands(item, book, magazine, dvd);
    return 0;
}
