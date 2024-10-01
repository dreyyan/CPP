#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentenceInput;
    string decryptedInput;
    int shift;

    cout << "| Caesar Cipher |";
    cout << "\nEnter Sentence to Encrypt: ";
    getline(cin, sentenceInput);

    cout << "\nEnter # of Shift/s: ";
    cin >> shift;

    cout << "\nEncryption Successful!";
    cout << "\nEncrypted Word: ";
    for (int i = 0; i < sentenceInput.length(); i++) {
        decryptedInput = sentenceInput[i] + shift;
            cout << decryptedInput;
    }



    return 0;
}