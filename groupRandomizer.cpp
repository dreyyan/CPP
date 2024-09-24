#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main() {
    vector<string> studentList = {"Alconada", "Alojepan", "Andicoy", "Bearneza", "Besana", "Bragancia", "Caballero", "Canteras", "Chua", "Colada", "Dariagan", "Dizon", "Dorado", "Escorpiso", "Fermase", "Galan", "Hitalia", "Jaudian", "Labiscase", "Lawi", "Losanes", "Macahilig", "Miralles", "Murillo", "Nono", "Panes", "Penaranda", "Purzuelo", "Requina", "Salarza", "Saraet", "Socolar", "Solomon", "Tan", "Umadhay"};
    int classSize = studentList.size();
    int groupSize;
    int groupNumber = 1;
    srand(time(0));

    cout << "Enter Group Size: ";
    cin >> groupSize;

    while (!studentList.empty()) {
        cout << "\nGroup " << groupNumber++ << ":\n";

    for (int i = 0; i < groupSize && !studentList.empty(); i++) {
            int seed = rand() % studentList.size();
            cout << studentList[seed] << "\n";
            studentList.erase(studentList.begin() + seed);
        }
    }
    return 0;
}