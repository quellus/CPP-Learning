#include "tic-tac-toe-2d.h"
#include <iostream>

void printGameState(GameState gs) {
	switch (gs) {
		case ONGOING:
			std::cout << "Game is ongoing" << std::endl;
			break;
		case X_WON:
			std::cout << "X won!" << std::endl;
			break;
		case O_WON:
			std::cout << "O won!" << std::endl;
			break;
		case DRAW:
			std::cout << "Game ended in a draw!" << std::endl;
			break;
		case INVALID_MOVE:
			std::cout << "The last move was invalid!" << std::endl;
			break;
	}
}


int main() {
	TicTacToe2D game(3);
	game.makeMove(0, 0, true);
	game.makeMove(0, 0, false);
	game.makeMove(0, 1, true);
	game.makeMove(1, 0, false);
	printGameState(game.makeMove(0, 2, true));

	game = TicTacToe2D(3);
	game.makeMove(0, 0, true);
	game.makeMove(1, 2, false);
	game.makeMove(0, 1, true);
	game.makeMove(2, 2, false);
	printGameState(game.makeMove(0, 2, true));

	game = TicTacToe2D(3);
	printGameState(game.makeMove(0, 5, true));

	game = TicTacToe2D(3);
	game.makeMove(0, 1, true);
	printGameState(game.makeMove(0, 1, false));

	game = TicTacToe2D(3);
	game.makeMove(0, 1, true);
	printGameState(game.makeMove(0, 2, true));

	game = TicTacToe2D(3);
	game.makeMove(0, 0, true);
	game.makeMove(0, 1, false);
	game.makeMove(0, 2, true);
	game.makeMove(1, 0, false);
	game.makeMove(1, 1, true);
	game.makeMove(1, 2, false);
	game.makeMove(2, 0, true);
	game.makeMove(2, 1, false);
	printGameState(game.makeMove(2, 2, true));

	// Output should be
	// X won
	// Ongoing
	// invalid
	// invalid
	// invalid
	// draw
	return 0;
}
