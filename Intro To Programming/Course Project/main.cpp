#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

bool validateInput(int size, int bombs);
bool validateMove(int row, int col, char action, int size);
vector<vector<int>> generateGameBoard(int size, int bombs);
vector<vector<int>> generatePlayerBoard(int size);
void printBoard(vector<vector<int>> board);
void revealSurroundings(int row, int col, vector<vector<int>> &playerBoard, vector<vector<int>> &gameBoard);

int main() {
    srand(time(NULL));
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
        char col = input[2] - '0';
        char action = input[4];
        if (validateMove(row, col, action, size) == false) {
            cout << "Your move is incorrect. Please enter valid data." << endl;
            continue;
        }

        if (playerBoard[row][col] != -2) {
            cout << "You've already played it. Select another one." << endl;
            continue;
        }

        if (action == 'r') {
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
        else if (action == 'b') {
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
        // can go to the upper row
        // can it go to the upper-left,right?
        //up
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
            //yes upper-left
        }
        if (col + 1 < size) {
            if (gameBoard[row - 1][col + 1] == 0) {
                revealSurroundings(row - 1, col + 1, playerBoard, gameBoard);
            }
            else {
                if (gameBoard[row - 1][col + 1] != -5)
                playerBoard[row - 1][col + 1] = gameBoard[row - 1][col + 1];
            }
            // yes upper-right
        }
    }
    if (row + 1 < size) {
        // can go to the lower row
        // can it go to the lower-left,right?
        //down
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
            //yes lower-left
        }
        if (col + 1 < size) {
            if (gameBoard[row + 1][col + 1] == -1) {
                revealSurroundings(row + 1, col + 1, playerBoard, gameBoard);
            }
            else {
                if (gameBoard[row + 1][col + 1] != -5)
                playerBoard[row + 1][col + 1] = gameBoard[row + 1][col + 1];
            }
            //yes lower-right
        }
    }
}

vector<vector<int>> generatePlayerBoard(int size) {
    vector<vector<int>> board;

    for (int i = 0; i < size; ++i) {
        vector<int> row;

        for (int j = 0; j < size; ++j) {
            row.push_back(-2);
        }

        board.push_back(row);
    }

    return board;
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

bool validateMove(int row, int col, char action, int size) {
    if (row < 0 || row >= size) {
        return false;
    }
    if (col < 0 || col >= size) {
        return false;
    }
    if (action != 'b' && action != 'r') {
        return false;
    }

    return true;
}

vector<vector<int>> generateGameBoard(int size, int bombs) {
    vector<vector<int>> board;

    for (int i = 0; i < size; ++i) {
        vector<int> row;

        for (int j = 0; j < size; ++j) {
            row.push_back(0);
        }

        board.push_back(row);
    }

    int placedBombs = 0;
    while (placedBombs != bombs) {
        int row = rand() % size;
        int column = rand() % size;

        if (board[row][column] == -1) {
            continue;
        }
        else {
            board[row][column] = -1;
            placedBombs++;
        }
    }

    // put the appropriate number in their positions
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == -1) {
                continue;
            }
            int numberOfBombsSurrounding = 0;

            if (j - 1 >= 0) {
                if (board[i][j-1] == -1) {
                    numberOfBombsSurrounding++;
                }
            }
            if (j + 1 < size) {
                if (board[i][j+1] == -1) {
                    numberOfBombsSurrounding++;
                }
            }
            if (i - 1 >= 0) {
                // can go to the upper row
                // can it go to the upper-left,right?
                //up
                if (board[i-1][j] == -1) {
                    numberOfBombsSurrounding++;
                }
                if (j - 1 >= 0) {
                    if (board[i-1][j-1] == -1) {
                        numberOfBombsSurrounding++;
                    }
                    //yes upper-left
                }
                if (j + 1 <= size) {
                    if (board[i-1][j+1] == -1) {
                        numberOfBombsSurrounding++;
                    }
                    // yes upper-right
                }
            }
            if (i + 1 < size) {
                // can go to the lower row
                // can it go to the lower-left,right?
                //down
                if (board[i+1][j] == -1) {
                    numberOfBombsSurrounding++;
                }
                if (j - 1 >= 0) {
                    if (board[i+1][j-1] == -1) {
                        numberOfBombsSurrounding++;
                    }
                    //yes lower-left
                }
                if (j + 1 <= size) {
                    if (board[i+1][j+1] == -1) {
                        numberOfBombsSurrounding++;
                    }
                    //yes lower-right
                }
            }

            board[i][j] = numberOfBombsSurrounding;
        }
    }

    return board;
}

bool validateInput(int size, int bombs) {
    if (bombs > size * size) {
        return 0;
    }

    return 1;
}
