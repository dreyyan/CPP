#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// fstream - append
int main() {
    fstream fileOpener;
    fileOpener.open("txt_files/test_file.txt", ios::app);
    if (fileOpener.is_open()) { // If file can be opened
        fileOpener << "this text has been appended.\n"; // Append text to file
        fileOpener.close(); // Close file
    } else { cerr << "Error opening the file."; }
    return 0;
}