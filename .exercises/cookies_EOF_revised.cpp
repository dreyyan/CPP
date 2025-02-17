#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
// CC 202 - Exercise 6
int main() {
    bool enterAgain = false, validFileName = false; // Flag Control
    map<string, double> maxBoxesSoldStudents; // Contains Student /w Max Boxes Sold
    int maxBoxesSold = 0, averageBoxesSold, totalNumOfBoxesSold = 0, numOfVolunteers = 0;
    double totalProfit = 0;

    do {
        // Declare Variables
        string name, path = "";

        // Prompt User to Enter File
            cout << "Enter File Name: "; // Enter file name without extension '.txt'
            getline(cin, path);
            path += ".txt"; // Add '.txt' Extension

        fstream readFile(path); // Read File

        // File Handling: is_open
        if (readFile.is_open()) {
            string line, volunteer;
            int numOfBoxesSold = 0;
            double costPerBox = 0, profit = 0;

            cout << "--------DETAILS--------" << endl;

            // File Handling: Loop
            while (getline(readFile, line)) {
                costPerBox = stod(line); // Extract Cost Per Box
                cout << "Cost per Box: $" << costPerBox << endl;

                getline(readFile, line); // Extract # of Boxes Sold
                numOfBoxesSold = stoi(line); // Convert to Integer
                cout << "# of Boxes Sold: " << numOfBoxesSold << endl; // Display

                totalNumOfBoxesSold += numOfBoxesSold; // Add to Total

                getline(readFile, line); // Extract Volunteer Name
                volunteer = line;
                cout << "Volunteer: " << volunteer << endl; // Display
                numOfVolunteers++;

                profit = numOfBoxesSold * costPerBox; // Formula for Profit
                totalProfit += profit; // Add to Total Profit
                cout << "Profit: $" << profit << endl; // Display

                // Input Handling: Max Boxes
                if (numOfBoxesSold == maxBoxesSold) {
                    maxBoxesSoldStudents[volunteer] = profit;
                } else if (numOfBoxesSold > maxBoxesSold) {
                    maxBoxesSold = numOfBoxesSold;
                    maxBoxesSoldStudents.clear();
                    maxBoxesSoldStudents[volunteer] = profit;
                    }
                }

            cout << "-----------------------" << endl;
            // Input or Display Stats
            char choice;
            // Prompt User to Enter File Name Again
            cout << "Enter File Name Again?[y/n]: ";
            cin >> choice;
            cin.ignore();

            // Input Handling: Choice
            if (choice == 'y') {
                enterAgain = true;
            } else {
                enterAgain = false;
                averageBoxesSold = totalNumOfBoxesSold / numOfVolunteers;
                // Display
                cout << "--------RESULTS--------" << endl;
                cout << "Total # of Boxes Sold: " << totalNumOfBoxesSold << endl;
                cout << "Total Profit: $" << totalProfit << endl;
                cout << "Average Boxes Sold by Volunteers: " << averageBoxesSold << endl;
                cout << "Students that Sold the Maximum Boxes:\n";
                for (const auto& student : maxBoxesSoldStudents) {
                    cout << "* " << student.first << endl;
                    cout << "\tProfit: $" << student.second << " | Donate: $" << student.second * 0.10 << endl;
                }
            }
            // Error Handling: Inaccessible File
        } else {
            cout << "Error Reading File." << endl;
        }
    } while (enterAgain);

    return 0;
}