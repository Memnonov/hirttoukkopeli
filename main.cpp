#include "game.hpp"
#include <iostream>

int main() {
  std::cout << "Testi testi, "
            << "yy, kaa koo..." << '\n';
  printTest();

  std::cout << "Paina jottai >" << '\n';
  std::cin.get();

  Game game; // using the default constructor
  game.refresh();
  std::cout << "Sana on: " << game.getWord() << '\n';

  std::cout << "Arvauksia\tmax: " << game.getGuessesMax()
            << " | nyt: " << game.getGuessesCurrent() << '\n';

  game.setGuessesMax(666);
  game.setGuessesCurrent(6666);

  std::cout << "Arvauksia\tmax: " << game.getGuessesMax()
            << " | nyt: " << game.getGuessesCurrent() << '\n';

  return 0;
}
