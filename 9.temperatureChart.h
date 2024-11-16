#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

void temperatureChart() {
    string fileName, temp;
    int stars, temperature, counter = 1;
    cin >> fileName;
    ifstream readTemperature("files\\" + fileName + ".txt");

    if (readTemperature.is_open()) {
        cout << "| Daily Temperature |" << endl;
        while (getline(readTemperature, temp)) {
            temperature = stoi(temp);
            stars = (temperature + 24) / 3;

            cout << setw(2) << counter++ << ":00 | ";
            for (int i = 0; i < stars; ++i) {
                cout << setw(4) << '*';
            }
            cout << endl;
        }
        cout << "____________________________________________________________________________________________________________" << endl;
        cout << " *C      -20 -17 -14 -11  -8  -6  -3   0   3   6   9  12  15  18  21  24  27  30  33  36  39  42  45  47  50";
    } else {
        cout << "Inacessible file.";
    }
}