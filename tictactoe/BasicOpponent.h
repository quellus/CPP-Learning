#ifndef Basic_Opponent_H_Include
#define Basic_Opponent_H_Include

#include <vector>

#include "Opponent.h"

class BasicOpponent : public Opponent {
public:
    int move(GameBoard gameBoard);
};

#endif