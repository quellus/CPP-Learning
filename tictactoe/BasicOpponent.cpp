#include "BasicOpponent.h"

int BasicOpponent::move(GameBoard gameBoard) {
    SquareState* boardState = gameBoard.getBoardState();
	std::vector<int> freeSpaces;
    for (int i = 0; i < 9; i++) {
		if (boardState[i] == FREE) {
			freeSpaces.push_back(i);
		}
    }

    return freeSpaces[rand() % freeSpaces.size()];
}
