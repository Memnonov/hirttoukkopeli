#include "game.hpp"
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <string>

void Game::hideWord() {
  wordHidden = std::string(word.length(), '*'); // using a fancy constructor
}

void Game::updateStatus() {
  if (wordHidden.find('*') == std::string::npos) {
    status = Game::GameStatus::WIN;
  }
  if (guessesCurrent < 1) {
    status = Game::GameStatus::LOSE;
  }
}

Game::GuessResult Game::guessLetter(char c) {
  c = (char) tolower(c);

  if (status != Game::GameStatus::RUNNING) {
    return Game::GuessResult::GAME_OVER;
  }

  if (std::find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end()) {
    updateStatus();
    return Game::GuessResult::ALREADY_GUESSED;
  }

  guessedLetters.push_back(c);

  if (word.find(c) != std::string::npos) {
    revealLetter(c);
    updateStatus();
    return Game::GuessResult::RIGHT;
  }
  setGuessesCurrent(--guessesCurrent);
  updateStatus();
  return Game::GuessResult::WRONG;
}

void Game::revealLetter(char c) {
  size_t i = word.find(c);
  while (i != std::string::npos) {
    wordHidden[i] = c;
    i = word.find(c, i + 1);
  }
}
