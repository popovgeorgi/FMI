#ifndef COURSE_PROJECT_GAME_H
#define COURSE_PROJECT_GAME_H

#include <vector>

using namespace std;

void printBoard(vector<vector<int>> board);
void revealSurroundings(int row, int col, vector<vector<int>> &playerBoard, vector<vector<int>> &gameBoard);

#endif //COURSE_PROJECT_GAME_H
