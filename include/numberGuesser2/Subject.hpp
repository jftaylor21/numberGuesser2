#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include "Observer.hpp"

#include <list>
#include <memory>

typedef std::shared_ptr<Observer> ObserverP;

class Subject
{
 public:
  ~Subject();

  void notify();

  void attach(ObserverP o);
  void detach(ObserverP o);

 private:
  typedef std::list<ObserverP> ObserverList;

  ObserverList mObservers;
};

#endif

