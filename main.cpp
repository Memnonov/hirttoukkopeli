#include <iostream>
#include "game.hpp"

int main() {
  std::cout << "Testi testi, " << "yy, kaa koo..." << '\n';
  printTest();

  Game game; // using the default constructor
  std::cout << "Sana on: " << game.getWord() << '\n';

  return 0;
}
