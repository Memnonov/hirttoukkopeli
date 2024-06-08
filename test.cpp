#include "game.hpp"
#include "hangmanui.hpp"
#include <iostream>
#include <string>

void testGame();
void testWord();
void testStatus();

int main() {
  testGame();
  std::cin.get();
  testWord();
  std::cin.get();
  testStatus();

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

void testStatus() {
  std::string word = "olut";
  Game game1(word);
  std::cout << "--- Pitäisi voittaa peli! ---\n"
            << "arvauksia jäljellä: " << game1.getGuessesCurrent() << '\n';
  for (auto c : word) {
    std::cout << "arvataan " << c << '\n';
    game1.guessLetter(c);
  }
  std::cout << "piilotettu sana: " << game1.getHiddenWord()
            << " | arvauksia jälj.: " << game1.getGuessesCurrent() << '\n';
  std::string s;
  s = (game1.getStatus() == Game::GameStatus::WIN) ? "win" : "lose";
  std::cout << s << '\n';
}
