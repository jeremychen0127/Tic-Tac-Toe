#ifndef __BOARD_H__
#define __BOARD_H__

#include "game.h"

// Board class
class Board {

  // The board
  tictactoe::Symbol board[tictactoe::DIMENSION];

  public:
    Board();

    // Updates the position with the symbol occupied
    void update(tictactoe::Symbol symbol, tictactoe::Position position);

    // Prints the board
    void print();
};

#endif
