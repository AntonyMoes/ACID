#ifndef ACID_INCLUDE_I_OBSERVER_H_
#define ACID_INCLUDE_I_OBSERVER_H_


class IObserver {
  public:
	IObserver();
	virtual ~IObserver();
	virtual void update() = 0;
};

#endif  // ACID_INCLUDE_I_OBSERVER_H_