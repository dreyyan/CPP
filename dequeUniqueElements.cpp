#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque<char> dq = {};
    string word = "antenna";
    bool invalid;
    
    for (size_t i = 0; i < word.length(); i++) {
        invalid = false;
        for (size_t k = 0; k < word.length(); k++) {
            if (i != k && word[i] == word[k]) {
                invalid = true;
                break;
            }
        }
        if (!invalid) {
            dq.push_front(word[i]);
        }
    }
    
    for (char letter : dq) {
        cout << letter << ' ';
    }
    return 0;
}