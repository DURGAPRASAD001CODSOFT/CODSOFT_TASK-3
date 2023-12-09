#include <iostream>
#include <vector>
using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl << "---------" << endl;
    }
}

// Function to check if the current player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

// Function to play the Tic-Tac-Toe game
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char players[] = {'X', 'O'};
    int currentPlayer = 0;

    while (true) {
        // Display the current state of the board
        printBoard(board);

        // Get player input
        int row, col;
        cout << "Player " << players[currentPlayer] << ", enter your move (row and column, e.g., 1 2): ";
        cin >> row >> col;

        // Update the board with the player's move
        if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = players[currentPlayer];

            // Check for a win
            if (checkWin(board, players[currentPlayer])) {
                printBoard(board);
                cout << "Player " << players[currentPlayer] << " wins!" << endl;
                break;
            }

            // Check for a draw
            if (checkDraw(board)) {
                printBoard(board);
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch players
            currentPlayer = 1 - currentPlayer;
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

int main() {
    while (true) {
        // Play the game
        playGame();

        // Ask if the players want to play again
        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }

    return 0;
}
