#include <iostream>
#include <vector>
#include "validation.h"
#include "generator.h"
#include "game.h"

using namespace std;

const char MARK_BOMB = 'b';
const char REVEAL_FIELD = 'r';
const int UNOPENED_FIELD = -2;

int main() {
    int size, bombs;

    cout << "Size of the board:";
    cin >> size;
    cout << "Number of bombs:";
    cin >> bombs;

    if (validateInput(size, bombs) == 0) {
        cout << "Wrong input!";
        return -1;
    }

    vector<vector<int>> gameBoard = generateGameBoard(size, bombs);
    vector<vector<int>> playerBoard = generatePlayerBoard(size);
    cout << "Good Luck!" << endl;
    printBoard(playerBoard);

    int correctlyPlacedBombs = 0;

    while (true) {
        cin.clear();
        cin.sync();
        string input;
        getline(cin, input);

        int row = input[0] - '0';
        int col = input[2] - '0';
        char action = input[4];
        if (validateMove(row, col, action, size) == false) {
            cout << "Your move is incorrect. Please enter valid data." << endl;
            continue;
        }

        if (playerBoard[row][col] != UNOPENED_FIELD) {
            cout << "You've already played it. Select another one." << endl;
            continue;
        }

        if (action == REVEAL_FIELD) {
            if (gameBoard[row][col] == -1) {
                cout << "Game over, you've hit a bomb!" << endl;
                printBoard(gameBoard);
                break;
            }
            else {
                if (gameBoard[row][col] == 0) {
                    revealSurroundings(row, col, playerBoard, gameBoard);
                }

                playerBoard[row][col] = gameBoard[row][col];
            }
        }
        else if (action == MARK_BOMB) {
            if (gameBoard[row][col] == -1) {
                correctlyPlacedBombs++;
            }
            playerBoard[row][col] = -1;
            if (correctlyPlacedBombs == bombs) {
                cout << "You won!" << endl;
                break;
            }
        }

        printBoard(playerBoard);
    }

    return 0;
}








