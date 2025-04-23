// tic-tac-toe-2d.cpp : Defines the entry point for the application.
//

#include "tic-tac-toe-2d.h"

GameState TicTacToe2D::makeMove(int x, int y, bool xTurn) {
	// Check if the move is valid
	if (xTurn != isXTurn || x >= sideLen || y >= sideLen || board[x][y] != EMPTY) {
		return INVALID_MOVE;
	}

	isXTurn = !isXTurn;

	// Make move
	board[x][y] = xTurn ? X : O;

	// Check board state
	GameState state = checkGameState(x, y, xTurn);
	if (state == ONGOING) {
		for (int tempX = 0; tempX < sideLen; tempX++) {
			for (int tempY = 0; tempY < sideLen; tempY++) {
				if (board[tempX][tempY] == EMPTY) {
					return state;
				}
			}
		}
		return DRAW;
	}
	return state;
}


GameState TicTacToe2D::checkGameState(int x, int y, bool xTurn) {
	State moveState = X;
	if (!xTurn) {
		moveState = O;
	}
	// Check rows
	bool win = true;
	for (int tempX = 0; tempX < sideLen; tempX++) {
		if (board[tempX][y] == EMPTY) {
			break;
		}
		else if (board[tempX][y] != moveState) {
			win = false;
		}
	}

	if (win) {
		if (xTurn) {
			return X_WON;
		} else {
			return O_WON;
		}
	}

	// Check columns
	for (int tempY = 0; tempY < sideLen; tempY++) {
		if (board[x][tempY] == EMPTY) {
			break;
		}
		else if (board[x][tempY] != moveState) {
			win = false;
		}
	}

	if (win) {
		if (xTurn) {
			return X_WON;
		}
		else {
			return O_WON;
		}
	}

	// Check diagnols top left
	if (x == y) {
		for (int xy = 0; xy < sideLen; xy++) {
			if (board[xy][xy] == EMPTY) {
				break;
			}
			else if (board[xy][xy] != moveState) {
				win = false;
			}
		}
	}

	// Check diagnols top right
	if (y == sideLen - 1 - x) {
		int tempY = sideLen - 1;
		for (int tempX = 0; tempX < sideLen; tempX++) {
			if (board[tempX][tempY] == EMPTY) {
				break;
			}
			else if (board[tempX][tempY] != moveState) {
				win = false;
			}
			tempY--;
		}
	}

	if (win) {
		if (xTurn) {
			return X_WON;
		}
		else {
			return O_WON;
		}
	}

	return ONGOING;
}