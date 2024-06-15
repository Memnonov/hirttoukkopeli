#ifndef UI_HPP
#define UI_HPP

#include "game.hpp"
#include <vector>

class HangmanUi {
public:
  explicit HangmanUi(Game &game) : game{game} {};

  std::string wrongGuesses() const;

  void start();

  void reset();



private:
  Game &game;

  std::string getWrongGuesses() const;

  void updateScreen() const;

  void clear() const;
};

#endif // !UI_HPP
