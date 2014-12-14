#include "engine/Game.hpp"
#include "engine/AIPlayer.hpp"
#include "cli/CLIPlayer.hpp"

#include <iostream>

int main()
{
  engine::Game g;

  std::cout << "Please enter the name of the player who will think of a secret number or \"ai\" for a computer player..." << std::endl;
  std::string name;
  while (name.empty())
  {
    std::getline(std::cin, name);
  }
  engine::Game::PlayerP p1(nullptr);
  if ("ai" == name)
  {
    p1 = engine::Game::PlayerP(new engine::AIPlayer());
  }
  else
  {
    p1 = engine::Game::PlayerP(new cli::CLIPlayer(name));
  }
  engine::GameData::PlayerID p1id(g.attach(p1));

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
      g.attach(engine::Game::PlayerP(new engine::AIPlayer()));
    }
    else
    {
      g.attach(engine::Game::PlayerP(new cli::CLIPlayer(name)));
    }
    std::cout << "Please enter the next player name, \"ai\" for a computer player, or empty string if complete..." << std::endl;
    std::getline(std::cin, name);
  }

  g.newGame(p1id);
  while (!g.nextTurn());
  return 0;
}

