#include <iostream>
#include <string>
#include <memory>
using namespace std;
// Write a program that defines a class that manipulates smart pointers
class Record {
protected:
    unique_ptr<string> name;
    unique_ptr<int> id;
public:
    Record(const string& recordName, int recordId)
        : name(make_unique<string>(recordName)), id(make_unique<int>(recordId)) {
        cout << "\n>>>> Record Created";
    }

    void displayInfo() {
        cout << "\nName: " << *name;
        cout << "\nID: " << *id;
    }

    static unique_ptr<Record> addRecord(const string& recordName, int id) {
        return make_unique<Record>(recordName, id);
    }
};

int main() {
    unique_ptr<Record> record1 = Record::addRecord("Adrian Tan", 117591120149);
    record1->displayInfo();
    return 0;
}
