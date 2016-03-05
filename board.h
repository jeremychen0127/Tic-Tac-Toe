#ifndef __BOARD_H__
#define __BOARD_H__

#include "game.h"

namespace tictactoe {
  // Board class
  class Board {

    // The board
    Symbol board[DIMENSION];

    public:
      Board();

      // Updates the position with the symbol occupied
      void update(Symbol symbol, Position position);

      // Prints the board
      void print();
  };
}

#endif
