#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream fileOpener;
    fileOpener.open("txt_files/test_file.txt", ios::out);

    if (fileOpener.is_open()) {
        fileOpener << "1st file read.";
        fileOpener.close();

        if (!fileOpener) {
            cerr << "Error opening the file.";
        }
    }

    fileOpener.open("txt_files/test_file.txt", ios::app);

    if (fileOpener.is_open()) {
        fileOpener << "\n2nd file read.";
        fileOpener.close();

        if (!fileOpener) {
            cerr << "Error opening the file.";
        }
    }

    return 0;
}