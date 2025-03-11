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

        int opponentMove = BasicOpponent().move(gameBoard);
        if (gameBoard.isSpaceFree(opponentMove)) {
            gameBoard.makeMove(opponentMove, O);
        }
        // std::cout << "Opponent moved on space " << BasicOpponent().move(gameBoard) << std::endl;
    }
}
