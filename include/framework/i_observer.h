#ifndef ACID_INCLUDE_I_OBSERVER_H_
#define ACID_INCLUDE_I_OBSERVER_H_

template <class T>
class IObservable;

template <class T>
class IObserver {
  public:
	virtual ~IObserver() {
		if (observable != nullptr) {
			observable->delete_observer(this);
		}
	};
	virtual void on_create(T* sender) {}
	virtual void on_delete(T* sender) { observable = nullptr; }
	virtual void on_update(T* sender) {}
  private:
	friend class IObservable<T>;
	IObservable<T>* observable = nullptr;
};

#endif  // ACID_INCLUDE_I_OBSERVER_H_