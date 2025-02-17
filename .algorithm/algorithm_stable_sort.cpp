#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// stable_sort (sort, but preserves relative order of equal elements)
struct Student {
    string name;
    int score;
};

void algorithm_stable_sort(vector<Student> students) {
    stable_sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.score < b.score; // Sort in ascending order
    });
    for (const auto& student : students) {
        cout << student.name << ' ';
    }
}

int main() {
    vector<Student> students = {
        {"Aaron", 90},
        {"Bob", 88},
        {"Chad", 90},
        {"David", 89},
        {"Eric", 88}
    };
    algorithm_stable_sort(students);
    return 0;
}
