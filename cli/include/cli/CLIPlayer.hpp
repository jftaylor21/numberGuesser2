#ifndef CLIPLAYER_HPP
#define CLIPLAYER_HPP

#include "engine/Player.hpp"

namespace cli
{
  class CLIPlayer : public engine::Player
  {
   public:
    CLIPlayer(const std::string& name);
  
    virtual void update(const engine::GameData& data) override;
    virtual engine::InputData getInput(engine::InputData::NeedInputType type) const override;
  };
}

#endif

