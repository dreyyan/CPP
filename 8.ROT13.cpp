#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

void ROT13() {
    string fileName, line, code;
    cin >> fileName;

    ifstream readFile(fileName + ".rot13");
    if (readFile.is_open()) {
        while (getline(readFile, line)) {
            code += line;
        }
        readFile.close();

        for (char character : code) {
            if (isalpha(character)) {
                    char offset = isupper(character) ? 'A' : 'a';
                    character = (character - offset + 13) % 26 + offset;
                    cout << character;
            }
        }
    } else {
        cout << "Inaccessible file.";
    }
}

int main() {
    ROT13();
    return 0;
}