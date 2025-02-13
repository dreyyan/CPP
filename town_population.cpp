#include <iostream>
using namespace std;
// CC 202 - Exercise 7
int main() {
    int townAPopulation, townBPopulation, years = 0;
    double townAGrowthRate, townBGrowthRate;

    // Population of Town A
    cout << "Population of Town A: ";
    cin >> townAPopulation;

    // Growth Rate of Town A
    cout << "Growth Rate of Town A: ";
    cin >> townAGrowthRate;

    // Population of Town B
    cout << "Population of Town B: ";
    cin >> townBPopulation;

    // Growth Rate of Town B
    cout << "Growth Rate of Town B: ";
    cin >> townBGrowthRate;

    // Calculate population over time
    while (true) {
        townAPopulation += (townAPopulation * townAGrowthRate);
        townBPopulation += (townBPopulation * townBGrowthRate);
        years++;
        if (townAPopulation >= townBPopulation) {
            break;
        }
    }

    // Display results
    cout << "Population of Town A will be greater than or equal to Town B in " <<  years << " year/s." << endl;
    cout << "\nTown Populations in " << years << " year/s:" << endl;
    cout << "Town A Population: " << townAPopulation << endl;
    cout << "Town B Population: " << townBPopulation << endl;
    return 0;
}