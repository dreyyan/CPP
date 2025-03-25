#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

// CC 203 - Exercise #1 [#4]
void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void display_format(size_t length) {
    for (size_t i = 0; i < length; ++i) {
        cout << '-';
    }
    cout << '\n';
}

int main() {
    string candidate_choice;
    bool candidate_exists;
    int num_of_votes, total_votes = 0;

    // To store list of candidates
    const string candidates[] = {"Marcos", "Duterte", "Aquino", "Arroyo", "Estrada"};
    int votes[5] = {0}; // To store votes for each candidate

    vector<string> finished_candidates; // To store list of candidates with votes

    do { // Prompt user to enter the votes for each candidate until all votes for candidates have been entered
        while (true) {
            candidate_exists = false;
            // Display list of candidates
            cout << "[ -- ELECTION --- SIMULATION -- ]\n";
            display_format(33);
            cout << setw(13) << "CANDIDATE" << setw(8) << "  |  # OF VOTES\n";
            for (size_t i = 0; i < 5; ++i) {
                cout << "   * " << setw(8) << candidates[i];
                // Check if the candidate has already been voted for
                for (const auto& finished_candidate : finished_candidates) {
                    if (candidates[i] == finished_candidate) {
                        cout << setw(2) << ' ' << setw(2) << "|  " << votes[i];
                        break;
                    }
                }
                cout << '\n';
            }
            display_format(33);

            // Prompt user to enter candidate of choice
            cout << "Enter Last Name of Candidate: ";
            getline(cin, candidate_choice);

            if (candidate_choice.empty()) { // ERROR: Empty input
                cout << "[ ERROR | Candidate choice must not be empty ]\n";
            }

            // Check if candidate choice exists
            for (size_t i = 0; i < 5; ++i) {
                if (candidate_choice == candidates[i]) {
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
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Fix

        // Add candidate votes
        for (size_t i = 0; i < 5; ++i) {
            if (candidate_choice == candidates[i]) {
                votes[i] += num_of_votes; // Add to # of votes to candidate's current votes
                total_votes += num_of_votes; // Add # of votes to total votes [to calculate vote percentage]
                break;
            }
        }
        finished_candidates.push_back(candidate_choice); // Add finished candidate's name
        clear_screen();
    } while (finished_candidates.size() != 5);

    // Determine the candidate with the highest # of votes
    string candidate_with_highest_votes;
    int highest_votes = 0;
    for (size_t i = 0; i < 5; ++i) {
        if (votes[i] > highest_votes) {
            candidate_with_highest_votes = candidates[i];
            highest_votes = votes[i];
        }
    }

    // Display List of candidates, together with respective votes received and % of total votes
    cout << setw(10) << "Candidate" << setw(17) << "Votes Received" << setw(20) << "% of Total Votes\n";
    display_format(46);
    for (size_t i = 0; i < 5; ++i) {
        cout << setw(10) << candidates[i] << setw(17) << votes[i] << setw(18) << fixed << setprecision(2) << (static_cast<float>(votes[i]) * 100 / total_votes) << "%\n";
    }
    display_format(46);

    // Display the winner of the election
    cout << "Winner: " << candidate_with_highest_votes << '\n';
    cout << "Votes: " << highest_votes << '\n';
    cout << "Press 'Enter' to continue...";
    cin.get();
    return 0;
}
