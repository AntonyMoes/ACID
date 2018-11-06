#ifndef ACID_INCLUDE_I_NODE_H_
#define ACID_INCLUDE_I_NODE_H_


#include <map>

#include <i_component.h>
#include <i_observable.h>
#include <i_update_observer.h>

template <class T>
class INode : public IObservable<T>, IUpdateObserver<IComponent> {
  public:
    INode();
    void initialize_components(const std::map<size_t, IComponent>& comps);  // TODO(AntonyMoes, ukhachev): устроить дальнейшую ревизию +
                                                                            // хендлинг невозможности построиться
  protected:
    template <class C>
    void add_component();
    std::map<size_t, IComponent*> components;
};

#endif  // ACID_INCLUDE_I_NODE_H_
