#include "game.hpp"
#include "ui.hpp"
#include <iostream>

int main() {
  std::cout << "Testi testi, "
            << "yy, kaa koo..." << '\n';
  printTest();

  std::cout << "Paina jottai >" << '\n';
  std::cin.get();

  Game game{"testi"};
  HangmanUi ui{game};
  game.setGuessesMax(666);
  game.setGuessesCurrent(6666);
  ui.update();

  return 0;
}
