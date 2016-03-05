#include "player.h"

using tictactoe::Player;
using std::string;
using tictactoe::Symbol;

Player::Player(string name, Symbol symbol)
    :name(name), symbol(symbol) {}

Symbol Player::getSymbol() {
  return symbol;
}

int Player::getScore() {
  return score;
}

string Player::getName() {
  return name;
}

// TODO
void Player::play() {}
