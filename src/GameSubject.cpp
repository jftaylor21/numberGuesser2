#include "numberGuesser2/GameSubject.hpp"

GameSubject::GameSubject()
  : mNextID(0)
{
}

GameSubject::~GameSubject()
{
  mObservers.clear();
}

void GameSubject::notify(size_t id)
{
  if (mObservers.count(id))
  {
    mObservers[id]->update();
  }
}

size_t GameSubject::attach(ObserverP o)
{
  size_t ret = SIZE_MAX;
  if (nullptr != o && SIZE_MAX != mNextID)
  {
    mObservers[mNextID] = o;
    ret = mNextID;
    ++mNextID;
  }
  return ret;
}

void GameSubject::detach(size_t id)
{
  mObservers.erase(id);
}

