#include <algorithm>
#include <cctype>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// IMPROVEMENTS:
// editInfo();

// Base Class: Book
class Book {
protected:
    string title, ISBN, genre, author;
    bool availability = true;

public:
    Book(string bookTitle, string bookISBN, string bookGenre, string bookAuthor, bool isAvailable)
        : title(bookTitle), ISBN(bookISBN), genre(bookGenre), author(bookAuthor), availability(isAvailable) {
        cout << "\n>>> Book Created";
        cout << "\nType: ";
    }

    void displayInfo() const {
        cout << "\n----------------------";
        cout << "\nTitle: " << title;
        cout << "\nISBN: " << ISBN;
        cout << "\nGenre: " << genre;
        cout << "\nAuthor: " << author;
        cout << "\nAvailable: " << (availability ? "Yes\n" : "No\n");
        cout << "----------------------";
    }

    string getTitle() const {
        return title;
    }

    string getISBN() const {
        return ISBN;
    }

    string getGenre() const {
        return genre;
    }

    string getAuthor() const {
        return author;
    }

    bool isAvailable() {
        return availability;
    }

    void setAvailability(bool isAvailable) {
        availability = isAvailable;
    }
};

// Derived Class: Fiction Book
class FictionBook : public Book {
public:
    FictionBook(string fictionBookTitle, string fictionBookISBN, string fictionBookGenre, string fictionBookAuthor, bool isAvailable)
        : Book(fictionBookTitle, fictionBookISBN, fictionBookGenre, fictionBookAuthor, isAvailable) {
        cout << "Fiction";
        displayInfo();
    }
};

// Derived Class: Non-Fiction Book
class NonFictionBook : public Book {
public:
    NonFictionBook(string nonFictionBookTitle, string nonFictionBookISBN, string nonFictionBookGenre, string nonFictionBookAuthor, bool isAvailable)
    : Book(nonFictionBookTitle, nonFictionBookISBN, nonFictionBookGenre, nonFictionBookAuthor, isAvailable) {
        cout << "Non-Fiction";
        displayInfo();
    }
};

// Derived Class: E-Book
class EBook : public Book {
public:
    EBook(string EBookTitle, string EBookISBN, string EBookGenre, string EBookAuthor, bool isAvailable)
    : Book(EBookTitle, EBookISBN, EBookGenre, EBookAuthor, isAvailable) {
        cout << "E-Book";
        displayInfo();
    }
};

// Derived Class: Magazine
class Magazine : public Book {
public:
    Magazine(string magazineTitle, string magazineISBN, string magazineGenre, string magazineAuthor, bool isAvailable)
    : Book(magazineTitle, magazineISBN, magazineGenre, magazineAuthor, isAvailable) {
        cout << "Magazine";
        displayInfo();
    }
};

// Derived Class: Comic Book
class ComicBook : public Book {
public:
    ComicBook(string comicBookTitle, string comicBookISBN, string comicBookGenre, string comicBookAuthor, bool isAvailable)
    : Book(comicBookTitle, comicBookISBN, comicBookGenre, comicBookAuthor, isAvailable) {
        cout << "Comic";
        displayInfo();
    }
};

// Derived Class: Textbook
class TextBook : public Book {
public:
    TextBook(string textbookTitle, string textbookISBN, string textbookGenre, string textbookAuthor, bool isAvailable)
    : Book(textbookTitle, textbookISBN, textbookGenre, textbookAuthor, isAvailable) {
        cout << "Textbook";
        displayInfo();
    }
};

// Base Class: Library
class Library {
public:
    vector<unique_ptr<Book>> bookList;
    vector<unique_ptr<string>> borrowHistory;
    vector<unique_ptr<string>> returnHistory;

