#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    list<string> students = {"John", "Jack", "Francis"};

    students.push_front("Gregory");
    students.pop_back();
    students.push_back("Liam");
    students.pop_front();

    for (const string i : students) {
        cout << i << "\n";
    }

    cout << students.empty();
    return 0;
}