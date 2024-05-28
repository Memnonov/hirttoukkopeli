#include "game.hpp"
#include <iostream>
#include <string>

void printTest() {
  std::cout << "testing linked file" << '\n';
}

Game::Game() : word{"default"} {}
Game::Game(std::string s) : word{s} {}
const std::string& Game::getWord() const { return word; }
