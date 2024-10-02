#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Abstract Base Class: Book
class Book {
protected:
    string title;
    string ISBN;
    string genre;
    string author;
    bool availability = true;

public:
    Book(string bookTitle, string bookISBN, string bookGenre, string bookAuthor, bool isAvailable)
        : title(bookTitle), ISBN(bookISBN), genre(bookGenre), author(bookAuthor), availability(isAvailable) {
        cout << "\n>> Book Created";
        displayInfo();
    }

    void displayInfo() const {
        cout << "\nTitle: " << title;
        cout << "\nISBN: " << ISBN;
        cout << "\nGenre: " << genre;
        cout << "\nAuthor: " << author;
        cout << "\nAvailable: " << (availability ? "Yes\n" : "No\n");
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

    virtual ~Book() = default;  // Virtual Destructor

    static unique_ptr<Book> createBook(); // Declare createBook Method
};

// Derived Class: Fiction Book
class FictionBook : public Book {
public:
    FictionBook(string fictionBookTitle, string fictionBookISBN, string fictionBookGenre, string fictionBookAuthor, bool isAvailable)
        : Book(fictionBookTitle, fictionBookISBN, fictionBookGenre, fictionBookAuthor, isAvailable) {
        cout << "\n>> Fiction Book Created";
        displayInfo();
    }

    void borrowBook() override {
        availability = false;
        cout << "\n>> Fiction Book [" << title << "] Borrowed";
    }

    void returnBook() override {
        availability = true;
        cout << "\n>> Fiction Book [" << title << "] Returned";
    }

};

// Derived Class: Non-Fiction Book
class NonFictionBook : public Book {
public:
    NonFictionBook(string nonFictionBookTitle, string nonFictionBookISBN, string nonFictionBookGenre, string nonFictionBookAuthor, bool isAvailable)
    : Book(nonFictionBookTitle, nonFictionBookISBN, nonFictionBookGenre, nonFictionBookAuthor, isAvailable) {
        cout << "\n>> Non-Fiction Book Created";
        displayInfo();
    }

    void borrowBook() override {
        availability = false;
        cout << "\n>> Non-Fiction Book [" << title << "] Borrowed";
    }

    void returnBook() override {
        availability = true;
        cout << "\n>> Non-Fiction Book [" << title << "] Returned";
    }

};

// Derived Class: E-Book
class EBook : public Book {
public:
    EBook(string EBookTitle, string EBookISBN, string EBookGenre, string EBookAuthor, bool isAvailable)
    : Book(EBookTitle, EBookISBN, EBookGenre, EBookAuthor, isAvailable) {
        cout << "\n>> E-Book Created";
        displayInfo();
    }

    void borrowBook() override {
        availability = false;
        cout << "\n>> E-Book [" << title << "] Borrowed";
    }

    void returnBook() override {
        availability = true;
        cout << "\n>> E-Book [" << title << "] Returned";
    }

};

// Derived Class: Magazine
class Magazine : public Book {
public:
    Magazine(string magazineTitle, string magazineISBN, string magazineGenre, string magazineAuthor, bool isAvailable)
    : Book(magazineTitle, magazineISBN, magazineGenre, magazineAuthor, isAvailable) {
        cout << "\n>> Magazine Created";
        displayInfo();
    }

    void borrowBook() override {
        availability = false;
        cout << "\n>> Magazine [" << title << "] Borrowed";
    }

    void returnBook() override {
        availability = true;
        cout << "\n>> Magazine [" << title << "] Returned";
    }

};

// Derived Class: Comic Book
class ComicBook : public Book {
public:
    ComicBook(string comicBookTitle, string comicBookISBN, string comicBookGenre, string comicBookAuthor, bool isAvailable)
    : Book(comicBookTitle, comicBookISBN, comicBookGenre, comicBookAuthor, isAvailable) {
        cout << "\n>> Comic Book Created";
        displayInfo();
    }

    void borrowBook() override {
        availability = false;
        cout << "\n>> Comic Book [" << title << "] Borrowed";
    }

    void returnBook() override {
        availability = true;
        cout << "\n>> Comic Book [" << title << "] Returned";
    }

};

// Derived Class: Textbook
class TextBook : public NonFictionBook {
public:
    TextBook(string textbookTitle, string textbookISBN, string textbookGenre, string textbookAuthor, bool isAvailable)
    : NonFictionBook(textbookTitle, textbookISBN, textbookGenre, textbookAuthor, isAvailable) {
        cout << "\n>> Textbook Created";
        displayInfo();
    }

    void borrowBook() override {
        availability = false;
        cout << "\n>> Textbook [" << title << "] Borrowed";
    }

    void returnBook() override {
        availability = true;
        cout << "\n>> Textbook [" << title << "] Returned";
    }

};

unique_ptr<Book> Book::createBook() {
    string bookType;

    cout << "\n>> Creating Book...";
    cout << "\nFiction | Non-Fiction | E-Book | Magazine | Comic | Textbook";
    cout << "\nEnter Book Type(lowercase): ";
    cin >> bookType;
    cin.ignore();

    string title, ISBN, genre, author;
    bool availability = true;

    cout << "\nEnter Title: "; getline(cin, title);
    cout << "\nEnter ISBN: "; getline(cin, ISBN);
    cout << "\nEnter Genre: "; getline(cin, genre);
    cout << "\nEnter Author: "; getline(cin, author);

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
    return Book::createBook(); // Create and return book
}

int main() {
    unique_ptr<Book> book = startProgram();
    book->borrowBook();
    book->returnBook();
    book->displayInfo();
    return 0;
}

