#include "board.h"
#include <iostream>

using std::cout;
using std::endl;
using tictactoe::Board;

Board::Board() {
  // Initializes each position to BLANK
  for (int p = NORTH_WEST; p < DIMENSION; p++) {
    board[p] = BLANK;
  }
}

void Board::update(Symbol symbol, Position position) {
  board[position] = symbol;
}

// TODO
void Board::print() {}
