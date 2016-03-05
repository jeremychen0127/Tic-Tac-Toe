#ifndef __GAME_H__
#define __GAME_H__

namespace tictactoe {

  // Board dimension
  const int DIMENSION = 3 * 3;

  // Symbols to be placed (or nothing placed) on the board
  enum Symbol {BLANK, O, X};

  // Each block on the board
  enum Position {
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

  class Player;

  // Game class for handling the game flow
  class Game {
    Symbol board[DIMENSION];
    Symbol turn;
    Player *player1;
    Player *player2;

    public:
      Game();
      void play();
  };
}

#endif
