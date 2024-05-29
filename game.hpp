#ifndef GAME_HPP
#define GAME_HPP

#include <string>

void printTest();

class Game {
public:
  Game();              // default constructor
  Game(std::string s); // construct a game from a word (string)

  const std::string &getWord() const;
  int getGuessesMax() const;
  int getGuessesCurrent() const;

  void setGuessesMax(int n);
  void setGuessesCurrent(int n);

  /* Refresh the game status on the console */
  void refresh() const;

private:
  std::string word;
  std::string wordMasked;
  int guessesMax{6};
  int guessesCurrent{0};

  void clearConsole() const;
};

#endif // !GAME_HPP
