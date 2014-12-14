#include "numberGuesser2/AIPlayer.hpp"

#include <cstdlib>
#include <sstream>
#include <string>

namespace
{
  // workaround for mingw not supporting std::to_string
  // https://gcc.gnu.org/bugzilla/show_bug.cgi?id=52015
  std::string to_string(size_t number)
  {
    std::ostringstream ss;
    ss << number;
    return ss.str();
  }
  
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
  : Player(sBasename+to_string(sNumber))
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

