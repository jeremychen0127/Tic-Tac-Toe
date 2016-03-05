#include "controller.h"
#include "game.h"
#include "board.h"
#include "player.h"

using tictactoe::GameController;

GameController::GameController(): turn(X) {
  game = new Game(this);
  view = new BoardView();
}

void GameController::updateSquareView(Square square, Symbol symbol) {
  view->updateSquareView(square, symbol);
}

// TODO
void GameController::play() {}