    void createBook() {
        string bookType, bookTitle, bookISBN, bookGenre, bookAuthor;
        bool isAvailable = true;
        cout << "\n~ creating book...";
        // Book Type
        cout <<"\n[ Fiction / Non-Fiction / E-Book / Magazine / Comic / Textbook ]";
        cout << "\nBook Type: ";
        cin.ignore();
        getline(cin, bookType);

        while (bookType != "fiction" && bookType != "nonfiction" && bookType != "ebook" && bookType != "magazine" && bookType != "comic" && bookType != "textbook") {
            cout << "\nInvalid Book Type. Please enter book type in lowercase.\n";
            cout << "\nBook Type: ";
            getline(cin, bookType);
        }
        // Title
        cout << "\nTitle: ";
        getline(cin, bookTitle);
        while (bookTitle.empty()) {
            cout << "\nInvalid title. Please try again.";
            cout << "\nTitle: ";
            getline(cin, bookTitle);
        }
        // ISBN
        cout << "\nISBN(13-Digit): ";
        getline(cin, bookISBN);

        bool allNumbers = true;
        for (char c : bookISBN) {
            if (!isdigit(c)) {
                allNumbers = false;
                break;
            }
        }

        while (!allNumbers || bookISBN.empty() || bookISBN.length() != 13) {
            allNumbers = true;
            cout << "\nInvalid ISBN. Please enter a 13-digit ISBN.";
            cout << "\nISBN(13-Digit): ";
            getline(cin, bookISBN);
        }
        // Genre
        cout << "\nGenre: ";
        getline(cin, bookGenre);
        while (bookGenre.empty()) {
            cout << "\nInvalid genre. Please try again.";
            cout << "\nGenre: ";
            getline(cin, bookGenre);
        }
        // Author
        cout << "\nAuthor: ";
        getline(cin, bookAuthor);
        while (bookAuthor.empty()) {
            cout << "\nInvalid author. Please try again.";
            cout << "\nAuthor: ";
            getline(cin, bookAuthor);
        }

        unique_ptr<Book> newBook;
        if (bookType == "fiction") {
            bookList.push_back(make_unique<FictionBook>(bookTitle, bookISBN, bookGenre, bookAuthor, isAvailable));
        }
        else if (bookType == "nonfiction") {
            bookList.push_back(make_unique<NonFictionBook>(bookTitle, bookISBN, bookGenre, bookAuthor, isAvailable));
        }
        else if (bookType == "ebook") {
            bookList.push_back(make_unique<EBook>(bookTitle, bookISBN, bookGenre, bookAuthor, isAvailable));
        }
        else if (bookType == "magazine") {
            bookList.push_back(make_unique<Magazine>(bookTitle, bookISBN, bookGenre, bookAuthor, isAvailable));
        }
        else if (bookType == "comic") {
           bookList.push_back(make_unique<ComicBook>(bookTitle, bookISBN, bookGenre, bookAuthor, isAvailable));
        }
        else if (bookType == "textbook") {
            bookList.push_back(make_unique<TextBook>(bookTitle, bookISBN, bookGenre, bookAuthor, isAvailable));
        }
    }

    void displayBookList() {
        int number = 1;
        cout << "\nBook List |";
        cout << "\n----------------------";
        for (const auto& book : bookList) {
            cout << "\n" << number << ". " << book->getTitle() << "[" << book->getISBN() << "]";
            number++;
        }
        cout << "\n----------------------";
    }

    void borrowBook() {
        string bookISBN;
        bool bookFound = false;
        cout << "\n~ borrowing book...";
        displayBookList();
        cout << "\nEnter ISBN: ";
        cin.ignore();
        getline(cin, bookISBN);

        for (int i = 0; i < bookList.size(); i++) {
            if (bookISBN == bookList[i]->getISBN()) {
                bookFound = true;
                if (bookList[i]->isAvailable()) {
                    string bookTitle;
                    bookTitle = bookList[i]->getTitle();
                    borrowHistory.push_back(make_unique<string>(bookTitle));

                    bookList[i]->setAvailability(false);
                    cout << "\nBook [" << bookISBN << "] borrowed";
                    cout << "\nTitle: " << bookList[i]->getTitle();
                    }
                else {
                cout << "\nError: Book[" << bookISBN << "] is already borrowed.";
                }
                break;
            }
        }
        if (!bookFound) {
            cout << "\nError. Book[" << bookISBN << "] not found.";
            return;
        }
    }

