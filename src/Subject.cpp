#include "numberGuesser2/Subject.hpp"

Subject::~Subject()
{
  mObservers.clear();
}

void Subject::notify()
{
  ObserverList::iterator it(mObservers.begin());
  for(; it != mObservers.end(); ++it)
  {
    (*it)->update();
  }
}

void Subject::attach(ObserverP o)
{
  if (nullptr != o)
  {
    mObservers.push_back(o);
  }
}

void Subject::detach(ObserverP o)
{
  mObservers.remove(o);
}

