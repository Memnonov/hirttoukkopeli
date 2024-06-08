#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>

void printTest();

class Game {
public:
  Game() : word{"default"} { hideWord(); }; // default constructor

  explicit Game(std::string s) : word{s} {
    hideWord();
  }; // construct a game from a word (string)

  enum class GameStatus { RUNNING, WIN, LOSE };

  enum class GuessResult { RIGHT, WRONG, ALREADY_GUESSED, GAME_OVER };

  const std::string &getWord() const { return word; }
  const std::string &getHiddenWord() const { return wordHidden; }
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
  GameStatus getStatus() const { return status; }

  GuessResult guessLetter(char c);

  const std::vector<char>& getGuessedLetters() const { return guessedLetters; }

private:
  std::string word;
  std::string wordHidden;
  int guessesMax{6};
  int guessesCurrent{6};
  std::vector<char> guessedLetters;
  GameStatus status = GameStatus::RUNNING;

  void updateStatus();

  void hideWord();

  void revealLetter(char c);
};

#endif // !GAME_HPP
