#ifndef ACID_INCLUDE_I_OBSERVER_H_
#define ACID_INCLUDE_I_OBSERVER_H_

template <class T>
class IObserver {
  public:
	virtual ~IObserver() = default;
	virtual void on_delete(T* sender) = 0;
};

#endif  // ACID_INCLUDE_I_OBSERVER_H_