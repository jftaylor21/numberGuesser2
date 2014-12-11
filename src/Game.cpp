#include "numberGuesser2/Game.hpp"

Game::Game()
  : mNextID(0),
    mSecretNumber(0),
    mOriginatorID(SIZE_MAX),
    mCurrentPlayerID(SIZE_MAX)
{
}

GameData::PlayerID Game::attach(PlayerP player)
{
  GameData::PlayerID ret(SIZE_MAX);
  if (nullptr != player && SIZE_MAX != mNextID)
  {
    mPlayers[mNextID] = player;
    ret = mNextID;
    ++mNextID;
  }
  return ret;
}

void Game::detach(GameData::PlayerID player)
{
  mPlayers.erase(player);
}

bool Game::nextTurn()
{
  bool ret(true);

  // find next player
  GameData::PlayerID nextPlayer(getNextPlayer(mCurrentPlayerID));

  if (SIZE_MAX != nextPlayer)
  {
    // update current player
    mCurrentPlayerID = nextPlayer;
    mGameData.currentPlayer = mPlayers[mCurrentPlayerID]->name();

    // send updates to everyone
    PlayerMap::iterator it2(mPlayers.begin());
    for(; it2 != mPlayers.end(); ++it2)
    {
      it2->second->update(mGameData);
    }

    // get input from current player
    InputData input(mPlayers[mCurrentPlayerID]->getInput(InputData::NEED_GUESS));

    // determine if guess is correct
    if (input.guess < mSecretNumber)
    {
      ret = false;
      mGameData.lastGuess = GameData::LAST_GUESS_LOW;
    }
    else if (input.guess > mSecretNumber)
    {
      ret = false;
      mGameData.lastGuess = GameData::LAST_GUESS_HIGH;
    }
    else
    {
      mGameData.lastGuess = GameData::LAST_GUESS_CORRECT;
    }
    mGameData.guesses.push_back(input.guess);
  }
  return ret;
}

void Game::newGame(GameData::PlayerID originatorID)
{
  if (mPlayers.count(originatorID))
  {
    mGameData = GameData();
    mOriginatorID = originatorID;
    mCurrentPlayerID = originatorID;
    InputData input(mPlayers[originatorID]->getInput(InputData::NEED_NEW_SECRET_NUMBER));
    mSecretNumber = input.guess;
  }
}

Game::PlayerMap::const_iterator Game::incrementIterator(PlayerMap::const_iterator it) const
{
    if (it == mPlayers.end() || ++it == mPlayers.end())
    {
      it = mPlayers.begin();
    }
    return it;
}

GameData::PlayerID Game::getNextPlayer(GameData::PlayerID currentPlayer) const
{
  GameData::PlayerID ret(SIZE_MAX);
  if (mPlayers.size() > 1)
  {
    PlayerMap::const_iterator it(mPlayers.find(currentPlayer));
    it = incrementIterator(it);
    if (it->first == mOriginatorID)
    {
      it = incrementIterator(it);
    }
    ret = it->first;
  }
  return ret;
}

