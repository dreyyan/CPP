#include <iostream>
#include <string>
using namespace std;
// CC 202: Lab Exercise 1
// [#1] Write a program that outputs your basic information
int main() {
    string name = "Adrian Dominic Tan";
    string programYearSection = "BSCS 1-A";
    string favoriteSongAndArtist = "Closer - The Chainsmokers";
    string favoriteTvSeries = "Young Sheldon";
    string inspiration = "My inspiration for this class is to learn new things and have fun!";

    // Display formatted information
    cout << name << '\n';
    cout << programYearSection << '\n';
    cout << favoriteSongAndArtist << '\n';
    cout << favoriteTvSeries << '\n';
    cout << inspiration;
    return 0;
}
