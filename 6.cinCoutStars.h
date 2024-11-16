#include <iostream>
using namespace std;

void cinCoutStars() {
    int num;
    cout << "Enter # of Stars: ";
    cin >> num;

    for (size_t i = 0; i < num; i++) {
        cout << '*';
    }

}