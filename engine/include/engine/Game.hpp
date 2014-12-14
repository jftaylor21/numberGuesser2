#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "GameData.hpp"
#include "InputData.hpp"

#include <memory>
#include <map>

class Game
{
 public:
  typedef std::shared_ptr<Player> PlayerP;

  Game();

  GameData::PlayerID attach(PlayerP player);
  void detach(GameData::PlayerID player);

  bool nextTurn();
  void newGame(GameData::PlayerID originatorID);

 private:
  typedef std::map<GameData::PlayerID, PlayerP> PlayerMap;

  PlayerMap::const_iterator incrementIterator(PlayerMap::const_iterator it) const;
  GameData::PlayerID getNextPlayer(GameData::PlayerID currentPlayer) const;
  void sendUpdatesToEveryone();

  PlayerMap mPlayers;
  GameData::PlayerID mNextID;

  GameData mGameData;
  InputData::Guess mSecretNumber;
  GameData::PlayerID mOriginatorID;
  GameData::PlayerID mCurrentPlayerID;
};

#endif

