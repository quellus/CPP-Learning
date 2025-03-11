#ifndef GameBoard_H_Include
#define GameBoard_H_Include

#include <string>
#include <sstream>

enum SquareState {
    FREE,
    X,
    O
};

class GameBoard {
public:
    bool end = false;
    std::string toString();
    bool isSpaceFree(int space);
    void makeMove(int space, SquareState state);
    SquareState* getBoardState() { return boardState; };
private:
    SquareState boardState[9] = {
        FREE,FREE,FREE,
        FREE,FREE,FREE,
        FREE,FREE,FREE
    };
};

#endif
