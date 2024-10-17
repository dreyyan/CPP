#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

// TO IMPROVE:
// listBook();
// searchBook();

// Book > Fiction/Non-Fiction/E-Book/Magazine/Comic/Textbook

// Abstract Base Class: Book
class Book {
protected:
    string title, ISBN, genre, author;
    vector<string> bookList;
    bool availability = true;

public:
    Book(string bookTitle, string bookISBN, string bookGenre, string bookAuthor, bool isAvailable)
        : title(bookTitle), ISBN(bookISBN), genre(bookGenre), author(bookAuthor), availability(isAvailable) {
        cout << "\n>> Book Created";
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

    void editInfo() {
        cout << "\n>> Changing Info...";
        getTitle();
        getISBN();
        getGenre();
        getAuthor();
        cout << "\n>> Book Info Changed Successfully";
        displayInfo();
    }

    void getTitle() {
        cout << "\nTitle: " << title << " -> ";
        getline(cin, title);

        while (title.empty()) {
            cout << "\nInvalid title. Please try again.";
            getline(cin, title);
        }
    }

    void getISBN() {
        cout << "\nISBN: " << ISBN << " -> ";
        getline(cin, ISBN);

        while (ISBN.empty() || ISBN.length() != 13) {
            cout << "Invalid ISBN. Must have 13-digits.";
            getline(cin, ISBN);
        }
    }

    void getGenre() {
        cout << "\nGenre: " << genre << " -> ";
        getline(cin, genre);

        while (genre.empty()) {
            cout << "\nInvalid genre. Please try again.";
            getline(cin, genre);
        }
    }

    void getAuthor() {
        cout << "\nAuthor: " << author << " -> ";
        getline(cin, author);

        while (author.empty()) {
            cout << "\nInvalid author. Please try again.";
            getline(cin, author);
        }
    }

    virtual void borrowBook() = 0;
    virtual void returnBook() = 0;

    void listBook() {
        for (int i = 0; i < bookList.size(); i++) {
            cout << "\n" << i + 1 << ". " << bookList[i];
        }
    }

    void searchBook() {

    }

    void displayMenu() {
        int choice;
        cout << "\n1. Add Book";
        cout << "\n2. List Books";
        cout << "\n3. Borrow Book";
        cout << "\n4. Return Book";
        cout << "\n5. Search Book";
        cout << "\n6. Exit";
        cin >> choice;

        switch(choice) {
            case 1:
                Book::createBook();
            break;
            case 2:
                listBook();
            break;
            case 3:
                borrowBook();
            break;
            case 4:
                returnBook();
            break;
            case 5:
                searchBook();
            break;
            case 6:
                cout << "\nProgram Exited.";
            break;
            default:
                cout << "\nInvalid Input. Please try again.";
            cin >> choice;
            break;
        }
    }

    virtual ~Book() = default;  // Virtual Destructor
    static unique_ptr<Book> createBook(); // Declare createBook Method
};

// Derived Class: Fiction Book
class FictionBook : public Book {
public:
    FictionBook(string fictionBookTitle, string fictionBookISBN, string fictionBookGenre, string fictionBookAuthor, bool isAvailable)
        : Book(fictionBookTitle, fictionBookISBN, fictionBookGenre, fictionBookAuthor, isAvailable) {
        cout << "\n>> Book: Fiction";
        displayInfo();
    }

    void borrowBook() override {
        if (availability) {
            bookList.push_back(title);
            availability = false;
            cout << "\n>> Fiction Book [" << title << "] Borrowed";
        }
        else {
            cout << "\n>> Fiction Book [" << title << "] is already Borrowed";
        }
    }

    void returnBook() override {
        if (!availability) {
            auto bookToReturn = find(bookList.begin(), bookList.end(), title);
            if (bookToReturn != bookList.end()) {
                bookList.erase(bookToReturn);
            }
            availability = true;
            cout << "\n>> Fiction Book [" << title << "] Returned";
        }
        else {
            cout << "\n>> Fiction Book [" << title << "] is already Returned";
        }
    }

