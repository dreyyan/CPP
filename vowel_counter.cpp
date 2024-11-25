#include <iostream>
#include <string>
using namespace std;

int main() {
    string stringInput;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int sizeVowels = sizeof(vowels) / sizeof(vowels[0]);
    int vowelCounter = 0;

    cout << "Enter Series of Letters: ";
    cin >> stringInput;

    for (int i = 0; i < stringInput.length(); i++) {
        for (int j = 0; j < sizeVowels; j++) {
            if (stringInput[i] == vowels[j]) {
                vowelCounter += 1;
            }
        }
    }

    cout << "\nNumber of Vowels: " << vowelCounter;
    return 0;
}
