#ifndef GAMEDATA_HPP
#define GAMEDATA_HPP

#include "InputData.hpp"

#include <cstdint>
#include <cstring>
#include <string>

struct GameData
{
  typedef size_t PlayerID;
  typedef std::list<InputData::Guess> GuessList;

  enum LastGuessType
  {
    LAST_GUESS_HIGH,
    LAST_GUESS_LOW,
    LAST_GUESS_CORRECT,
    LAST_GUESS_INVALID
  };

  GameData() : lastGuess(LAST_GUESS_INVALID) {}

  std::string currentPlayer;
  GuessList guesses;
  LastGuessType lastGuess;
};

#endif

