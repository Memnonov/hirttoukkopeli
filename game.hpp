#ifndef GAME_HPP
#define GAME_HPP

#include <string>

void printTest();

class Game {
public:
  Game() : word{"default"} { hideWord(); }; // default constructor

  explicit Game(std::string s) : word{s} {
    hideWord();
  }; // construct a game from a word (string)

  const std::string &getWord() const { return word; }
  const std::string& getHiddenWord() const { return wordHidden; }
  int getGuessesMax() const { return guessesMax; }
  void setGuessesMax(int n) { guessesMax = (n > 0) ? n : 1; }
  int getGuessesCurrent() const { return guessesCurrent; }
  void setGuessesCurrent(int n) {
    if (n < 0) {
      guessesCurrent = 0;
      return;
    }
    guessesCurrent = (n > guessesMax) ? guessesMax : n;
  }

  bool guessLetter(char c);

private:
  std::string word;
  std::string wordHidden;
  int guessesMax{6};
  int guessesCurrent{0};

  void hideWord();
};

#endif // !GAME_HPP
