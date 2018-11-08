#ifndef ACID_INCLUDE_ACTIVE_SYSTEM_H_
#define ACID_INCLUDE_ACTIVE_SYSTEM_H_


#include <vector>

#include <i_system.h>

template <class T>
class ActiveSystem : public virtual ISystem<T> {
  public:
    virtual ~ActiveSystem() = default;
    void on_create(T* node) final;
    void on_delete(T* node) final;
    void run() final;
    void execute() const override = 0;

  protected:
    std::vector<T*> active_nodes; //TODO make as heap
};

#endif  // ACID_INCLUDE_ACTIVE_SYSTEM_H_
