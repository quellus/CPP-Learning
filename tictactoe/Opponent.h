#ifndef Opponent_Interface_H_Include
#define Opponent_Interface_H_Include

#include "GameBoard.h"

class Opponent {
public:
    virtual int move(GameBoard gameBoard) = 0;
};

#endif
