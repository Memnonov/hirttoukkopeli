#include "game.hpp"
#include "hangmanui.hpp"

int main() {
  Game game{"testi"};
  HangmanUi ui{game};
  game.setGuessesMax(666);
  game.setGuessesCurrent(6666);

  return 0;
}
