#ifndef GAME_HPP
#define GAME_HPP

#include <string>

void printTest();

class Game {
public:
  Game(); // default constructor
  Game(std::string s); // construct a game from a word
  const std::string& getWord() const;

private:
  std::string word;
};


#endif // !GAME_HPP
