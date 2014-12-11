#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "GameData.hpp"
#include "InputData.hpp"

#include <string>

class Player
{
 public:
  Player(const std::string& name);

  void update(const GameData& data);
  InputData getInput(InputData::NeedInputType type) const;

  const std::string& name() const;

 private:
  std::string mName;
};

#endif