    /*void searchBook() {
        string bookToSearch;
        cout << "\nEnter ISBN: ";
        getline(cin, bookToSearch);


        for (size_t j = 0; j < bookList.size(); j++) {
            if (bookList[j].ISBN == bookToSearch) {
                cout << "\nBook Found! Title: " << bookList[j].title;
                return;
            }
        }

        // If no book is found
        cout << "\nBook not found!";
    }*/
};

// Derived Class: Non-Fiction Book
class NonFictionBook : public Book {
public:
    NonFictionBook(string nonFictionBookTitle, string nonFictionBookISBN, string nonFictionBookGenre, string nonFictionBookAuthor, bool isAvailable)
    : Book(nonFictionBookTitle, nonFictionBookISBN, nonFictionBookGenre, nonFictionBookAuthor, isAvailable) {
        cout << "\n>> Book: Non-Fiction";
        displayInfo();
    }

    void borrowBook() override {
        if (availability) {
            bookList.push_back(title);
            availability = false;
            cout << "\n>> Non-Fiction Book [" << title << "] Borrowed";
        }
        else {
            cout << "\n>> Non-Fiction Book [" << title << "] is already Borrowed";
        }
    }

    void returnBook() override {
        if (!availability) {
            auto bookToReturn = find(bookList.begin(), bookList.end(), title);
            if (bookToReturn != bookList.end()) {
                bookList.erase(bookToReturn);
            }
            availability = true;
            cout << "\n>> Non-Fiction Book [" << title << "] Returned";
        }
        else {
            cout << "\n>> Non-Fiction Book [" << title << "] is already Returned";
        }
    }
};

// Derived Class: E-Book
class EBook : public Book {
public:
    EBook(string EBookTitle, string EBookISBN, string EBookGenre, string EBookAuthor, bool isAvailable)
    : Book(EBookTitle, EBookISBN, EBookGenre, EBookAuthor, isAvailable) {
        cout << "\n>> Book: E-Book";
        displayInfo();
    }

    void borrowBook() override {
        if (availability) {
            bookList.push_back(title);
            availability = false;
            cout << "\n>> E-Book [" << title << "] Borrowed";
        }
        else {
            cout << "\n>> E-Book [" << title << "] is already Borrowed";
        }
    }

    void returnBook() override {
        if (!availability) {
            auto bookToReturn = find(bookList.begin(), bookList.end(), title);
            if (bookToReturn != bookList.end()) {
                bookList.erase(bookToReturn);
            }
            availability = true;
            cout << "\n>> E-Book [" << title << "] Returned";
        }
        else {
            cout << "\n>> E-Book [" << title << "] is already Returned";
        }
    }
};

// Derived Class: Magazine
class Magazine : public Book {
public:
    Magazine(string magazineTitle, string magazineISBN, string magazineGenre, string magazineAuthor, bool isAvailable)
    : Book(magazineTitle, magazineISBN, magazineGenre, magazineAuthor, isAvailable) {
        cout << "\n>> Book: Magazine";
        displayInfo();
    }

    void borrowBook() override {
        if (availability) {
            bookList.push_back(title);
            availability = false;
            cout << "\n>> Magazine [" << title << "] Borrowed";
        }
        else {
            cout << "\n>> Magazine [" << title << "] is already Borrowed";
        }
    }

    void returnBook() override {
        if (!availability) {
            auto bookToReturn = find(bookList.begin(), bookList.end(), title);
            if (bookToReturn != bookList.end()) {
                bookList.erase(bookToReturn);
            }
            availability = true;
            cout << "\n>> Magazine [" << title << "] Returned";
        }
        else {
            cout << "\n>> Magazine [" << title << "] is already Returned";
        }
    }
};

// Derived Class: Comic Book
class ComicBook : public Book {
public:
    ComicBook(string comicBookTitle, string comicBookISBN, string comicBookGenre, string comicBookAuthor, bool isAvailable)
    : Book(comicBookTitle, comicBookISBN, comicBookGenre, comicBookAuthor, isAvailable) {
        cout << "\n>> Book: Comic";
        displayInfo();
    }

