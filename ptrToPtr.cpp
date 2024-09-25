#include <iostream>
using namespace std;

int main() {
    int num = 5;
    int* ptrNum1 = &num;
    int** ptrNum2 = &ptrNum1;

    cout << "\nVariable: " << num;
    cout << "\nPointer: " << *ptrNum1;
    cout << "\nPointer -> Pointer: " << **ptrNum2;
    return 0;
}