#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// CC 202 - Exercise 5
int main() {
    bool enterAgain = false; // Flag Control
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
            int numOfVolunteers, numOfBoxesSold, totalNumOfBoxesSold;
            double costPerBox, profit;

            cout << "--------DETAILS--------" << endl;

            // File Handling: Loop
            while (getline(readFile, line)) {
                costPerBox = stod(line); // Extract Cost Per Box
                cout << "Cost per Box: $" << costPerBox << endl;

                getline(readFile, line); // Extract # of Boxes Sold
                numOfBoxesSold = stoi(line); // Convert to Integer
                cout << "# of Boxes Sold: " << numOfBoxesSold << endl; // Display

                getline(readFile, line); // Extract Total # of Boxes Sold
                totalNumOfBoxesSold = stoi(line); // Convert to Integer
                cout << "Total # of Boxes Sold: " << totalNumOfBoxesSold << endl; // Display

                profit = totalNumOfBoxesSold * costPerBox; // Formula for Profit
                cout << "Profit: $" << profit << endl; // Display

                getline(readFile, line); // Extract Volunteer Name
                volunteer = line;
                cout << "Volunteer: " << volunteer << endl; // Display
            }
            cout << "-----------------------" << endl;
            readFile.close(); // Close File
            // Error Handling: Inaccessible File
        } else {
            cout << "Error Reading File.";
        }
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
        }
    } while (enterAgain);

    return 0;
}