#include <iostream>
using namespace std;
// CC 202: Lab Exercise 1
// [#4] Write a revised 'softdrink.cpp' program that calculates the following:
// * # of bottles sold
// * daily profit
// * annual profit
// * profit in a decade
int main() {
    // Declaration & Initialization of Variables
    double cases_per_day, bottles_per_day;
    int bottles_per_case = 12;
    int bottles_sold;
    double profit_per_bottle = 0.3; // 30 cents per bottle
    double profit_per_day, profit_per_year, profit_per_decade;

    // Input # of Cases
    cout << "Enter # of Cases: \n";
    cin >> cases_per_day;

    // Algorithm for # of Bottles Sold Per Day
    bottles_sold = cases_per_day * 12;

    // Algorithm for Daily Profit
    profit_per_day = cases_per_day * bottles_per_case * profit_per_bottle;

    // Algorithm for Annual Profit
    profit_per_year = profit_per_day * 365;

    // Algorithm for Profit in a Decade
    profit_per_decade = profit_per_year * 10;

    // Display # of Bottles Sold, Daily Profit, Annual Profit, and Profit in a Decade
    cout << "# of Bottles Sold/day: " << bottles_sold << " bottles";
    cout << "\nDaily Profit: $" << profit_per_day;
    cout << "\nAnnual Profit: $" << profit_per_year;
    cout << "\nProfit in a Decade: $" << profit_per_decade;

    return 0;
}
