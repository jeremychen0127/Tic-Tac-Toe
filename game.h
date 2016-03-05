#ifndef __GAME_H__
#define __GAME_H__

namespace tictactoe {

  // Board dimension
  const int DIMENSION = 3 * 3;
  // Number of symbols
  const int NUM_SYMBOLS = 3;

  // Symbols to be placed (or nothing placed) on the board
  enum Symbol {BLANK, O, X};

  // Each square on the board
  enum Square {
    NORTH_WEST,
    NORTH,
    NORTH_EAST,
    WEST,
    CENTRE,
    EAST,
    SOUTH_WEST,
    SOUTH,
    SOUTH_EAST
  };

  enum WinningCase {
    TOP_ROW,
    CENTRE_ROW,
    BOTTOM_ROW,
    LEFT_COLUMN,
    CENTRE_COLUMN,
    RIGHT_COLUMN,
    TOP_LEFT_DIAGONAL, // top-left to bottom-right
    TOP_RIGHT_DIAGONAL, // top-right to bottom-left
    DRAW,
    NOT_OVER
  };

  class GameController;

  // Game class for handling the game
  class Game {
    GameController *gameController;
    Symbol board[DIMENSION];

    // If a player wins, returns the line of winning
    // If draw, return DRAW
    // If the game is not over yet, return NOT_OVER
    WinningCase isOver();

    // Returns
    //   O if O is the winner
    //   X if X is the winner
    Symbol getWinner(WinningCase winningCase);

    public:
      Game(GameController *gameController);

      // Updates the symbol on the square
      // Intended to be called by Player
      void updateSquare(Square square, Symbol symbol);
  };
}

#endif
