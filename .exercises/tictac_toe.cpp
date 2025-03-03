#include <algorithm>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <chrono>
#include <thread>
#include <utility>
#include <vector>
using namespace std;
// CC 203 - Exercise #1 [#6]
class ticTacToe {
    /* GAME STATISTICS */
    int player_score = 0, opponent_score = 0;
    bool winner = false;

    /* BOARD STATISTICS */
    pair<int, int> current_coordinate = make_pair(0, 0); // To store current coordinate
    vector<pair<int, int>> coordinates_list; // To store coordinates with already placed tokens
    char board[3][3]; // To store X & O
    char players_token = 'X', opponents_token = 'O'; // Default tokens
public:
    ticTacToe() { // Default Constructor
        // Board setup
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' '; // Set board values to blank
                coordinates_list.push_back(make_pair(i, j)); // Store coordinates
            }
        }
    }

    // UTILS
    void display_format(size_t length) {
        for (size_t i = 0; i < length; ++i) {
            cout << '-';
        } cout << '\n';
    } void clear_screen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    } void delay(int seconds) {
        this_thread::sleep_for(chrono::seconds(seconds));
    }

    /* METHODS */
    void display_board() {
        cout << "[ TIC-TAC-TOE ]\n";
        display_format(15);
        cout << "  XY 1  2  3\n";
        for (int i = 0; i < 3; ++i) {
            cout << "  " << i + 1 << ' ';
            for (int j = 0; j < 3; ++j) {
                cout << "[" << board[i][j] << "]";
            } cout << '\n';
        } display_format(15);
    }

    bool player_won() {
        for (int i = 0; i < 3; ++i) {
            // Check for linear patterns
            if ((board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X')
                || (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == 'X'))
                return true;
            // Check for diagonal patterns
            if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
                || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
                return true;
        } return false;
    } bool opponent_won() {
        for (int i = 0; i < 3; ++i) {
            // Check for linear patterns
            if ((board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == 'O')
                || (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == 'O'))
                return true;
            // Check for diagonal patterns
            if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
                || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
                return true;
        } return false;
    }

    void player_turn() {
        pair<int, int> coordinates;

        while (true) {
            cout << "Your turn!\n";
            cout << "Enter [x y]: ";
            cin >> coordinates.first >> coordinates.second;

            if (cin.fail()) { // ERROR: Type mismatch
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[ ERROR | Invalid coordinate/s ]\n";
                delay(1); clear_screen(); display_board();
                continue;
            }

            // Convert to index value [0-based]
            coordinates.first--, coordinates.second--;

            // Check if the coordinates are within valid range
            if (coordinates.first < 0 || coordinates.first >= 3 ||
                coordinates.second < 0 || coordinates.second >= 3) {
                cout << "[ ERROR | Out-of-bounds coordinate ]\n";
                delay(1); clear_screen(); display_board();
                continue;
                }

            // Check if the selected position is already occupied
            if (board[coordinates.first][coordinates.second] != ' ') {
                cout << "[ ERROR | Cell already occupied ]\n";
                delay(1); clear_screen(); display_board();
                continue;
            }

            // If valid move, place the token
            board[coordinates.first][coordinates.second] = players_token;

            // Remove the used coordinate from the list
            auto it = find(coordinates_list.begin(), coordinates_list.end(), make_pair(coordinates.first, coordinates.second));
            if (it != coordinates_list.end()) { // If coordinates are found...
                coordinates_list.erase(it); // Erase the coordinates from the list
            }

            clear_screen();
            display_board();
            break;
        }
    }


    void opponent_turn() {
        cout << "Opponents turn...\n";
        delay(1);

        if (coordinates_list.empty()) return; // No valid moves

        // Setup RNG
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<size_t> dist(0, coordinates_list.size() - 1);
        pair<int, int> random_coordinate = coordinates_list[dist(gen)]; // Store random coordinate
        board[random_coordinate.first][random_coordinate.second] = opponents_token; // Display opponent's token

        // Remove opponent's selected coordinate from the list
        auto it = find(coordinates_list.begin(), coordinates_list.end(), random_coordinate);
        if (it != coordinates_list.end()) { // If coordinates are found...
            coordinates_list.erase(it); // Erase the coordinates from the list
        } clear_screen(); display_board(); // Update board
    }

    void start_game() {
        // Decide whether you or opponent goes first
        srand(time(0));
        int num = rand(); // Generate random number
        bool coin = (num % 2 == 0); // Coin flip simulation

        if (coin) { // If won coin flip
            cout << "You won the coinflip!\n";
            delay(1);
            cout << "You get to move first...\n";
            delay(1);
            clear_screen(); display_board();
            while (!winner) { // Continue game until someone scores a point
                player_turn();
                if (player_won()) break;
                opponent_turn();
                if (opponent_won()) break;
            }
        } else { // If lost coin flip
            cout << "Opponent won the coinflip...\n";
            delay(1);
            cout << "opponent moves first...\n";
            delay(1);
            clear_screen(); display_board();
            while (!winner) { // Continue game until someone scores a point
                opponent_turn();
                if (opponent_won()) break;
                player_turn();
                if (player_won()) break;
            }
        }

        cout << "Match made!\n";
        delay(2);

        // Display message
        if (player_won()) {
            cout << "Congratulations, you won!\n";
            delay(3);
            exit(0);
        } else {
            cout << "You lost, better luck next time...\n";
            delay(3);
            exit(0);
        }

        cout << "Press 'Enter' to continue...";
        cin.get();
    }

    void display_menu() {
        int choice;
        while (true) {
            cout << "[ TIC-TAC-TOE ]\n";
            display_format(15);
            cout << "1. Start\n";
            cout << "2. Exit\n";
            display_format(15);

            // Prompt user to enter choice
            cout << ">> ";
            cin >> choice;

            if (cin.fail()) { // ERROR: Type mismatch
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "[ ERROR | Invalid choice ]\n";
            } else if (choice != 1 && choice != 2) { // ERROR: Out-of-range choice
                cout << "[ ERROR | Out-of-range choice ]\n";
            } else break;
        }

        if (choice == 1) { clear_screen(); start_game(); }
        else { cout << "exiting program...\n"; delay(1); exit(0); }
    }
};
int main() {
    ticTacToe start_program;
    start_program.display_menu();
    cin.get();
    return 0;
}
