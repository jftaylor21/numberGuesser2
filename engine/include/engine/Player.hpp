#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameData.hpp"
#include "InputData.hpp"

#include <string>

class Player
{
 public:
  Player(const std::string& name);

  virtual void update(const GameData& data) = 0;
  virtual InputData getInput(InputData::NeedInputType type) const = 0;

  const std::string& name() const;

 private:
  std::string mName;
};

#endif

