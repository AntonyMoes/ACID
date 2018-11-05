#ifndef ACID_INCLUDE_I_OBSERVER_H_
#define ACID_INCLUDE_I_OBSERVER_H_

template <class T>
class IObserver {
  public:
	IObserver();
	virtual ~IObserver();
	virtual void on_delete(T* sender) = 0;

  private:
	T* observable;
};

template <class T>
class IUpdateObserver: IObserver
{
  public:
	virtual void on_update(T* sender) = 0;
};

#endif  // ACID_INCLUDE_I_OBSERVER_H_