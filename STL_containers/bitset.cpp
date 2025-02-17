#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<8> b1("11001100"); // 8-bit representation
    cout << "Bitset: " << b1 << endl; // 11001100
    cout << "Number of 1s: " << b1.count() << endl; // 4
    return 0;
}