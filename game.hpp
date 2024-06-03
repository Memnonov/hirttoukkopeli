#ifndef GAME_HPP
#define GAME_HPP

#include <string>

void printTest();

class Game {
public:
  Game() : word{"default"} {}; // default constructor

  explicit Game(std::string s)
      : word{s} {}; // construct a game from a word (string)

  const std::string &getWord() const;
  int getGuessesMax() const;
  int getGuessesCurrent() const;
  void setGuessesMax(int n);
  void setGuessesCurrent(int n);

private:
  std::string word;
  std::string wordMasked;
  int guessesMax{6};
  int guessesCurrent{0};
};

#endif // !GAME_HPP
