#include<iostream>
#include "TicTacToe.h"
TicTacToe::TicTacToe() {
    currentPlayer = 1;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = 0; // Empty cells
}
// Play the game
void TicTacToe::playGame() {
    std::cout << "Welcome to Tic-Tac-Toe!\n";
    displayBoard();
    while (true) {
        int row, col;
        std::cout << "Player " << currentPlayer << "'s turn.\n";
        std::cout << "Enter row and column (1-3): ";
        std::cin >> row >> col;

        if (!std::cin) {
            std::cout << "Invalid input! Exiting.\n";
            break;
         }

        // Adjust for 0-based index
        if (makeMove(row - 1, col - 1)) {
            displayBoard();
            if (checkWin()) {
                std::cout << "Player " << currentPlayer << " wins!\n";
                break;
            }
            if (checkDraw()) {
                std::cout << "It's a draw!\n";
                break;
            }

            switchPlayer(); // Next turn
        }
     }
}
// Display the game board
void TicTacToe::displayBoard() const {
    std::cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << " ";
        for (int j = 0; j < 3; ++j) {
            char symbol;
            if (board[i][j] == 0) symbol = ' ';
            else if (board[i][j] == 1) symbol = 'X';
            else symbol = 'O';
            std::cout << symbol;
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "---|---|---\n";
        }
        std::cout <<std::endl;
}

// Switch players
void TicTacToe::switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

// Make a move
bool TicTacToe::makeMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        std::cout << "Invalid position! Please enter values between 1 and 3.\n";
        return false;
    }
    if (board[row][col] != 0) {
        std::cout << "Cell already occupied! Choose another.\n";
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

// Check if current player has won
bool TicTacToe::checkWin() const {
// Check rows
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;

    // Check columns
    for (int j = 0; j < 3; ++j)
        if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer)
            return true;

    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

// Check if the game is a draw
bool TicTacToe::checkDraw() const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == 0)
                return false; // empty spot found
    return true; // board full
}


