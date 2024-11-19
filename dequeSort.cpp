#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque<int> dq = {2, 6, 1, 10, 9, 7, 4, 5, 3, 8};
    int minIndex, temp;
    
    for (size_t i = 0; i < dq.size(); i++) {
        minIndex = i;
        for (size_t j = i + 1; j < dq.size(); j++) {
            if (dq[j] < dq[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = dq[minIndex];
            dq[minIndex] = dq[i];
            dq[i] = temp;
        }
    }
    
    for (int num : dq) {
        cout << num << ' ';
    }
    return 0;
}