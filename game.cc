#include "game.h"
#include "player.h"

using tictactoe::Game;

Game::Game(): turn(X) {
  for (int p = NORTH_WEST; p < DIMENSION; ++p) {
    board[p] = BLANK;
  }
}

void Game::play() {
  if (turn == player1->getSymbol()) {
    player1->play();
  } else {
    player2->play();
  }
}
