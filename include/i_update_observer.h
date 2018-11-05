//
// Created by antonymo on 05.11.18.
//

#ifndef ACID_INCLUDE_I_UPDATE_OBSERVER_H_
#define ACID_INCLUDE_I_UPDATE_OBSERVER_H_


#include <i_observer.h>

template <class T>
class IUpdateObserver : IObserver<T> {
  public:
    virtual void on_update(T* sender) = 0;
};

#endif  // ACID_INCLUDE_I_UPDATE_OBSERVER_H_
