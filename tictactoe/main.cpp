#include <iostream>

#include "GameBoard.h"
#include "BasicOpponent.h"


int main() {
    GameBoard gameBoard = GameBoard();
    while (!gameBoard.end) {
        std::cout << gameBoard.toString() << std::endl;

        std::cout << "Where do you want to place an X?" << std::endl;
        int userMove;
        std::cin >> userMove;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Move invalid, please select a free space " << std::endl;
            continue;
        }

        if (gameBoard.isSpaceFree(userMove)) {
            gameBoard.makeMove(userMove, X);
        } else {
            std::cout << "Move invalid, please select a free space " << std::endl;
        }

        gameBoard.checkGameEnd();


        int opponentMove = BasicOpponent().move(gameBoard);
        if (gameBoard.isSpaceFree(opponentMove)) {
            gameBoard.makeMove(opponentMove, O);
        }

		gameBoard.checkGameEnd();
    }

    std::cout << gameBoard.toString() << std::endl;

    if (gameBoard.winner == X) {
		std::cout << "You win!" << std::endl;
	} else if (gameBoard.winner == O) {
	 std::cout << "You lose!" << std::endl;
	} else {
		std::cout << "It's a draw!" << std::endl;
	}
}
