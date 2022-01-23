#include "game.h"
#include <iostream>

void revealSurroundings(int row, int col, vector<vector<int>> &playerBoard, vector<vector<int>> &gameBoard) {
    int size = playerBoard.size();
    playerBoard[row][col] = 0;
    gameBoard[row][col] = -5;

    if (col - 1 >= 0) {
        if (gameBoard[row][col - 1] == 0) {
            revealSurroundings(row, col - 1, playerBoard, gameBoard);
        }
        else {
            if (gameBoard[row][col - 1] != -5) {
                playerBoard[row][col - 1] = gameBoard[row][col - 1];
            }
        }
    }
    if (col + 1 < size) {
        if (gameBoard[row][col + 1] == 0) {
            revealSurroundings(row, col + 1,playerBoard, gameBoard);
        }
        else {
            if (gameBoard[row][col + 1] != -5)
                playerBoard[row][col + 1] = gameBoard[row][col + 1];
        }
    }
    if (row - 1 >= 0) {
        if (gameBoard[row - 1][col] == 0) {
            revealSurroundings(row - 1, col, playerBoard, gameBoard);
        }
        else {
            if (gameBoard[row - 1][col] != -5)
                playerBoard[row - 1][col] = gameBoard[row - 1][col];
        }

        if (col - 1 >= 0) {
            if (gameBoard[row - 1][col - 1] == 0) {
                revealSurroundings(row - 1, col - 1, playerBoard, gameBoard);
            }
            else {
                if (gameBoard[row - 1][col - 1] != -5)
                    playerBoard[row - 1][col - 1] = gameBoard[row - 1][col - 1];
            }
        }
        if (col + 1 < size) {
            if (gameBoard[row - 1][col + 1] == 0) {
                revealSurroundings(row - 1, col + 1, playerBoard, gameBoard);
            }
            else {
                if (gameBoard[row - 1][col + 1] != -5)
                    playerBoard[row - 1][col + 1] = gameBoard[row - 1][col + 1];
            }
        }
    }
    if (row + 1 < size) {
        if (gameBoard[row + 1][col] == 0) {
            revealSurroundings(row + 1, col, playerBoard, gameBoard);
        }
        else {
            if (gameBoard[row + 1][col] != -5)
                playerBoard[row + 1][col] = gameBoard[row + 1][col];
        }

        if (col - 1 >= 0) {
            if (gameBoard[row + 1][col - 1] == 0) {
                revealSurroundings(row + 1, col - 1, playerBoard, gameBoard);
            }
            else {
                if (gameBoard[row + 1][col - 1] != -5)
                    playerBoard[row + 1][col - 1] = gameBoard[row + 1][col - 1];
            }
        }
        if (col + 1 < size) {
            if (gameBoard[row + 1][col + 1] == -1) {
                revealSurroundings(row + 1, col + 1, playerBoard, gameBoard);
            }
            else {
                if (gameBoard[row + 1][col + 1] != -5)
                    playerBoard[row + 1][col + 1] = gameBoard[row + 1][col + 1];
            }
        }
    }
}



void printBoard(vector<vector<int>> board) {
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (board[i][j] == -2) {
                cout << '_';
            }
            else if (board[i][j] == -1) {
                cout << 'B';
            }
            else if (board[i][j] == 0 || board[i][j] == -5) {
                cout << '0';
            }
            else {
                cout << board[i][j];
            }

            if (j + 1 < board.size()) {
                cout << " ";
            }
            else {
                cout << '\n';
            }
        }
    }
}
