#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deque<int> dqsum;
    int sum, n1, n2, n3;
    for (size_t i = 0; i < dq.size() - 2; i++) {
        sum = 0;
        n1 = dq[i];
        n2 = dq[i + 1];
        n3 = dq[i + 2];
        sum = sum + n1 + n2 + n3;
        dqsum.push_back(sum);
    }
    
    for (int num : dqsum) {
        cout << num << ' ';
    }
    return 0;
}