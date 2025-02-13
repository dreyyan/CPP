#include <iostream>
using namespace std;

int main() {
    int size;
        
    cout << "Enter Size: ";
    cin >> size;
        
    int* ptrArr = new int[size];
        
    for (int i = 0; i < size; i++) {
        cout << "\nEnter Grade #" << i + 1 << ": ";
        cin >> ptrArr[i];
    }
        
    for (int j = 0; j < size; j++) {
        cout << "\nGrade " << j + 1 << " = " << ptrArr[j];
    }
        
    delete[] ptrArr;
    return 0;
}