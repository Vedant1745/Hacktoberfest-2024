#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 9;

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < SIZE; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "---------------------\n"; // Print grid lines
        }
        for (int j = 0; j < SIZE; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "| "; // Print vertical grid lines
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if placing num at (row, col) is valid
bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    // Check the row and column
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num || board[x][col] == num) {
            return false;
        }
    }

    // Check the 3x3 box
    int boxRowStart = row - row % 3;
    int boxColStart = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + boxRowStart][j + boxColStart] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if the Sudoku board is complete
bool isComplete(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            if (num == 0) {
                return false; // Found an empty space
            }
        }
    }
    return true;
}

int main() {
    // Sample Sudoku puzzle (0s are placeholders for empty cells)
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    while (true) {
        printBoard(board);
        int row, col, num;
        cout << "Enter row (0-8), column (0-8), and number (1-9) to place (or -1 to quit): ";
        cin >> row;

        if (row == -1) {
            cout << "Exiting game." << endl;
            break;
        }

        cin >> col >> num;

        // Check for validity
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || num < 1 || num > 9) {
            cout << "Invalid input. Please try again." << endl;
            continue;
        }

        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (isComplete(board)) {
                printBoard(board);
                cout << "Congratulations! You've completed the Sudoku!" << endl;
                break;
            }
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    return 0;
}
