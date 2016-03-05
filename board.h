#ifndef __BOARD_H__
#define __BOARD_H__

#include <string>
#include "game.h"

namespace tictactoe {
  
  const std::string SYMBOL_VIEW[NUM_SYMBOLS] = {" ", "O", "X"};

  class BoardView {

    // The board for viewing
    std::string board[DIMENSION];

    public:
      BoardView();

      // Updates the square with the symbol occupied
      void updateSquareView(Square square, Symbol symbol);

      // Prints the board
      void print();
  };
}

#endif
