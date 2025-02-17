#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// fstream - in
int main() {
    fstream fileOpener;
    fileOpener.open("txt_files/test_file.txt", ios::in);
    if (fileOpener.is_open()) { // If file can be opened
        cout << "📂 File Content:\n";
        string line;
        while (getline(fileOpener, line)) { // Read line by line
            cout << line << endl;
        }
        fileOpener.close(); // Close file
    } else { cerr << "Error opening the file."; }
    return 0;
}