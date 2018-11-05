#ifndef ACID_INCLUDE_PROXY_SINGLETONE_OBSERVER_H_
#define ACID_INCLUDE_PROXY_SINGLETONE_OBSERVER_H_


#include "i_singletone.h"
#include "i_observer.h"

template <class T>
class ProxySingletoneObserver : public ISingletone, IObserver<T>{
  public:
    virtual ~ProxySingletoneObserver();

  private:
    IObserver<T>* observer;
};

#endif  // ACID_INCLUDE_PROXY_SINGLETONE_OBSERVER_H_
