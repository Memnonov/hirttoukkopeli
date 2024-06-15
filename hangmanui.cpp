#include "hangmanui.hpp"
#include <algorithm>
#include <iostream>
#include <string>

const std::string GAME_NAME = "--- HirttoUkkoPeli ---";

void HangmanUi::start() {
  updateScreen();
}

void HangmanUi::updateScreen() const {
  clear();
  std::cout << GAME_NAME << "\n\n"
            << "Sana: " << game.getHiddenWord()
            << "\t\tArvatut kirjaimet: " << getWrongGuesses();
}

std::string HangmanUi::wrongGuesses() const { return getWrongGuesses(); };

void HangmanUi::clear() const { std::cout << "\033[2J\033[H"; }

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
