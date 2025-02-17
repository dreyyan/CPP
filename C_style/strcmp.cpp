#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[] = "apple";
    char str2[] = "banana";

    int result = strcmp(str1, str2);
    if (result == 0)
        cout << "Strings are equal\n";
    else if (result < 0)
        cout << str1 << " < " << str2 << '\n';
    else
        cout << str1 << " > " << str2 << '\n';

    return 0;
}