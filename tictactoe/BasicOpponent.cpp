
#include "BasicOpponent.h"

int BasicOpponent::move(GameBoard gameBoard) {
    SquareState* boardState = gameBoard.getBoardState();
    int numFreeSpaces = 0;
    for (int i = 0; i < 9; i++) {
        if (boardState[i] == FREE) {
            numFreeSpaces++;
        }
    }
    int freeSpaces[numFreeSpaces];
    int currFreeSpacesIndex = 0;
    for (int i = 0; i < 9; i++) {
        if (boardState[i] == FREE) {
            freeSpaces[currFreeSpacesIndex] = i;
            currFreeSpacesIndex++;
        }
    }
    return freeSpaces[rand() % numFreeSpaces];
}
