#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// fstream - out
int main() {
    fstream fileOpener;
    fileOpener.open("txt_files/test_file.txt", ios::out);
    if (fileOpener.is_open()) { // If file can be opened
        fileOpener << "This is a test file."; // Write text to file
        fileOpener.close(); // Close file
    } else { cerr << "Error opening the file."; }

    return 0;
}
