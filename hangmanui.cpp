#include "hangmanui.hpp"
#include "game.hpp"
#include <cctype>
#include <iostream>
#include <string>

// Public stuff

void HangmanUi::start() {
  bool gameOver = false;
  while (true) {
    updateScreen();
    displayMessages();
    if (gameOver) {
      break;
    }
    if (getPlayerInput() == QUIT_INPUT) {
      gameOver = true;
    }
    if (game.getStatus() != Game::GameStatus::RUNNING) {
      gameOver = true;
    }
  }
}

void HangmanUi::updateScreen() const {
  clear();
  std::cout << GAME_NAME << "\n\n"
            << "Sana: " << game.getHiddenWord()
            << "\t Arvauksia jäljellä: " << game.getGuessesCurrent()
            << "\t| Arvattu: " << getWrongGuesses() << "\n\n";
}

char HangmanUi::getPlayerInput() {
  std::cout << INPUT_PROMPT;
  char inp = input();
  if (inp == QUIT_INPUT || inp == INVALID_INPUT) {
    if (inp == QUIT_INPUT) {
      messages.push_back(QUIT_MESSAGE);
    }
    return inp;
  }

  Game::GuessResult res = game.guessLetter(inp);
  switch (res) {
  case Game::GuessResult::RIGHT:
    messages.push_back(GUESS_MESSAGE + " " + inp + " : Oikein!");
    break;
  case Game::GuessResult::WRONG:
    messages.push_back(GUESS_MESSAGE + " " + inp + " : Väärin!");
    break;
  default:
    break;
  }

  if (game.getStatus() == Game::GameStatus::WIN) {
    messages.push_back(WIN_MESSAGE);
  }
  if (game.getStatus() == Game::GameStatus::LOSE) {
    messages.push_back(LOSE_MESSAGE);
  }

  return inp;
}

void HangmanUi::displayMessages() {
  for (auto &line : messages) {
    std::cout << line << '\n';
  }
  std::cout << "\n";
  messages.clear();
}

// For testing purposes
std::string HangmanUi::wrongGuesses() const { return getWrongGuesses(); };

void HangmanUi::clear() const { std::cout << "\033[2J\033[H"; }

char HangmanUi::input() {
  std::string input;
  std::getline(std::cin, input);
  if (input == QUIT_GAME) {
    return QUIT_INPUT;
  }
  if (input.length() != 1 || !std::isalpha(input[0])) {
    return INVALID_INPUT;
  }
  return input[0];
}

// Private stuff

std::string HangmanUi::getWrongGuesses() const {
  std::string result;
  for (auto c : game.getGuessedLetters()) {
    if (game.getWord().find(c) == std::string::npos) {
      if (c == '\0')
        continue;
      result += c;
      result += " ";
    }
  }
  return result;
}
