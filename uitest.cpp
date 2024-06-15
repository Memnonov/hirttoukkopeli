#include "game.hpp"
#include "hangmanui.hpp"
#include <iostream>

bool testWrongGuesses(bool verbose = false);

int main() {
  testWrongGuesses(true);
  std::cin.ignore();
  Game game{"olut"};
  for (auto c : "xyzol") {
    if (c == '\0') continue;
    game.guessLetter(c);
  }
  HangmanUi ui{game};
  ui.start();
}

bool testWrongGuesses(bool verbose) {
  Game game{"olut"};
  HangmanUi ui{game};
  for (auto c : "oollluuxyz") {
    game.guessLetter(c);
  }
  bool res = ui.wrongGuesses() == "x y z ";

  if (verbose) {
    std::cout << "testWrongGuesses --> odotettu: 'x y z '" 
              << " | palautus: '" << ui.wrongGuesses() << "'\n";
  }

  std::cout << "testWrongGuesses: " << ((res) ? "OK!\n" : "Epäonnistui!\n") ;

  return res;
}
