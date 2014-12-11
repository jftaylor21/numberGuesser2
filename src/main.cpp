#include "numberGuesser2/Game.hpp"
#include "numberGuesser2/Player.hpp"

int main()
{
  Game::PlayerP p1(new Player("p1"));
  Game::PlayerP p2(new Player("p2"));

  Game g;
  GameData::PlayerID p1id(g.attach(p1));
  g.attach(p2);
  g.newGame(p1id);
  while (!g.nextTurn());
  return 0;
}

