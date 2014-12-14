#ifndef INPUTDATA_HPP
#define INPUTDATA_HPP

#include <list>

namespace engine
{
  struct InputData
  {
    typedef int Guess;
  
    enum NeedInputType
    {
      NEED_NEW_SECRET_NUMBER,
      NEED_GUESS
    };
  
    InputData(Guess g) : guess(g) {}
  
    Guess guess;
  };
}

#endif

