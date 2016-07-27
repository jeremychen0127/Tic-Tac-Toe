#include <iostream>
#include <string>
#include "controller.h"
#include "game.h"
#include "board.h"
#include "player.h"
#include "exception.h"

using tictactoe::GameController;
using tictactoe::Square;
using tictactoe::Exception;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::string;

GameController::GameController(): turn(X) {
  game = new Game(this);
  view = new BoardView();
}

void GameController::updateSquareView(Square square, Symbol symbol) {
  view->updateSquareView(square, symbol);
}

// Gets input from user to place their X or O to the square
void selectSquare(int &intSquare) {
  cout << "Square you would like to place (enter 1-9): ";
  while (true) {
    if (cin >> intSquare && intSquare >= 1 && intSquare <= 9) break;
    else {
      cout << "Sorry! Invalid input! Please try again!" << endl;
      cout << "Square you would like to place (enter 1-9): ";
      cin.clear();
    }
  }
  cout << "---------------------------------------------------" << endl;
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
      selectSquare(intSquare);
      try {
        game->updateSquare(static_cast<Square>(intSquare - 1), X);
        turn = O;
      } catch (Exception &exception) {
        cerr << exception.getMessage() << " Please try another square" << endl;
      }
    } else {
      cout << playerO->getName() << "'s turn (O)" << endl;
      selectSquare(intSquare);
      try {
        game->updateSquare(static_cast<Square>(intSquare - 1), O);
        turn = X;
      } catch (Exception &exception) {
        cerr << exception.getMessage() << " Please try another square" << endl;
      }
    }
  } while (NOT_OVER == game->isOver());

  if (DRAW == game->isOver()) {
    cout << "The game is over! It is DRAW" << endl;
  } else {
    Symbol winner = game->getWinner(game->isOver());
    cout << "The game is over! WINNER: " << SYMBOL_VIEW[winner] << endl;
  }

  cout << "New Game (Y/N)? ";
  string response;
  cin >> response;
  if ("Y" == response || "YES" == response || "y" == response ||
      "Yes" == response || "yes" == response) {
    game->restart();
    play();
  }
}

void GameController::clearBoardView() {
  view->clear();
}
