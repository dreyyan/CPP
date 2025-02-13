#include <cstdint>
#include <iostream>
using namespace std;
// RNG - Linear Congruential Genereator[LCG](Fast, lightweight, low memory | short period, predictable)
int main() {
    uint32_t seed = 42; // Initial seed
    uint32_t a = 1664525;
    uint32_t c = 1013904223;
    uint32_t m = 1 << 31; // Modulus (2^31)

    for (int i = 0; i < 10; i++) {
        seed = (a * seed + c) % m; // LCG formula
        cout << seed << endl;
    }
    return 0;
}