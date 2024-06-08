#include "game.hpp"
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

void Game::hideWord() {
  wordHidden = std::string(word.length(), '*'); // using a fancy constructor
}

void Game::updateStatus() {
  if (wordHidden.find('*') == std::string::npos) {
    status = Game::GameStatus::WIN;
    std::cout << "asetettiin WIN\n";
  }
  if (guessesCurrent < 1) {
    status = Game::GameStatus::LOSE;
    std::cout << "asetettiin LOSE\n";
  }
}

Game::GuessResult Game::guessLetter(char c) {
  std::cout << "@ guessLetter\n";
  if (status != Game::GameStatus::RUNNING) {
    std::cout << "@ return GAME_OVER\n";
    return Game::GuessResult::GAME_OVER;
  }

  if (std::find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end()) {
    updateStatus();
    std::cout << "@ return ALREADY_GUESSED\n";
    return Game::GuessResult::ALREADY_GUESSED;
  }

  guessedLetters.push_back(c);

  if (word.find(c) != std::string::npos) {
    revealLetter(c);
    updateStatus();
    std::cout << "@ return RIGHT\n";
    return Game::GuessResult::RIGHT;
  }
  setGuessesCurrent(--guessesCurrent);
  updateStatus();
  std::cout << "@ return WRONG\n";
  return Game::GuessResult::WRONG;
}

void Game::revealLetter(char c) {
  size_t i = word.find(c);
  while (i != std::string::npos) {
    wordHidden[i] = c;
    i = word.find(c, i + 1);
  }
}
