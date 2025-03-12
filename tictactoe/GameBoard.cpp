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

bool GameBoard::checkGameEnd() {
	// Check rows
	for (int i = 0; i < 9; i += 3) {
		if (boardState[i] == boardState[i + 1] && boardState[i] == boardState[i + 2] && boardState[i] != FREE) {
			end = true;
			winner = boardState[i];
			return true;
		}
	}
	// Check columns
	for (int i = 0; i < 3; i++) {
		if (boardState[i] == boardState[i + 3] && boardState[i] == boardState[i + 6] && boardState[i] != FREE) {
			end = true;
			winner = boardState[i];
			return true;
		}
	}
	// Check diagonals
	if (boardState[0] == boardState[4] && boardState[0] == boardState[8] && boardState[0] != FREE) {
		end = true;
		winner = boardState[0];
		return true;
	}
	if (boardState[2] == boardState[4] && boardState[2] == boardState[6] && boardState[2] != FREE) {
		end = true;
		winner = boardState[2];
		return true;
	}
	// Check for a draw
	bool draw = true;
	for (int i = 0; i < 9; i++) {
		if (boardState[i] == FREE) {
			draw = false;
			break;
		}
	}
	if (draw) {
		end = true;
		return true;
	}
	return false;
}


void GameBoard::makeMove(int space, SquareState state) {
    boardState[space] = state;
}

