#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char list[5][20];
    strcpy(list[1], "Snow White");

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 20; ++j) {
            cout << list[i][j] << ' ';
        } cout << '\n';
    }

    return 0;
}