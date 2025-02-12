#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// Write a program that returns the count of a given element in a container
void element_occurence(vector<int>& list, int n) {
    int occurences = count(list.begin(), list.end(), n);
    cout << "There are " << occurences << " #" << n << "s in the container.\n";
}

int main() {
    vector<int> numbers = {1, 2, 3, 1, 2, 1, 1, 4, 5, 4, 7};
    element_occurence(numbers, 1);
    return 0;
}