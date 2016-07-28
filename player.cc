#include "player.h"

using tictactoe::Player;
using std::string;
using tictactoe::Symbol;

Player::Player(string name, Symbol symbol, bool isComputerPlayer)
    :symbol(symbol), name(name), isComputerPlayer(isComputerPlayer) {}

Symbol Player::getSymbol() {
  return symbol;
}

int Player::getScore() {
  return score;
}

string Player::getName() {
  return name;
}

bool Player::isComputer() {
  return isComputerPlayer;
}
