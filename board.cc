#include "board.h"
#include <iostream>

using std::cout;
using std::endl;
using tictactoe::BoardView;

BoardView::BoardView() {
  // Initializes each square to BLANK
  for (int square = NORTH_WEST; square < DIMENSION; square++) {
    board[square] = symbolView[BLANK];
  }
}

void BoardView::updateSquareView(Square square, Symbol symbol) {
  board[square] = symbolView[symbol];
}

// TODO
void BoardView::print() {}
