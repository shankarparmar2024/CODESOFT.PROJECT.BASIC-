#include <iostream>
using namespace std;

// Function to display board
void displayBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

// Function to check win
bool checkWin(char board[3][3], char player) {

    // Check rows & columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;

    return true;
}

int main() {

    char board[3][3];
    char currentPlayer = 'X';
    int row, col;
    char playAgain;

    do {
        // Initialize board with empty spaces
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';

        currentPlayer = 'X';

        while (true) {

            displayBoard(board);

            // Player input
            cout << "Player " << currentPlayer << ", enter row (0-2) and column (0-2): ";
            cin >> row >> col;

            // Validate move
            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            // Update board
            board[row][col] = currentPlayer;

            // Check win
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "🎉 Player " << currentPlayer << " wins!\n";
                break;
            }

            // Check draw
            if (checkDraw(board)) {
                displayBoard(board);
                cout << "🤝 It's a draw!\n";
                break;
            }

            // Switch player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        // Play again option
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";
    return 0;
}
