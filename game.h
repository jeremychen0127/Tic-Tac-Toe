#ifndef __GAME_H__
#define __GAME_H__

namespace tictactoe {

  const int DIMENSION = 3 * 3;

  enum Symbol {BLANK, O, X};

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
}

#endif
