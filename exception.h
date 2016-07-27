#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>

namespace tictactoe {

  // Exception class
  class Exception {
    std::string message;

    public:
      explicit Exception(std::string message);

      // Gets the error message
      std::string getMessage();
  };
}

#endif