    void borrowBook() override {
        if (availability) {
            bookList.push_back(title);
            availability = false;
            cout << "\n>> Comic [" << title << "] Borrowed";
        }
        else {
            cout << "\n>> Comic [" << title << "] is already Borrowed";
        }
    }

    void returnBook() override {
        if (!availability) {
            auto bookToReturn = find(bookList.begin(), bookList.end(), title);
            if (bookToReturn != bookList.end()) {
                bookList.erase(bookToReturn);
            }
            availability = true;
            cout << "\n>> Comic [" << title << "] Returned";
        }
        else {
            cout << "\n>> Comic [" << title << "] is already Returned";
        }
    }
};

// Derived Class: Textbook
class TextBook : public NonFictionBook {
public:
    TextBook(string textbookTitle, string textbookISBN, string textbookGenre, string textbookAuthor, bool isAvailable)
    : NonFictionBook(textbookTitle, textbookISBN, textbookGenre, textbookAuthor, isAvailable) {
        cout << "\n>> Book: Textbook";
        displayInfo();
    }

    void borrowBook() override {
        if (availability) {
            bookList.push_back(title);
            availability = false;
            cout << "\n>> Textbook [" << title << "] Borrowed";
        }
        else {
            cout << "\n>> Textbook [" << title << "] is already Borrowed";
        }
    }

    void returnBook() override {
        if (!availability) {
            auto bookToReturn = find(bookList.begin(), bookList.end(), title);
            if (bookToReturn != bookList.end()) {
                bookList.erase(bookToReturn);
            }
            availability = true;
            cout << "\n>> Textbook [" << title << "] Returned";
        }
        else {
            cout << "\n>> Textbook [" << title << "] is already Returned";
        }
    }
};

    static unique_ptr<Book> createBook() {
    string bookType;

    cout << "\n>> Creating Book...";
    cout << "\nFiction | Non-Fiction | E-Book | Magazine | Comic | Textbook";
    cout << "\nEnter Book Type(lowercase): ";
    cin >> bookType;
        while (bookType != "fiction" && bookType != "nonfiction" && bookType != "ebook" && bookType != "magazine" && bookType != "comic" && bookType != "textbook") {
            cout << "\nInvalid Book Type. Please enter in Lowercase /wo Spaces.\n";
            cout << "\nEnter Book Type(lowercase): ";
            cin >> bookType;
        }
    cin.ignore();

    string title, ISBN, genre, author;
    bool availability = true;

    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter ISBN: ";
    getline(cin, ISBN);
    while (ISBN.empty() || ISBN.length() != 13) {
        cout << "Invalid ISBN. Must have 13-digits.\n";
        getline(cin, ISBN);
    }
    cout << "\nEnter Genre: ";
    getline(cin, genre);
    cout << "\nEnter Author: ";
    getline(cin, author);

    if (bookType == "fiction") {
        return make_unique<FictionBook>(title, ISBN, genre, author, availability);
    }
    else if (bookType == "nonfiction") {
        return make_unique<NonFictionBook>(title, ISBN, genre, author, availability);
    }
    else if (bookType == "ebook") {
        return make_unique<EBook>(title, ISBN, genre, author, availability);
    }
    else if (bookType == "magazine") {
        return make_unique<Magazine>(title, ISBN, genre, author, availability);
    }
    else if (bookType == "comic") {
        return make_unique<ComicBook>(title, ISBN, genre, author, availability);
    }
    else if (bookType == "textbook") {
        return make_unique<TextBook>(title, ISBN, genre, author, availability);
    }

    else {
        cout << "\nInvalid Book Type.";
        return nullptr;
    }
}

unique_ptr<Book> startProgram() {
    cout << "| Library Management System |\n";
    return createBook();
}

int main() {
    unique_ptr<Book> book = startProgram();
    unique_ptr<Book> book1 = createBook();
    /*book1->listBook();*/
    return 0;
}
