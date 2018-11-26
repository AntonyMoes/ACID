#ifndef ACID_INCLUDE_I_OBSERVABLE_H_
#define ACID_INCLUDE_I_OBSERVABLE_H_

#include <list>
#include <iostream>
#include <set>

#include <i_observer.h>

template <class T>
class IObservable {
  public:
	~IObservable() {
	    for (auto observer : observers) {
            observer->on_delete(reinterpret_cast<T*>(this));
	    }
	}

	void add_observer(IObserver<T>* observer) {
		observers.insert(observer);
		observer->observable = this;
	}
	void delete_observer(IObserver<T>* observer) {
		auto observer_iter = observers.find(observer);
		if (observer_iter != observers.end()) {
		    observers.erase(observer);
		}
	}

  protected:
    std::set<IObserver<T>*> observers;
};

#endif  // ACID_INCLUDE_I_OBSERVABLE_H_
