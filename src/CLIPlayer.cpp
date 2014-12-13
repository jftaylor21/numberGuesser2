#include "numberGuesser2/CLIPlayer.hpp"

#include <iostream>

CLIPlayer::CLIPlayer(const std::string& name)
  : Player(name)
{
}

void CLIPlayer::update(const GameData& data)
{
  std::cout << std::endl;
  std::cout << "Guess Number: " << data.guesses.size() << std::endl;
  if (GameData::LAST_GUESS_INVALID != data.lastGuess)
  {
    std::cout << "Previous guesses were: ";
    GameData::GuessList::const_iterator it(data.guesses.begin());
    for(; it != data.guesses.end(); ++it)
    {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Previous guess was: ";
    switch (data.lastGuess)
    {
     case GameData::LAST_GUESS_LOW:
      std::cout << "LOW";
      break;
     case GameData::LAST_GUESS_HIGH:
      std::cout << "HIGH";
      break;
     case GameData::LAST_GUESS_CORRECT:
      std::cout << "CORRECT";
      break;
     case GameData::LAST_GUESS_INVALID:
      // not possible
      break;
    }
    std::cout << std::endl;
  }
  if (GameData::LAST_GUESS_CORRECT == data.lastGuess)
  {
    std::cout << "Winner: " << data.currentPlayer << std::endl;
  }
  else
  {
    std::cout << "Current player: " << data.currentPlayer << std::endl;
  }
  std::cout << std::endl;
}

InputData CLIPlayer::getInput(InputData::NeedInputType type) const
{
  std::cout << name() << ", ";
  switch(type)
  {
   case InputData::NEED_NEW_SECRET_NUMBER:
    std::cout << "please enter a secret number for other players to guess...";
    break;
   case InputData::NEED_GUESS:
    std::cout << "please guess a number...";
    break;
  }

  InputData::Guess g;
  std::cin >> g;
  InputData ret(g);
  return ret;
}

