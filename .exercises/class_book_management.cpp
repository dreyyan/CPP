#include <chrono>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <random>
#include <thread>
#include <string>
using namespace std;
// CC 203 - Exercise #1 [#8]
class bookType {
    /* ATTRIBUTES */
    string title, ISBN;
    unsigned int num_of_copies;

public:
    bookType(string title, string ISBN, unsigned int num_of_copies)
        : title(move(title)), ISBN(move(ISBN)), num_of_copies(num_of_copies) {} // Parameterized Constructor
    bookType()
        : title(""), ISBN(""), num_of_copies(0) {} // Default Constructor

    /* UTILS */
    void display_format(size_t length) {
        for (size_t i = 0; i < length; ++i) {
            cout << '-';
        }
        cout << '\n';
    } void clear_screen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    } void delay(int ms) {
        this_thread::sleep_for(chrono::milliseconds(ms));
    }

    /* METHODS */
    void search_book_by_title(bookType books[], int size, string title) {
        bool book_found = false;
        string book_ISBN;

        // Search for book
        for (int i = 0; i < size; ++i) {
            if (title == books[i].title) {
                book_found = true;
                book_ISBN = books[i].ISBN;
                break;
            }
        }

        cout << "* '" << title << "' ";
        if (book_found) {
            cout << "found! [ISBN: " << book_ISBN << "]\n";
        } else cout << "not found...\n";
    }

    void search_book_by_ISBN(bookType books[], int size, string ISBN) {
        bool book_found = false;
        string book_title;

        // Search for book
        for (int i = 0; i < size; ++i) {
            if (ISBN == books[i].ISBN) {
                book_found = true;
                book_title = books[i].title;
                break;
            }
        }

        cout << "* '" << ISBN << "' ";
        if (book_found) {
            cout << "found! [Title: " << book_title << "]\n";
        } else cout << "not found...\n";
    }

    void update_num_of_book_copies(int updated_num_of_copies) {
        cout << "* [" << title << "] # of copies: " << num_of_copies << " >> " << updated_num_of_copies << '\n';
        num_of_copies = updated_num_of_copies; // Update # of copies
    }
};
int main() {
    bookType books[100]; // Declare a 'bookType' array to process up to 100 books

    // Setup RNG
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 99); // Random index
    uniform_int_distribution<int> copies_dist(0, 9); // Random index

    // Array of values for randomization
    string book_title[100] = {
    "The Great Gatsby", "To Kill a Mockingbird", "1984", "Pride and Prejudice", "Moby-Dick",
    "The Catcher in the Rye", "War and Peace", "The Hobbit", "Crime and Punishment", "Brave New World",
    "The Lord of the Rings", "Jane Eyre", "The Brothers Karamazov", "Fahrenheit 451", "Wuthering Heights",
    "The Picture of Dorian Gray", "Dracula", "Les Miserables", "The Odyssey", "The Iliad",
    "Great Expectations", "The Divine Comedy", "Frankenstein", "A Tale of Two Cities", "Don Quixote",
    "The Count of Monte Cristo", "Anna Karenina", "Heart of Darkness", "The Old Man and the Sea", "The Stranger",
    "Catch-22", "Ulysses", "One Hundred Years of Solitude", "Beloved", "Slaughterhouse-Five",
    "The Sound and the Fury", "Lolita", "The Grapes of Wrath", "Brave New World", "A Clockwork Orange",
    "The Sun Also Rises", "Dune", "The Shining", "The Stand", "It",
    "Dr. Jekyll and Mr. Hyde", "The Metamorphosis", "On the Road", "The Road", "Blood Meridian",
    "The Call of the Wild", "Treasure Island", "The Jungle Book", "The Wind in the Willows", "Peter Pan",
    "Charlotte's Web", "Harry Potter and the Sorcerer’s Stone", "Harry Potter and the Chamber of Secrets",
    "Harry Potter and the Prisoner of Azkaban", "Harry Potter and the Goblet of Fire", "Harry Potter and the Order of the Phoenix",
    "Harry Potter and the Half-Blood Prince", "Harry Potter and the Deathly Hallows", "The Chronicles of Narnia", "Percy Jackson and the Lightning Thief",
    "Percy Jackson and the Sea of Monsters", "Percy Jackson and the Titan's Curse", "Percy Jackson and the Battle of the Labyrinth",
    "Percy Jackson and the Last Olympian", "The Maze Runner", "The Hunger Games", "Catching Fire", "Mockingjay",
    "Divergent", "Insurgent", "Allegiant", "The Fault in Our Stars", "Looking for Alaska",
    "Paper Towns", "An Abundance of Katherines", "Turtles All the Way Down", "The Alchemist", "The Book Thief",
    "The Giver", "Ender's Game", "The Hitchhiker's Guide to the Galaxy", "Good Omens", "American Gods",
    "The Name of the Wind", "The Wise Man’s Fear", "Eragon", "Eldest", "Brisingr",
    "Inheritance", "A Game of Thrones", "A Clash of Kings", "A Storm of Swords", "A Feast for Crows",
    "A Dance with Dragons", "The Shadow of the Wind"};
    string book_ISBN[100] = {
    "9780743273565", "9780061120084", "9780451524935", "9780141439518", "9781503280786",
    "9780316769488", "9781400079988", "9780547928227", "9780486415871", "9780060850524",
    "9780544003415", "9780141441146", "9780374528379", "9781451673319", "9780141439556",
    "9780141442464", "9780486411095", "9780451419430", "9780140268867", "9780140275360",
    "9780486415864", "9780140448955", "9780486282114", "9780486406510", "9780060934347",
    "9780140449266", "9781400033416", "9780486264646", "9780684801223", "9780679720201",
    "9780684833392", "9781840226355", "9780060883287", "9781400033416", "9780385333849",
    "9780679732242", "9780679720201", "9780143039433", "9780060850524", "9780345356791",
    "9780743273565", "9780345370773", "9780345453747", "9780450411437", "9780345453730",
    "9780141439686", "9780486282114", "9780140283297", "9780307387899", "9780679728740",
    "9781400030934", "9780142404676", "9781405274305", "9781405248498", "9781405221743",
    "9781405283511", "9780439708180", "9780439064873", "9780439136358", "9780439139601",
    "9780439358071", "9780439785969", "9780545010221", "9780064404990", "9780786838653",
    "9781423103349", "9781423103340", "9781423101468", "9781423101451", "9781423101475",
    "9780545425117", "9780545459068", "9780062315007", "9780062024022", "9780062024053",
    "9780062314992", "9780142424179", "9780142402511", "9780142414934", "9780142419014",
    "9780062315007", "9780142424179", "9780765326355", "9780812550702", "9780345391803",
    "9780060558123", "9780061054884", "9780553293357", "9780062472103", "9780345520685",
    "9780590353403", "9780553573404", "9780553579901", "9780553573428", "9780553801477",
    "9780553582024", "9780553582031", "9780553582048", "9780553805451", "9780385514231"};
    int num_of_copies[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int random_dist;

    cout << "[ * | BOOK MANAGEMENT SYSTEM | * ]\n";
    /* HOW TO USE CLASS: */
    // [1] Creating 'book' objects
    for (int i = 0; i < 100; ++i) {
        books[i] = bookType(
            book_title[dist(gen)],
            book_ISBN[dist(gen)],
            num_of_copies[copies_dist(gen)]
            );
    }
    // [2] Search book by title (Searches up to the first 25 books)
    cout << "\n[ SEARCH BOOK:TITLE SIMULATION(25) ]\n";
    for (int i = 0; i < 25; ++i) {
        random_dist = dist(gen);
        books[i].search_book_by_title(books, 25, book_title[random_dist]);
        books->delay(250);
    }
    // [3] Search book by ISBN (Searches up to the first 25 books)
    cout << "\n[ SEARCH BOOK:ISBN SIMULATION(25) ]\n";
    for (int i = 25; i < 50; ++i) {
        random_dist = dist(gen);
        books[i].search_book_by_ISBN(books, 25, book_ISBN[random_dist]);
        books->delay(250);
    }
    // [4] Update # of copies
    cout << "\n[ UPDATE # OF BOOK COPIES SIMULATION(25) ]\n";
    for (int i = 50; i < 75; ++i) {
        books[i].update_num_of_book_copies(copies_dist(gen));
        books->delay(250);
    }

    cout << "Press 'Enter' to continue...";
    cin.get();
    return 0;
}
