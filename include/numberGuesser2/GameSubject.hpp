#ifndef GAMESUBJECT_HPP
#define GAMESUBJECT_HPP

#include "Observer.hpp"

#include <map>
#include <memory>

typedef std::shared_ptr<Observer> ObserverP;

class GameSubject
{
 public:
  GameSubject();
  ~GameSubject();

  void notify(size_t id);

  size_t attach(ObserverP o);
  void detach(size_t id);

 private:
  // we use map[size_t] instead of vector so that ids remain the
  // same when players drop out
  // We will always assign the next larger ID to new players. There is a
  // potential of running out of IDs. If this happens, we will not allow
  // any new players to attach
  typedef std::map<size_t, ObserverP> ObserverMap;

  ObserverMap mObservers;
  size_t mNextID;
};

#endif

