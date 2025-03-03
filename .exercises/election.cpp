#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// CC 203 - Exercise #1 [#4]
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
} void display_format(size_t length) {
    for (size_t i = 0; i < length; ++i) {
        cout << '-';
    } cout << '\n';
}

int main() {
    string candidate_choice;
    bool candidate_exists;
    int num_of_votes, total_votes;

    vector<string> finished_candidates; // Store list of candidates who already have votes
    // Store list of candidates using unordered_map [key-value pairs]
    unordered_map<string, int> candidates = {
        {"Marcos", 0},
        {"Duterte", 0},
        {"Aquino", 0},
        {"Arroyo", 0},
        {"Estrada", 0}
    };

    do { // Prompt user to enter the votes for each candidate until all votes for candidates have been entered
        while (true) {
            candidate_exists = false;
            // Display list of candidates
            cout << "[ -- ELECTION --- SIMULATION -- ]\n";
            display_format(33);
            cout << setw(13) << "CANDIDATE" << setw(8) << "  |  # OF VOTES\n";
            for (const auto &candidate: candidates) {
                cout << "   * " << setw(8) << candidate.first;
                for (const auto& finished_candidate : finished_candidates) {
                    if (candidate.first == finished_candidate) {
                        cout << setw(2) << ' ' << setw(2) << "|  " << candidate.second;
                        break;
                    }
                } cout << '\n';
            } display_format(33);

            // Prompt user to enter candidate of choice
            cout << "Enter Last Name of Candidate: ";
            getline(cin, candidate_choice);

            if (candidate_choice.empty()) { // ERROR: Empty input
                // ERROR: Empty input
                cout << "[ ERROR | Candidate choice must not be empty ]\n";
            }

            // Check if candidate choice exists
            for (const auto &candidate: candidates) {
                if (candidate_choice == candidate.first) {
                    // If candidate choice exists
                    candidate_exists = true;
                    break;
                }
            }

            if (!candidate_exists) { // ERROR: Non-existing candidate
                clear_screen();
                cout << "[ ERROR | Candidate does not exist ]\n";
            } else break;
        }

        // Prompt user to enter # of votes for candidate of choice
        while (true) {
            cout << "Enter # of votes received: ";
            cin >> num_of_votes;

            if (cin.fail()) { // ERROR: Type mismatch
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                clear_screen();
                cout << "[ ERROR | Invalid # of votes ]\n";
            } else if (num_of_votes < 1) { // ERROR: Non-positive votes
                clear_screen();
                cout << "[ ERROR | # of Votes must be greater than 0 ]\n";
            } else break;
        } cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Fix

        // Add candidate votes
        for (auto &candidate: candidates) {
            if (candidate_choice == candidate.first) { // Locate the candidate
                candidate.second += num_of_votes; // Add to # of votes to candidate's current votes
                total_votes += num_of_votes; // Add # of votes to total votes [to calculate vote percentage]
                break;
            }
        }
        finished_candidates.push_back(candidate_choice); // Add finished candidate's name
        clear_screen();
    } while (finished_candidates.size() != candidates.size());

    // Determine the candidate with the highest # of votes
    string candidate_with_highest_votes;
    int highest_votes = 0;
    for (const auto& candidate : candidates) {
        if (candidate.second > highest_votes) {
            candidate_with_highest_votes = candidate.first;
            highest_votes = candidate.second;
        }
    }

    // Display List of candidates, together with respective votes received and % of total votes
    cout <<  setw(10) << "Candidate" << setw(17) << "Votes Received" << setw(20) << "% of Total Votes\n";
    display_format(46);
    for (const auto& candidate : candidates) {
        cout << setw(10) << candidate.first << setw(17) << candidate.second << setw(18) << fixed << setprecision(2) << (static_cast<float>(candidate.second) * 100 / total_votes) << "%\n";
    } display_format(46);

    // Display the winner of the election
    cout << "Winner: " << candidate_with_highest_votes << '\n';
    cout << "Votes: " << highest_votes << '\n';
    cout << "Press 'Enter' to continue...";
    cin.get();
    return 0;
}
