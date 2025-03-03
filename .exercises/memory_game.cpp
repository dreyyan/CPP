#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <random>
#include <thread>
#include <utility>
#include <vector>
using namespace std;
// CC 203 - Exercise #1 [#5]
// UTILS
void display_format(size_t length) {
    for (size_t i = 0; i < length; ++i) {
        cout << '-';
    }
    cout << '\n';
} void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
} void delay(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

class Memory {
    /* GAME STATISTICS */
    int total_num_of_pairs;
    int player_score = 0, opponent_score = 0;
    pair<int, int> currently_selecting_card = {-1, -1};

    /* RNG */
    random_device rd;
    mt19937 mt;

    /* OTHERS */
    int size = 4;
    vector<vector<bool>> revealed;

public:
    Memory() : mt(rd()) {} // Default Constructor

    /* METHODS */
    void display_table(int **arr) {
        clear_screen();
        cout << "   [ MEMORY GAME ]\n";
        display_format((size * 4) + 6);
        cout << "    Y1   Y2   Y3   Y4\n";
        for (int i = 0; i < size; ++i) {
            cout << "X" << i + 1 << ' ';
            for (int j = 0; j < size; ++j) {
                if (revealed[i][j] || (i == currently_selecting_card.first && j == currently_selecting_card.second)) {
                    if (arr[i][j] > 9) {
                        cout << "[" << setw(2) << arr[i][j] << "] ";
                    } else {
                        cout << "[" << '0' << arr[i][j] << "] ";
                    }
                } else {
                    cout << "[XX] ";
                }
            } cout << '\n';
        }
        display_format((size * 4) + 6);
    }

    void display_scores() {
        cout << "Player: " << player_score << " | Opponent: " << opponent_score << '\n';
        display_format((size * 4) + 6);
    }

    void player_turn(int** arr) {
        pair<int, int> first_card, second_card;
        bool first_card_picked = false;

        for (int i = 0; i < 2; ++i) {
            pair<int, int>& card = (i == 0) ? first_card : second_card;
            while (true) {
                if (!first_card_picked) {
                    cout << "Card #1 [x y]: ";
                } else {
                    cout << "Card #2 [x y]: ";
                }
                cin >> card.first >> card.second;

                // Convert to index value[0-based]
                card.first--;
                card.second--;

                // ERROR: Chosen a revealed card
                if (cin.fail() || card.first < 0 || card.first >= size || card.second < 0 || card.second >= size || revealed[card.first][card.second]) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "[ ERROR ] Invalid or already revealed card. Try again.\n";
                } else if (i == 1 && card == first_card) { // ERROR: Already selected card
                    cout << "[ ERROR ] You already selected this card. Choose a different one.\n";
                } else {
                    first_card_picked = true;
                    break;
                }
            }
            currently_selecting_card = card; // Set to current selecting card
            display_table(arr); // Update table
        }

        first_card_picked = false;
        // Chose matching cards
        if (arr[first_card.first][first_card.second] == arr[second_card.first][second_card.second]) {
            cout << "[/] Match found!\n";
            this_thread::sleep_for(chrono::seconds(1));
            player_score++;
            total_num_of_pairs--;
            revealed[first_card.first][first_card.second] = true;
            revealed[second_card.first][second_card.second] = true;
        } else { // Chose mismatching cards
            cout << "[X] Wrong pair...\n";
            this_thread::sleep_for(chrono::seconds(1));

            // Cover cards again
            currently_selecting_card = {-1, -1};
            display_table(arr);
        } cin.ignore(); // Fix
    }

    void opponent_turn(int** arr) {
        pair<int, int> first, second;
        do {
            first = {rand() % size, rand() % size};
        } while (revealed[first.first][first.second]);

        do {
            second = {rand() % size, rand() % size};
        } while (first == second || revealed[second.first][second.second]);

        // Display opponent's cards
        cout << "Opponent's turn...\n";
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Card #1: " << arr[first.first][first.second] << " (" << first.first + 1 << ", " << first.second + 1 << ")\n";
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Card #2: " << arr[second.first][second.second] << " (" << second.first + 1 << ", " << second.second + 1 << ")\n";
        this_thread::sleep_for(chrono::seconds(1));

        display_format((size * 4) + 6);
        cout << "Press any key to continue...";
        cin.get();

        // If opponent picked matching cards
        if (arr[first.first][first.second] == arr[second.first][second.second]) {
            opponent_score++;
            total_num_of_pairs--;
            revealed[first.first][first.second] = true;
            revealed[second.first][second.second] = true;
        }
    }

    void start_game() {
        total_num_of_pairs = (size * size) / 2;
        revealed.assign(size, vector<bool>(size, false)); // Resize & assign to 'unrevealed' at the start of game
        vector<int> numbers; // Store initial numbers

        // Add initial numbers twice to the list [cards]
        for (int i = 1; i <= total_num_of_pairs; ++i) {
            numbers.push_back(i);
            numbers.push_back(i);
        } shuffle(numbers.begin(), numbers.end(), mt); // Randomoize cards

        int** arr = new int*[size];
        int num = 0;
        for (int i = 0; i < size; ++i) {
            arr[i] = new int[size];
            for (int j = 0; j < size; ++j) {
                arr[i][j] = numbers[num++]; // Set board values using randomized numbers
            }
        }

        // Game continues as long as pairs exist
        while (total_num_of_pairs > 0) {
            display_table(arr);
            display_scores();
            player_turn(arr);
            if (total_num_of_pairs > 0) { // Opponent moves as long as game isn't over
                opponent_turn(arr);
            }
        }

        // Display winner
        clear_screen();
        cout << "Game Over!\n"; delay(2);
        cout << "[ Final Score ]\n"; delay(1);
        cout << "You: " << player_score << '\n'; delay(1);
        cout << "Opponent: " << opponent_score << '\n'; delay(1);
        display_format(11); delay(1);

        if (player_score > opponent_score) { // If greater than opponent's score
            cout << "You win!\n";
        } else if (player_score < opponent_score) { // If lesser than opponent's score
            cout << "Opponent wins, better luck next time...\n";
        } else cout << "It's a tie!\n";
        cout << "Press 'Enter' to continue...";
        cin.get();
    }
};

int main() {
    unique_ptr<Memory> game = make_unique<Memory>();
    game->start_game();
    return 0;
}
