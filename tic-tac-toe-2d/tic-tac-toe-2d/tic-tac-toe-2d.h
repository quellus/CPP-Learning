// tic-tac-toe-2d.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <vector>

enum State {
	EMPTY,
	X,
	O
};

enum GameState {
	ONGOING,
	X_WON,
	O_WON,
	DRAW,
	INVALID_MOVE
};

class TicTacToe2D {
public:
	TicTacToe2D(int newSideLen) {
		sideLen = newSideLen;
		board.resize(sideLen, std::vector<State>(sideLen, EMPTY));
	}

	GameState makeMove(int x, int y, bool xTurn);

private:
	std::vector<std::vector<State>> board;
	int sideLen;
	bool isXTurn = true;

	GameState checkGameState(int x, int y, bool xTurn);

};