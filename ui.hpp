#ifndef UI_HPP
#define UI_HPP

#include "game.hpp"

class HangmanUi {
public:
  explicit HangmanUi(Game &game) : game{game} {};
  void update() const;

private:
  Game &game;

  void clear() const;
};

#endif // !UI_HPP
