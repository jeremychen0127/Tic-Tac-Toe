#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>
#include "game.h"

namespace tictactoe {
  class Player {
    Symbol symbol;
    std::string name;
    int score;

    public:
      Player(std::string name, Symbol symbol);
      Symbol getSymbol();
      int getScore();
      std::string getName();
      void play();
  };
}

#endif
