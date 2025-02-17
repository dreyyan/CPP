#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char source[] = "Hello";
    char destination[10];  // Must be large enough

    strcpy(destination, source);
    cout << "Copied string: " << destination << endl;

    return 0;
}