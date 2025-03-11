#include "GameBoard.h"

std::string GameBoard::toString() {
    // std::string board = " 0 | 1 | 2 \n-----------\n 3 | 4 | 5 \n-----------\n 6 | 7 | 8 ";
    std::stringstream board;
    for (int i = 0; i < 9; i++) {
        board << " ";
        switch (boardState[i]) {
            case FREE:
                board << std::to_string(i);
                break;
            case X:
                board << "X";
                break;
            case O:
                board << "O";
                break;
        }
        if (i == 2 || i == 5) {
            board << " \n-----------\n";
        } else if (i != 8) {
            board << " |";
        }
    }
    return board.str();
}

bool GameBoard::isSpaceFree(int space) {
    if (space >= 0 && space < 9) {
        return boardState[space] == FREE;
    }
    return false;
}

void GameBoard::makeMove(int space, SquareState state) {
    boardState[space] = state;
}

