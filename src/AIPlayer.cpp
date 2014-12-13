#include "numberGuesser2/AIPlayer.hpp"

namespace
{
  InputData::Guess getRandomGuess()
  {
    InputData::Guess ret(rand());
    bool positive(rand()%2);
    return positive ? ret : -ret;
  }

  std::string sBasename("AI ");
  size_t sNumber(0);
}

AIPlayer::AIPlayer()
  : Player(sBasename+std::to_string(sNumber))
{
  ++sNumber;
}

void AIPlayer::update(const GameData&)
{
}

InputData AIPlayer::getInput(InputData::NeedInputType type) const
{
  InputData::Guess g;
  switch(type)
  {
   case InputData::NEED_NEW_SECRET_NUMBER:
    g = getRandomGuess();
    break;
   case InputData::NEED_GUESS:
    g = getRandomGuess();
    break;
  }

  InputData ret(g);
  return ret;
}

