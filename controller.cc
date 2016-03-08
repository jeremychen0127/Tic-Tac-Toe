#include <iostream>
#include <string>
#include "controller.h"
#include "game.h"
#include "board.h"
#include "player.h"

using tictactoe::GameController;
using tictactoe::Square;
using std::cin;
using std::cout;
using std::endl;
using std::string;

GameController::GameController(): turn(X) {
  game = new Game(this);
  view = new BoardView();
}

void GameController::updateSquareView(Square square, Symbol symbol) {
  view->updateSquareView(square, symbol);
}

void GameController::play() {
  string name;
  cout << "Name of Player X: ";
  cin >> name;
  playerX = new Player(name, X);
  cout << "Name of Player O: ";
  cin >> name;
  playerO = new Player(name, O);
  view->print();

  int intSquare;
  do {
    if (X == turn) {
      cout << playerX->getName() << "'s turn (X)" << endl;
      cout << "Square you would like to place (enter 1-9): ";
      cin >> intSquare;
      cout << "---------------------------------------------------" << endl;
      game->updateSquare(static_cast<Square>(intSquare - 1), X);
      turn = O;
    } else {
      cout << playerO->getName() << "'s turn (O)" << endl;
      cout << "Square you would like to place (enter 1-9): ";
      cin >> intSquare;
      cout << "---------------------------------------------------" << endl;
      game->updateSquare(static_cast<Square>(intSquare - 1), O);
      turn = X;
    }
  } while (NOT_OVER == game->isOver());

  if (DRAW == game->isOver()) {
    cout << "The game is over! It is DRAW" << endl;
  } else {
    Symbol winner = game->getWinner(game->isOver());
    cout << "The game is over! WINNER: " << SYMBOL_VIEW[winner] << endl;
  }
}
