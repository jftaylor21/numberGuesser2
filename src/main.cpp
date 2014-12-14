#include "engine/Game.hpp"
#include "engine/AIPlayer.hpp"
#include "numberGuesser2/CLIPlayer.hpp"

#include <iostream>

int main()
{
  Game g;

  std::cout << "Please enter the name of the player who will think of a secret number or \"ai\" for a computer player..." << std::endl;
  std::string name;
  while (name.empty())
  {
    std::getline(std::cin, name);
  }
  Game::PlayerP p1(nullptr);
  if ("ai" == name)
  {
    p1 = Game::PlayerP(new AIPlayer());
  }
  else
  {
    p1 = Game::PlayerP(new CLIPlayer(name));
  }
  GameData::PlayerID p1id(g.attach(p1));

  name = "";
  std::cout << "Please enter the first player name who will try to guess the number or \"ai\" for a computer player..." << std::endl;
  while (name.empty())
  {
    std::getline(std::cin, name);
  }
  while (name.size())
  {
    if ("ai" == name)
    {
      g.attach(Game::PlayerP(new AIPlayer()));
    }
    else
    {
      g.attach(Game::PlayerP(new CLIPlayer(name)));
    }
    std::cout << "Please enter the next player name, \"ai\" for a computer player, or empty string if complete..." << std::endl;
    std::getline(std::cin, name);
  }

  g.newGame(p1id);
  while (!g.nextTurn());
  return 0;
}

