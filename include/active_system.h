#ifndef ACID_INCLUDE_ACTIVE_SYSTEM_H_
#define ACID_INCLUDE_ACTIVE_SYSTEM_H_


#include <i_system.h>
#include <vector>

template <class T>
class ActiveSystem : public virtual ISystem<T> {
  public:
    virtual ~ActiveSystem();
    void on_create(T* node) final;
    void on_delete(T* node) final;
  protected:
    std::vector<T*> active_nodes; //TODO make as heap
};

#endif  // ACID_INCLUDE_ACTIVE_SYSTEM_H_
