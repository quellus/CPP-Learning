#include <iostream>
#include <cstring>
#include <ctime>
#include <chrono>


enum Move {
    PAPER,
    ROCK,
    SCISSORS
};
  
std::string moveToString(Move move) {
    switch (move) {
        case PAPER:
            return "Paper";
        case ROCK:
            return "Rock";
        case SCISSORS:
            return "Scissors";
    }
    return "";
}

void playGame(Move move) {
    std::cout << "You played " << moveToString(move) << std::endl;
    Move botMove = Move(rand() % 3);
    std::cout << "Bot played " << moveToString(botMove) << std::endl;
    switch (move) {
        case PAPER:
            switch (botMove) {
                case PAPER:
                    std::cout << "You tied!" << std::endl;
                    break;
                case ROCK:
                    std::cout << "You win!" << std::endl;
                    break;
                case SCISSORS:
                    std::cout << "You lose!" << std::endl;
                    break;
            }
            break;
        case ROCK:
            switch (botMove) {
                case PAPER:
                    std::cout << "You lose!" << std::endl;
                    break;
                case ROCK:
                    std::cout << "You tied!" << std::endl;
                    break;
                case SCISSORS:
                    std::cout << "You win!" << std::endl;
                    break;
            }
            break;
        case SCISSORS:
            switch (botMove) {
                case PAPER:
                    std::cout << "You win!" << std::endl;
                    break;
                case ROCK:
                    std::cout << "You lose!" << std::endl;
                    break;
                case SCISSORS:
                    std::cout << "You tied!" << std::endl;
                    break;
            }
            break;
    }
}


int printUsageHelpAndExit() {
    std::cout << "usage:" << std::endl;
    std::cout << "\t-p paper" << std::endl;
    std::cout << "\t-r rock" << std::endl;
    std::cout << "\t-s scissors" << std::endl;
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        return printUsageHelpAndExit();
    } else {
        srand(time(0));
        if (strcmp(argv[1], "-p") == 0) {
            playGame(PAPER);
        } else if (strcmp(argv[1], "-r") == 0) {
            playGame(ROCK);
        } else if (strcmp(argv[1], "-s") == 0) {
            playGame(SCISSORS);
        } else {
            return printUsageHelpAndExit();
        }
    }
}
