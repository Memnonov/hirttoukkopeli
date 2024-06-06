#include "game.hpp"
#include <cstddef>
#include <iostream>
#include <string>

/* For  testing. */
void printTest() { std::cout << "testing linked file" << '\n'; }

/* Actual class Game implementation. */

Game::GuessResult Game::guessLetter(char c) {
  if (word.find(c)) {
    revealLetter(c);
    return Game::GuessResult::RIGHT;
  }
  return Game::GuessResult::WRONG;
}

void Game::hideWord() {
  wordHidden = std::string(word.length(), '*'); // using a fancy constructor
}

// TODO: Jaa ei toimi vielä
void Game::revealLetter(char c) {
  size_t i = word.find(c);
  while (i != std::string::npos) {
    wordHidden[i] = c;
    i = word.find(c, i + 1);
  }
}
