#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream fileOpener;
    fileOpener.open("txt_files/test_file.txt", ios::out);

    if (fileOpener.is_open()) {
        fileOpener << "This is a test file.";
        fileOpener.close();

        if (!fileOpener) {
            cerr << "Error opening the file.";
        }
    }

    return 0;
}