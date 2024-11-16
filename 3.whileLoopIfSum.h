// 4. Prints Sum if Greater than 10, 000
#include <iostream>
using namespace std;

void whileLoopIfSum() {
    int sum = 0, num = 1;
    while (sum < 10000) {
        sum += num;
        num++;
    }
    cout << "Recent Number: " << num;
}