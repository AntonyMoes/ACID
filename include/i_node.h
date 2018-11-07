#ifndef ACID_INCLUDE_I_NODE_H_
#define ACID_INCLUDE_I_NODE_H_


#include <map>

#include <i_component.h>
#include <i_observable.h>
#include <i_observer.h>

template <class T>
class INode : public IObservable<T>, IObserver<IComponent> {
  public:
    INode();
    void initialize_components(const std::map<size_t, IComponent>& comps);  // TODO(AntonyMoes, ukhachev): further re-check this implementation +
                                                                            // handle unabling to initialize
    void on_update() final;
    void on_delete() final;
  protected:
    template <class C>
    void add_component();
    std::map<size_t, IComponent*> components;
};

#endif  // ACID_INCLUDE_I_NODE_H_
