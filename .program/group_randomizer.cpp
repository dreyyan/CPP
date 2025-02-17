#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void group_randomizer(vector<string> list_of_names) {
    int classSize = list_of_names.size();
    int groupSize, groupNumber = 1;

    cout << "Enter Group Size: ";
    cin >> groupSize;

    while (!list_of_names.empty()) {
        cout << "\nGroup " << groupNumber++ << ":\n";

        for (int i = 0; i < groupSize && !list_of_names.empty(); i++) {
            int seed = rand() % list_of_names.size();
            cout << list_of_names[seed] << "\n";
            list_of_names.erase(list_of_names.begin() + seed);
        }
    }
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
        "Tan", "Umadhay"
    };
    srand(time(0));

    group_randomizer(student_list);
    return 0;
}