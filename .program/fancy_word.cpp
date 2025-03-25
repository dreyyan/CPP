#include <chrono>
#include <iostream>
#include <string>
#include <thread>
using namespace std;

void FancyWord(string word) {
    string current_word = "";
    for (int i = 0; i < word.length(); i++) {
        int A = 65;
        while (A <= 90) { // While Iterated Letter is Unequal to Word's Letter
            if (word[i] == static_cast<char>(A)) { // If Iterated Letter is Same as Word's Letter
                current_word += static_cast<char>(A); // Add Current Letter to Word
                cout << current_word << '\n';
                break;
            }
            cout << current_word << static_cast<char>(A++); // Print Letter
            this_thread::sleep_for(chrono::milliseconds(50));
            cout << '\n';
        }
    }
    cin.get();
}

int main() {
    FancyWord("HELLO WORLD");
    return 0;
}