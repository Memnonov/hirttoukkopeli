#include "game.hpp"
#include <iostream>
#include <string>

/* For  testing. */
void printTest() { std::cout << "testing linked file" << '\n'; }

/* Actual class Game implementation. */

bool Game::guessLetter(char c) {
  // do stuff...
  return true;
}

void Game::hideWord() {
  wordHidden = std::string(word.length(), '*'); // using a fancy constructor
}
