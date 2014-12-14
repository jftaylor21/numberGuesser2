#include "engine/Player.hpp"

namespace engine
{
  Player::Player(const std::string& name)
    : mName(name)
  {
  }
  
  const std::string& Player::name() const
  {
    return mName;
  }
}

