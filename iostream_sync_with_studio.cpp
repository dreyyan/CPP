#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); // Disable synchronization /w C-style streams like printf scanf

    cout << "Before scanf\n"; // Output via C++ stream
    int x;
    scanf("%d", &x); // Input via C-style stream
    cout << "You entered: " << x << "\n"; // Output via C++ stream
    return 0;
}
