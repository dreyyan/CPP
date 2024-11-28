#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers1 = {1, 2, 3, 4, 5};
    vector<int> numbers2 = {3, 4, 5, 6, 7};
    vector<int> difference;
    set_difference(numbers1.begin(), numbers1.end(), numbers2.begin(), numbers2.end(), back_inserter(difference));

    cout << "Set Difference: ";
    for (int i : difference) {
        cout << i << ' ';
    }
    return 0;
}