#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    ///////////////////////////////  MAP  ///////////////////////////////
    map<int, string> students; // Key: Student ID, Value: Name

    // Insert elements into the map
    students[101] = "Alice";
    students[102] = "Bob";
    students[103] = "Charlie";

    // Alternative way to insert
    students.insert({104, "David"});

    // Display all elements (sorted by key)
    cout << "Student List:\n";
    for (const auto& entry : students) {
        cout << "ID: " << entry.first << ", Name: " << entry.second << endl;
    }

    // Find an element
    int searchID = 102;
    if (students.find(searchID) != students.end()) {
        cout << "Student ID " << searchID << " found: " << students[searchID] << endl;
    } else {
        cout << "Student ID " << searchID << " not found.\n";
    }

    // Erase an element
    students.erase(103);
    cout << "After erasing ID 103:\n";
    for (const auto& entry : students) {
        cout << "ID: " << entry.first << ", Name: " << entry.second << endl;
    }

    ///////////////////////////////  MULTIMAP  ///////////////////////////////
    multimap<int, string> grades; // Key: Grade, Value: Student Name

    // Insert elements (duplicate keys allowed)
    grades.insert({90, "Alice"});
    grades.insert({85, "Bob"});
    grades.insert({90, "Charlie"});
    grades.insert({80, "David"});
    grades.insert({85, "Eve"});

    // Display all elements (sorted by key)
    cout << "Grades List:\n";
    for (const auto& entry : grades) {
        cout << "Grade: " << entry.first << ", Student: " << entry.second << endl;
    }

    // Find all students with grade 85
    cout << "Students with grade 85:\n";
    auto range = grades.equal_range(85);
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << endl;
    }

    // Erase all students with grade 90
    grades.erase(90);
    cout << "After erasing all students with grade 90:\n";
    for (const auto& entry : grades) {
        cout << "Grade: " << entry.first << ", Student: " << entry.second << endl;
    }

    ///////////////////////////////  UNORDERED_MAP  ///////////////////////////////
    unordered_map<string, int> ages;
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages["Charlie"] = 22;

    // Access and modify values
    ages["Alice"] = 26;  // Modify value

    // Iterate through the map
    for (const auto& entry : ages) {
        cout << entry.first << " is " << entry.second << " years old.\n";
    }

    ///////////////////////////////  UNORDERED_MULTIMAP  ///////////////////////////////
    unordered_multimap<int, string> gradeBook;
    gradeBook.insert({90, "Alice"});
    gradeBook.insert({85, "Bob"});
    gradeBook.insert({90, "Charlie"});  // Duplicate key allowed

    // Display all elements
    for (const auto& entry : gradeBook) {
        cout << "Grade: " << entry.first << ", Student: " << entry.second << endl;
    }
    return 0;
}
