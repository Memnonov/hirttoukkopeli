#include "game.hpp"
#include <iostream>
#include <string>

/* For  testing. */
void printTest() { std::cout << "testing linked file" << '\n'; }

/* Actual class Game implementation. */

Game::Game() : word{"default"} {}
Game::Game(std::string s) : word{s} {}

const std::string &Game::getWord() const { return word; }
int Game::getGuessesMax() const { return guessesMax; }
int Game::getGuessesCurrent() const { return guessesCurrent; }

void Game::setGuessesMax(int n) { guessesMax = (n > 0) ? n : 1; }

void Game::setGuessesCurrent(int n) {
  if (n < 0) {
    guessesCurrent = 0;
    return;
  }
  guessesCurrent = (n > guessesMax) ? guessesMax : n;
}

void Game::clearConsole() const { std::cout << "\033[2J\033[H"; }

void Game::refresh() const {
  clearConsole();
}

