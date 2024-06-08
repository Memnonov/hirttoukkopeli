#include "hangmanui.hpp"
#include <iostream>

void HangmanUi::update() const {
  clear();
  std::cout << "Sana on: " << game.getWord() << '\n';
  std::cout << "Piilotettu sana: " << game.getHiddenWord() << '\n';
  std::cout << "Arvauksia\tmax: " << game.getGuessesMax()
            << " | nyt: " << game.getGuessesCurrent() << '\n';
}

void HangmanUi::clear() const { std::cout << "\033[2J\033[H"; }
