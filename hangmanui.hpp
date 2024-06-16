#ifndef UI_HPP
#define UI_HPP

#include "game.hpp"
#include <string>
#include <vector>

const char QUIT_INPUT = 0;
const char INVALID_INPUT = 1;

const std::string GAME_NAME = "--- HirttoUkkoPeli ---";
const std::string QUIT_GAME = "exit";
const std::string START_MESSAGE = "Peli alkaa...";
const std::string INPUT_PROMPT = "Arvaa kirjain tai kirjoita '" + QUIT_GAME + "'\n> ";
const std::string WIN_MESSAGE = "Voitit pelin!";
const std::string GUESS_MESSAGE = "Arvasit: ";
const std::string LOSE_MESSAGE = "Hävisit pelin!";
const std::string QUIT_MESSAGE = "Suljetaan peli...";

class HangmanUi {
public:
  explicit HangmanUi(Game &game) : game{game} {};

  std::string wrongGuesses() const;

  void start();

  void reset();

  char getPlayerInput();

private:
  Game &game;

  std::vector<std::string> messages{START_MESSAGE};

  char input();

  void displayMessages();

  std::string getWrongGuesses() const;

  void updateScreen() const;

  void clear() const;
};

#endif // !UI_HPP
