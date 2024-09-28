#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Record {
protected:
    unique_ptr<string> name;
    unique_ptr<int> id;
public:
    Record(const string& name, int id)
        : name(make_unique<string>(name)), id(make_unique<int>(id)) {
        cout << "\n<< Record Created >>";
    }

    void displayDetails() {
        cout << "\nName: " << *name;
        cout << "\nID: " << *id;
    }
};

unique_ptr<Record> newRecord(const string& name, int id) {
    return make_unique<Record>(name, id);
}

int main() {
    unique_ptr<Record> record1 = newRecord("Adrian Tan", 1);
    record1->displayDetails();
    return 0;
}