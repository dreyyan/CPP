#include <iostream>
#include <vector>
using namespace std;

void arrayDuplicates() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 3, 5};
    vector<int> duplicateElements;
    int arraySize = sizeof(array) / sizeof(array[0]);
    int currentElement = 0;

    for (size_t i = 0; i < arraySize; i++) {
        currentElement = array[i];
        for (size_t j = i + 1; j < arraySize; j++) {
            if (array[j] == currentElement) {
                duplicateElements.push_back(currentElement);
                break;
            }
        }
    }
    cout << "Duplicate Elements:\n";
    for (size_t k = 0; k < duplicateElements.size(); k++) {
        if (k == duplicateElements.size() - 1) {
            cout << duplicateElements[k];
        } else {
            cout << duplicateElements[k] << ", ";
        }
    }
}

int main() {
    arrayDuplicates();
    return 0;
}