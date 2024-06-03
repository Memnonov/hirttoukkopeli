#include "game.hpp"
#include <iostream>
#include <string>

/* For  testing. */
void printTest() { std::cout << "testing linked file" << '\n'; }

/* Actual class Game implementation. */
const std::string &Game::getWord() const { return word; }
int Game::getGuessesMax() const { return guessesMax; }
void Game::setGuessesMax(int n) { guessesMax = (n > 0) ? n : 1; }
int Game::getGuessesCurrent() const { return guessesCurrent; }
void Game::setGuessesCurrent(int n) {
  if (n < 0) {
    guessesCurrent = 0;
    return;
  }
  guessesCurrent = (n > guessesMax) ? guessesMax : n;
}
