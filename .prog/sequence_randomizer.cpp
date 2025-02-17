#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

void display_space(int length) {
    for (int i = 0; i < length; ++i) {
        cout << ' ';
    }
}
void display_format(int length) {
    for (int i = 0; i < length; ++i) {
        cout << '-';
    } cout << '\n';
}

void sequence_randomizer(vector<string> list_of_students, string subject, string event, string date) {
    int size = list_of_students.size(); // Class list size

    // Generate Random Number Generator(RNG)
    random_device rd;
    mt19937 mt(rd());

    // Shuffle student list
    shuffle(list_of_students.begin(), list_of_students.end(), mt);

    // Display details
    display_space(19);
    cout << "[ DETAILS ]\n";
    display_format(47);
    cout << "Subject: " << subject << '\n';
    cout << "Event: " << event << '\n';
    cout << "Date: " << date << '\n';
    display_format(47);
    display_space(12);
    cout << "[ ORDER of PRESENTATION ]\n";
    display_format(47);

    // Display sequence of presentation
    for (int i = 0; i < size; ++i) {
        cout << setw(2) << i + 1 << ". " << list_of_students[i] << '\n';
    }
    display_format(47);
}

int main() {
    vector<string> student_list = {
        "Alconada", "Alojepan", "Andicoy",
        "Bearneza", "Besana", "Bragancia",
        "Caballero", "Canteras", "Chua",
        "Colada", "Dariagan", "Dizon",
        "Dorado", "Escorpiso", "Fermase",
        "Galan", "Hitalia", "Jaudian",
        "Labiscase", "Lawi", "Losanes",
        "Macahilig", "Miralles", "Murillo",
        "Nono", "Panes", "Penaranda",
        "Purzuelo", "Requina", "Salarza",
        "Saraet", "Socolar", "Solomon",
        "Tan", "Umadhay", "Villuga"
    };
    vector<string> irregular_students_list = {
        "Pendon"
    };
    // Add irregular students to the list
    for (const string& name : irregular_students_list) {
        student_list.push_back(name);
    }
    sequence_randomizer(student_list, "ENG 110", "Tongue Twister #1 - Foolish Young Fisher", "Feb. 24, 2025");
    return 0;
}
