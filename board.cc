#include "board.h"
#include <iostream>

using std::cout;
using std::endl;
using tictactoe::BoardView;

BoardView::BoardView() {
  // Initializes each square to BLANK
  for (int square = NORTH_WEST; square < DIMENSION; square++) {
    board[square] = SYMBOL_VIEW[BLANK];
  }
}

void BoardView::updateSquareView(Square square, Symbol symbol) {
  board[square] = SYMBOL_VIEW[symbol];
  print();
}

void BoardView::print() {
  cout << "___________________" << endl;
  cout << "|  " << 1 << "  |  " << 2 << "  |  " << 3 << "  |" << endl;
  cout << "|  " << board[NORTH_WEST];
  cout << "  |  " << board[NORTH];
  cout << "  |  " << board[NORTH_EAST] << "  |" << endl;
  cout << "|_____|_____|_____|" << endl;
  cout << "|  " << 4 << "  |  " << 5 << "  |  " << 6 << "  |" << endl;
  cout << "|  " << board[WEST];
  cout << "  |  " << board[CENTRE];
  cout << "  |  " << board[EAST] << "  |" << endl;
  cout << "|_____|_____|_____|" << endl;
  cout << "|  " << 7 << "  |  " << 8 << "  |  " << 9 << "  |" << endl;
  cout << "|  " << board[SOUTH_WEST];
  cout << "  |  " << board[SOUTH];
  cout << "  |  " << board[SOUTH_EAST] << "  |" << endl;
  cout << "|_____|_____|_____|" << endl;
}
