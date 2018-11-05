#ifndef ACID_INCLUDE_I_OBSERVABLE_H_
#define ACID_INCLUDE_I_OBSERVABLE_H_


#include <vector>
#include <i_observer.h>

class IObservable {
	std::vector<IObserver*> observers;
 public:
	IObservable();
	virtual ~IObservable();
	virtual void update() = 0;
	void add_observer(IObserver* observer);
};

#endif  // ACID_INCLUDE_I_OBSERVABLE_H_