    void returnBook() {
        string bookISBN;
        bool bookFound = false;

        cout << "\n~ returning book...";
        displayBookList();
        cout << "\nEnter ISBN: ";
        cin.ignore();
        getline(cin, bookISBN);

        for (int i = 0; i < bookList.size(); i++) {
            if (bookISBN == bookList[i]->getISBN()) {
                bookFound = true;
                if (bookList[i]->isAvailable()) {
                    cout << "\nError: Book[" << bookISBN << "]is already in library.";
                } else {
                    string bookTitle;
                    bookTitle = bookList[i]->getTitle();
                    returnHistory.push_back(make_unique<string>(bookTitle));

                    bookList[i]->setAvailability(true);
                    cout << "\nBook [" << bookISBN << "] returned successfully.";
                    cout << "\nTitle: " << bookList[i]->getTitle();
                }
                break;
            }
        }
        if (!bookFound) {
            cout << "\nError. Book[" << bookISBN << "] not found.";
            return;
        }
    }

    void searchBook() {
        string bookISBN;
        bool bookFound = false;

        cout << "\n~ Searching for book...";
        displayBookList();
        cout << "\nEnter ISBN: ";
        cin.ignore();
        getline(cin, bookISBN);

        for (const auto& book : bookList) {
            if (bookISBN == book->getISBN()) {
                bookFound = true;
                cout << "\nBook [" << bookISBN << "] found";
                cout << "\nTitle: " << book->getTitle();
                cout << "\nAvailable: " << (book->isAvailable() ? "Yes" : "No") << endl;
                break;
            }
        }

        if (!bookFound) {
            cout << "\nError. Book [" << bookISBN << "] not found." << endl;
        }
    }

    void printBorrowHistory() {
        cout << "\n~ Borrow History";
        cout << "\n----------------------";

        // Print Date
        time_t now = time(nullptr);
        // Convert to local time
        tm* local_time = localtime(&now);

        for (const auto& book : borrowHistory) {
            cout << "\nBook [" << *book << "] borrowed | " << (local_time->tm_mon + 1) << '-' << local_time->tm_mday  << '-' << (local_time->tm_year + 1900);
        }
        cout << "\n----------------------";
    }

    void printReturnHistory() {
        cout << "\n~ Return History";
        cout << "\n----------------------";
        // Print Date
        time_t now = time(nullptr);
        // Convert to local time
        tm* local_time = localtime(&now);

        for (const auto& book : returnHistory) {
            cout << "\nBook [" << *book << "] returned | " << (local_time->tm_mon + 1) << '-' << local_time->tm_mday  << '-' << (local_time->tm_year + 1900);
        }
        cout << "\n----------------------";
    }

    void displayMenu() {
        int choice;
        do {
            cout << "\n| LIBRARY MANAGEMENT SYSTEM |";
            cout << "\n[1] | Add Book";
            cout << "\n[2] | Edit Book Info";
            cout << "\n[3] | Show Booklist";
            cout << "\n[4] | Borrow Book/s";
            cout << "\n[5] | Return Book/s";
            cout << "\n[6] | Search Book/s";
            cout << "\n[7] | Borrow History";
            cout << "\n[8] | Return History";
            cout << "\n[9] | Exit";
            cout << "\n-> ";
            cin >> choice;

            switch(choice) {
                case 1:
                    createBook();
                    backToMenu();
                break;
                case 2:
                    /*editInfo();*/
                    backToMenu();
                break;
                case 3:
                    displayBookList();
                    backToMenu();
                break;
                case 4:
                    borrowBook();
                    backToMenu();
                break;
                case 5:
                    returnBook();
                    backToMenu();
                break;
                case 6:
                    searchBook();
                    backToMenu();
                break;
                case 7:
                    printBorrowHistory();
                    backToMenu();
                break;
                case 8:
                    printReturnHistory();
                    backToMenu();
                break;
                case 9:
                    cout << "\nProgram Exited.";
                    return;
                default:
                    cout << "\nInvalid Input. Please try again.";
                break;
            }
        } while(true);
    }

    void backToMenu() {
        char choice;
        cout << "\nReturn to menu[y/n]?: ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            return;
        }

        else if (choice == 'n' || choice == 'N') {
            cout << "\nProgram Exited.";
            exit(0);
        }
        else {
            cout << "\nInvalid Input.\n";
            cin >> choice;
        }
    }
};

int main() {
    unique_ptr<Library> startProgram = make_unique<Library>();
    startProgram->displayMenu();
}