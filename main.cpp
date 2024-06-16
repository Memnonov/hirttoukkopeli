#include "game.hpp"
#include "hangmanui.hpp"

int main() {
  Game game{"testi"};
  HangmanUi ui{game};
  ui.start();

  return 0;
}
