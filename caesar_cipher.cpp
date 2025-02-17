#include <iostream>
#include <string>
using namespace std;
// Write a program that encrypts a sentence using Caesar cipher
int main() {
    string sentenceInput;
    string decryptedInput;
    int shift;

    // Prompt user to enter a sentence to encrypt
    cout << "| Caesar Cipher |";
    cout << "\nEnter Sentence to Encrypt: ";
    getline(cin, sentenceInput);

    // Prompt user to enter # of shift/s
    cout << "\nEnter # of Shift/s: ";
    cin >> shift;

    // Display encrypted sentence
    cout << "\nEncryption Successful!";
    cout << "\nEncrypted Word: ";
    for (int i = 0; i < sentenceInput.length(); i++) {
        decryptedInput = sentenceInput[i] + shift;
            cout << decryptedInput;
    }
    return 0;
}