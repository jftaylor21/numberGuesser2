#include "numberGuesser2/Game.hpp"
#include "numberGuesser2/CLIPlayer.hpp"

#include <iostream>

int main()
{
  Game g;

  std::cout << "Please enter the name of the player who will think of a secret number..." << std::endl;
  std::string name;
  while (name.empty())
  {
    std::getline(std::cin, name);
  }
  GameData::PlayerID p1id(g.attach(Game::PlayerP(new CLIPlayer(name))));

  name = "";
  std::cout << "Please enter the first player name who will try to guess the number..." << std::endl;
  while (name.empty())
  {
    std::getline(std::cin, name);
  }
  while (name.size())
  {
    g.attach(Game::PlayerP(new CLIPlayer(name)));
    std::cout << "Please enter the next player name or empty string if complete..." << std::endl;
    std::getline(std::cin, name);
  }

  g.newGame(p1id);
  while (!g.nextTurn());
  return 0;
}

