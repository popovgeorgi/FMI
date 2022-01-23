#include "generator.h"
#include <cstdlib>
#include <ctime>

const int DEFAULT_NUMBER = 0;
const int BOMB_NUMBER = -1;
const int UNOPENED_FIELD = -2;

vector<vector<int>> generateGameBoard(int size, int bombs) {
    srand(time(NULL));
    vector<vector<int>> board;

    for (int i = 0; i < size; ++i) {
        vector<int> row;

        for (int j = 0; j < size; ++j) {
            row.push_back(DEFAULT_NUMBER);
        }

        board.push_back(row);
    }

    int placedBombs = 0;
    while (placedBombs != bombs) {
        int row = rand() % size;
        int column = rand() % size;

        if (board[row][column] == BOMB_NUMBER) {
            continue;
        }
        else {
            board[row][column] = BOMB_NUMBER;
            placedBombs++;
        }
    }

    // put the appropriate number to their positions
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == BOMB_NUMBER) {
                continue;
            }
            int numberOfBombsSurrounding = 0;

            if (j - 1 >= 0) {
                if (board[i][j-1] == BOMB_NUMBER) {
                    numberOfBombsSurrounding++;
                }
            }
            if (j + 1 < size) {
                if (board[i][j+1] == BOMB_NUMBER) {
                    numberOfBombsSurrounding++;
                }
            }
            if (i - 1 >= 0) {
                if (board[i-1][j] == BOMB_NUMBER) {
                    numberOfBombsSurrounding++;
                }
                if (j - 1 >= 0) {
                    if (board[i-1][j-1] == BOMB_NUMBER) {
                        numberOfBombsSurrounding++;
                    }
                }
                if (j + 1 <= size) {
                    if (board[i-1][j+1] == BOMB_NUMBER) {
                        numberOfBombsSurrounding++;
                    }
                }
            }
            if (i + 1 < size) {
                if (board[i+1][j] == BOMB_NUMBER) {
                    numberOfBombsSurrounding++;
                }
                if (j - 1 >= 0) {
                    if (board[i+1][j-1] == BOMB_NUMBER) {
                        numberOfBombsSurrounding++;
                    }
                }
                if (j + 1 <= size) {
                    if (board[i+1][j+1] == BOMB_NUMBER) {
                        numberOfBombsSurrounding++;
                    }
                }
            }

            board[i][j] = numberOfBombsSurrounding;
        }
    }

    return board;
}

vector<vector<int>> generatePlayerBoard(int size) {
    vector<vector<int>> board;

    for (int i = 0; i < size; ++i) {
        vector<int> row;

        for (int j = 0; j < size; ++j) {
            row.push_back(UNOPENED_FIELD);
        }

        board.push_back(row);
    }

    return board;
}
