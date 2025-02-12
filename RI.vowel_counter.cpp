#include <iostream>
#include <string>
#include <vector>
using namespace std;

int vowel_counter(const vector<char> vowel_list, string word) {
    size_t counter = 0;
    for (const char& letter : word) {
        for (const char& vowel : vowel_list) {
            if (vowel == letter) {
                ++counter; break;
            }
        }
    }
    return counter;
}

int main() {
    vector<char> vowels = {'a', 'a', 'e', 'i', 'o', 'u'};
    string word;
    int vowel_count;

    // Prompt user to enter a word
    cout << "Enter a word: ";
    getline(cin, word);

    vowel_count = vowel_counter(vowels, word);
    if (vowel_count) {
        cout << "There are " << vowel_count << " vowel/s in the word " << word << ".\n";
    } else cout << "There are no vowels in the word " << word << '\n';
    return 0;
}
