#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque<char> dq = {};
    string word = "raceclar";
    bool isPalindrome = true;
    
    for (char c : word) {
        dq.push_front(c);
    }
    
    for (size_t i = 0; i < word.length(); i++) {
        if (dq[i] != word[i]) {
            isPalindrome = false;
            break;
        }
    }
    
    if (isPalindrome) {
        cout << word << " is a palindrome.";
    } else {
        cout << word << " is not a palindrome.";
    }
    return 0;
}