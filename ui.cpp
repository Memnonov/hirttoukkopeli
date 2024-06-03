#include "ui.hpp"
#include <iostream>

void Ui::update() const {
  clear();
  std::cout << "Sana on: " << game.getWord() << '\n';
  std::cout << "Arvauksia\tmax: " << game.getGuessesMax()
            << " | nyt: " << game.getGuessesCurrent() << '\n';
}

void Ui::clear() const { std::cout << "\033[2J\033[H"; }
