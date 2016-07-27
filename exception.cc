#include "exception.h"

using tictactoe::Exception;
using std::string;

Exception::Exception(string message): message(message) {}

string Exception::getMessage() {
  return this->message;
}
