#ifndef CLIPLAYER_HPP
#define CLIPLAYER_HPP

#include "engine/Player.hpp"

class CLIPlayer : public Player
{
 public:
  CLIPlayer(const std::string& name);

  virtual void update(const GameData& data) override;
  virtual InputData getInput(InputData::NeedInputType type) const override;
};

#endif

