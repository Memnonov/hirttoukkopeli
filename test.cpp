#include "game.hpp"
#include "hangmanui.hpp"
#include <iostream>

void testGame();
void testWord();

int main() {
  testGame();
  std::cin.get();
  testWord();

  return 0;
}

void testGame() {
  Game game{"testi"};
  HangmanUi ui{game};
  game.setGuessesMax(666);
  game.setGuessesCurrent(6666);
  game.guessLetter('a');
  ui.update();
}

void testWord() {
  Game game;
  std::cout << "Testataa vähä sanahommia: \n"
            << "sana: " << game.getWord() << '\n';
  game.guessLetter('d');
  game.guessLetter('e');
  game.guessLetter('f');
  game.guessLetter('a');
  game.guessLetter('u');
  game.guessLetter('l');
  game.guessLetter('t');
  std::cout << "piilotettu sana: " << game.getHiddenWord() << '\n';
};
