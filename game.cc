#include "game.h"
#include "controller.h"

using tictactoe::Game;
using tictactoe::WinningCase;
using tictactoe::Symbol;

WinningCase Game::isOver() {
  for (int square = NORTH_WEST; square < DIMENSION; ++square) {
    if (BLANK == board[square]) {
      return NOT_OVER;
    }
  }

  if (board[CENTRE] == board[NORTH_WEST]) {
    if (board[CENTRE] == board[SOUTH_EAST]) {
      return TOP_LEFT_DIAGONAL;
    }
  }

  if (board[CENTRE] == board[NORTH_EAST]) {
    if (board[CENTRE] == board[SOUTH_WEST]) {
      return TOP_RIGHT_DIAGONAL;
    }
  }

  if (board[CENTRE] == board[NORTH]) {
    if (board[CENTRE] == board[SOUTH]) {
      return CENTRE_COLUMN;
    }
  }

  if (board[CENTRE] == board[WEST]) {
    if (board[CENTRE] == board[EAST]) {
      return CENTRE_ROW;
    }
  }

  if (board[NORTH_WEST] == board[NORTH]) {
    if (board[NORTH_WEST] == board[NORTH_EAST]) {
      return TOP_ROW;
    }
  }

  if (board[NORTH_WEST] == board[WEST]) {
    if (board[NORTH_WEST] == board[SOUTH_WEST]) {
      return LEFT_COLUMN;
    }
  }

  if (board[SOUTH_EAST] == board[SOUTH]) {
    if (board[SOUTH_EAST] == board[SOUTH_WEST]) {
      return BOTTOM_ROW;
    }
  }

  if (board[SOUTH_EAST] == board[EAST]) {
    if (board[SOUTH_EAST] == board[NORTH_EAST]) {
      return RIGHT_COLUMN;
    }
  }

  for (int square = NORTH_WEST; square < DIMENSION; ++square) {
    if (BLANK == board[square]) {
      return NOT_OVER;
    }
  }

  return DRAW;
}

Symbol Game::getWinner(WinningCase winningCase) {
  switch (winningCase) {
    case TOP_LEFT_DIAGONAL:
    case TOP_RIGHT_DIAGONAL:
    case CENTRE_ROW:
    case CENTRE_COLUMN:
      return board[CENTRE];

    case TOP_ROW:
    case LEFT_COLUMN:
      return board[NORTH_WEST];

    case BOTTOM_ROW:
    case RIGHT_COLUMN:
      return board[SOUTH_EAST];

    default:
      return BLANK;
  }
}

Game::Game(GameController *gameController): gameController(gameController) {
  for (int square = NORTH_WEST; square < DIMENSION; ++square) {
    board[square] = BLANK;
  }
}

void Game::updateSquare(Square square, Symbol symbol) {
  board[square] = symbol;
  gameController->updateSquareView(square, symbol);
}
