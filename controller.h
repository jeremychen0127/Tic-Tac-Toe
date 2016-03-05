#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include "game.h"

namespace tictactoe {

  class BoardView;
  class Player;

  class GameController {
    Game *game;
    BoardView *view;
    Symbol turn;
    Player *player1;
    Player *player2;

    public:
      GameController();

      // Updates the square view
      // Intended to be called by Game
      void updateSquareView(Square square, Symbol symbol);

      // Starts the game
      void play();
  };
}

#endif
