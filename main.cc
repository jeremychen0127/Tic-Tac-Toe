#include "controller.h"

using tictactoe::GameController;

int main() {
  GameController *gameController = new GameController();
  gameController->play();
  delete gameController;
}
