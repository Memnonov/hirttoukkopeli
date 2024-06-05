#include "game.hpp"
#include "ui.hpp"

int main() {
  Game game{"testi"};
  HangmanUi ui{game};
  game.setGuessesMax(666);
  game.setGuessesCurrent(6666);
  ui.update();

  return 0;
}
