#include "game.hpp"
#include "hangmanui.hpp"
#include <iostream>
#include <string>
#include <vector>

std::string toString(Game::GameStatus);
std::string toString(Game::GuessResult);
void testUi();
bool testGameEnd(std::string word, std::string letters = "", bool result = true,
              bool verbose = false);
void testWin();
void testLose();

int main() {
  testUi();
  std::cin.get();
  std::vector<bool> results;
  results.push_back(testGameEnd("olut", "olut", true, false));
  results.push_back(testGameEnd("olut", "oolluutt", true, false));
  results.push_back(testGameEnd("olut", "kkalexsiii", false, false));
  // std::cout << "Tää niinku epäonnistuu tahallaa...\n";
  // results.push_back(testGameEnd("olut", "kkalexsiii"));

  int fail{0};
  for (auto res : results) {
    if (!res) {
      fail++;
    }
  }

  if (fail) {
    std::cout << "Epäonnistuneita testejä! Läpi " << results.size() - fail
              << '/' << results.size() << '\n';
  } else {
    std::cout << "Kaikki testit OK! (" << results.size() << " kpl)\n";
  }

  return 0;
}

std::string toString(Game::GameStatus status) {
  using Status = Game::GameStatus;
  switch (status) {
  case Status::RUNNING:
    return "Running";
  case Status::LOSE:
    return "Lose";
  case Status::WIN:
    return "Win";
  default:
    return "Unkown";
  }
}

std::string toString(Game::GuessResult guess) {
  using Guess = Game::GuessResult;
  switch (guess) {
  case Guess::RIGHT:
    return "Right";
  case Guess::WRONG:
    return "Wrong";
  case Guess::ALREADY_GUESSED:
    return "Already guessed";
  case Guess::GAME_OVER:
    return "Game Over";
  default:
    return "Unkown";
  }
}

bool testGameEnd(std::string word, std::string letters, bool result,
              bool verbose) {
  if (verbose)
    std::cout << "Testataan sanalla: " << word << '\n';

  Game game{word};
  if (letters.empty()) {
    letters = word;
  }

  for (auto c : letters) {
    if (verbose) {
      std::cout << "--> " << game.getHiddenWord()
                << " | arvauksia jäljellä: " << game.getGuessesCurrent()
                << '\n';
    }
    auto guess = game.guessLetter(c);
    if (verbose) {
      std::cout << "  arvataan: " << c << " | tulos: " << toString(guess)
                << '\n';
    }
  }

  if (verbose) {
    std::cout << "  game result: " << toString(game.getStatus())
              << " | expected: " << ((result) ? "Win" : "Lose") << '\n';
  }
  if (game.getStatus() == Game::GameStatus::RUNNING) {
    std::cout << "  Game is still running!";
    return false;
  }
  if (game.getStatus() == Game::GameStatus::WIN && result == true) {
    std::cout << "  Testi OK!\n\n";
    return true;
  }
  if (game.getStatus() == Game::GameStatus::LOSE && result == false) {
    std::cout << "  Testi OK!\n\n";
    return true;
  }
  std::cout << "  Testi epäonnistui!\n\n";
  return false;
}

void testUi() {
  Game game{"testi"};
  HangmanUi ui{game};
  game.setGuessesMax(666);
  game.setGuessesCurrent(6666);
  game.guessLetter('a');
  ui.update();
}
