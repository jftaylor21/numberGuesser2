#ifndef AIPLAYER_HPP
#define AIPLAYER_HPP

#include "engine/Player.hpp"

class AIPlayer : public Player
{
 public:
  AIPlayer();

  virtual void update(const GameData& data) override;
  virtual InputData getInput(InputData::NeedInputType type) const override;
};

#endif

