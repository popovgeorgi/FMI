#include "validation.h"

const char MARK_BOMB = 'b';
const char REVEAL_FIELD = 'r';

bool validateInput(int size, int bombs) {
    if (bombs > size * size) {
        return 0;
    }

    return 1;
}

bool validateMove(int row, int col, char action, int size) {
    if (row < 0 || row >= size) {
        return false;
    }
    if (col < 0 || col >= size) {
        return false;
    }
    if (action != MARK_BOMB && action != REVEAL_FIELD) {
        return false;
    }

    return true;
}
