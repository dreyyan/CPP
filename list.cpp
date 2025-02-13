#include <iostream>
#include <list>
#include <string>
using namespace std;
// Write a program that demonstrates how to manipulate lists
int main() {
    list<string> students = {"John", "Jack", "Francis"};

    // Access front and back elements
    cout << "Front: " << students.front() << '\n';
    cout << "Back: " << students.back() << '\n';

    // Modify the list
    students.push_front("Gregory");   // Add student to front
    students.pop_back();              // Remove student from back
    students.push_back("Liam");       // Add student to the back
    students.pop_front();             // Remove student from the front
    students.insert(students.begin(), "Anna"); // Insert element at specified position
    students.erase(students.begin()); // Remove element at specified position
    students.remove("John");          // Remove all elements specified in parameter
    // students.clear();              // Uncomment to remove all elements

    // Display each name in the list
    cout << "\nStudents in the list:\n";
    for (const string& name : students) {
        cout << "- " << name << '\n';
    }

    // Display list status
    cout << "\nThere are " << (students.empty() ? "no" : to_string(students.size())) 
         << " students in the list.\n";

    return 0;
}
